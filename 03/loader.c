#include "loader.h"

int loadtable64_num;
Load_table64* loadtable64;
int loadtable32_num;
Load_table32* loadtable32;

uint64_t load(const char* path)
{
    /* open elf */
    FILE* input_file = fopen(path, "rb");
    if (!input_file)
    {
        /* failed to open file */
        fclose(input_file);
        return 0;
    }

    /* check magic number to tell whether it is 32-bit or 64-bit */
    unsigned char elf_magic[EI_NIDENT];
    fread((void *)elf_magic, sizeof(unsigned char) * EI_NIDENT, 1, input_file);
    /* sanity checks */
    if (elf_magic[EI_MAG0] == ELFMAG0 &&
        elf_magic[EI_MAG1] == ELFMAG1 &&
        elf_magic[EI_MAG2] == ELFMAG2 &&
        elf_magic[EI_MAG3] == ELFMAG3 &&
        elf_magic[EI_DATA] == ELFDATA2LSB &&
        elf_magic[EI_OSABI] == ELFOSABI_LINUX)
    {
        /* check elf bit depth */
        if (elf_magic[EI_CLASS] == ELFCLASS32)
        {
            return (uint64_t)load32(input_file);
        }
        else if (elf_magic[EI_CLASS] == ELFCLASS64)
        {
            return load64(input_file);
        }
    }
    fclose(input_file);
    return 0;
}

uint64_t load64(FILE* input_file)
{
    /* read elf header */
    rewind(input_file);
    Elf64_Ehdr elf_header;
    fread(&elf_header, sizeof(Elf64_Ehdr), 1, input_file);
 
    /* sanity check */
    if (elf_header.e_type != ET_EXEC)
    {
        fclose(input_file);
        return 0;
    }

    /* read program header */
    fseek(input_file, (long int)elf_header.e_phoff, SEEK_SET);
    Elf64_Phdr* program_headers = (Elf64_Phdr*) malloc((size_t)(elf_header.e_phentsize * elf_header.e_phnum));
    fread(program_headers, (size_t)(elf_header.e_phentsize), (size_t)(elf_header.e_phnum), input_file);
    
    /* allocate memory for ELF segments */
    int i;
    loadtable64_num = 0;
    /* check how many segments are loadable */
    for (i = 0; i < elf_header.e_phnum; i++)
    {
        if (program_headers[i].p_type == PT_LOAD)
        {
            loadtable64_num += 1;
        }
    }
    loadtable64 = (Load_table64*) malloc(sizeof(Load_table64) * loadtable64_num);
    /* read program headers and load ELF */
    int loadtable64_idx = 0;
    for (i = 0; i < elf_header.e_phnum; i++)
    {
        if (program_headers[i].p_type != PT_LOAD)
        {
            /* not a loadable segment, pass */
            continue;
        }
        loadtable64[loadtable64_idx].orig_addr = program_headers[i].p_vaddr;
        loadtable64[loadtable64_idx].size = program_headers[i].p_memsz; /* use memsz since sections like .bss occupies no space in file but the memory must be reserved when loading */
        loadtable64[loadtable64_idx].start_ptr = (uint8_t*) malloc((size_t)program_headers[i].p_memsz);
        /* read file into memory */
        fread(loadtable64[loadtable64_idx].start_ptr, 1, (size_t)program_headers[i].p_memsz, input_file);
        loadtable64_idx += 1;
    }
    
    /* do cleaning up */
    free(program_headers);
    fclose(input_file);
    return elf_header.e_entry;
}

int cleanup64()
{
    int i;
    /* free segments */
    for (i = 0; i < loadtable64_num; i++)
    {
        free(loadtable64[i].start_ptr);
    }
    /* free load table */
    free(loadtable64);
    return 1;
}

uint32_t load32(FILE* input_file)
{
    /* read elf header */
    rewind(input_file);
    Elf32_Ehdr elf_header;
    fread(&elf_header, sizeof(Elf32_Ehdr), 1, input_file);
 
    /* sanity check */
    if (elf_header.e_type != ET_EXEC)
    {
        fclose(input_file);
        return 0;
    }

    /* read program header */
    fseek(input_file, (long int)elf_header.e_phoff, SEEK_SET);
    Elf32_Phdr* program_headers = (Elf32_Phdr*) malloc((size_t)(elf_header.e_phentsize * elf_header.e_phnum));
    fread(program_headers, (size_t)(elf_header.e_phentsize), (size_t)(elf_header.e_phnum), input_file);
    
    /* allocate memory for ELF segments */
    int i;
    loadtable32_num = 0;
    /* check how many segments are loadable */
    for (i = 0; i < elf_header.e_phnum; i++)
    {
        if (program_headers[i].p_type == PT_LOAD)
        {
            loadtable32_num += 1;
        }
    }
    loadtable32 = (Load_table32*) malloc(sizeof(Load_table32) * loadtable32_num);
    /* read program headers and load ELF */
    int loadtable32_idx = 0;
    for (i = 0; i < elf_header.e_phnum; i++)
    {
        if (program_headers[i].p_type != PT_LOAD)
        {
            /* not a loadable segment, pass */
            continue;
        }
        loadtable32[loadtable32_idx].orig_addr = program_headers[i].p_vaddr;
        loadtable32[loadtable32_idx].size = program_headers[i].p_memsz; /* use memsz since sections like .bss occupies no space in file but the memory must be reserved when loading */
        loadtable32[loadtable32_idx].start_ptr = (uint8_t*) malloc((size_t)program_headers[i].p_memsz);
        /* read file into memory */
        fread(loadtable32[loadtable32_idx].start_ptr, 1, (size_t)program_headers[i].p_memsz, input_file);
        loadtable32_idx += 1;
    }
    
    /* do cleaning up */
    free(program_headers);
    fclose(input_file);
    return elf_header.e_entry;
}

int cleanup32()
{
    int i;
    /* free segments */
    for (i = 0; i < loadtable32_num; i++)
    {
        free(loadtable32[i].start_ptr);
    }
    /* free load table */
    free(loadtable32);
    return 1;
}

void* getptr64(uint64_t addr)
{
    int i;
    /* we don't handle situations where segments overlap */
    for (i = 0; i < loadtable64_num; i++)
    {
        if ((addr < (loadtable64[i].orig_addr + loadtable64[i].size)) &&
            (addr >= loadtable64[i].orig_addr))
        {
            uint8_t* result = loadtable64[i].start_ptr + (addr - loadtable64[i].orig_addr);
            return (void*) result;
        }
    }
    return NULL;
}

void* getptr32(uint32_t addr)
{
    int i;
    for (i = 0; i < loadtable32_num; i++)
    {
        if ((addr < (loadtable32[i].orig_addr + loadtable32[i].size)) &&
            (addr >= loadtable32[i].orig_addr))
        {
            uint8_t* result = loadtable32[i].start_ptr + (addr - loadtable32[i].orig_addr);
            return (void*) result;
        }
    }
    return NULL;
}

