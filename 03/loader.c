#include "loader.h"


uint64_t load(const char* path)
{
    /* open elf */
    FILE* input_file = fopen(path, "rb");
    if (!input_file)
    {
        /* failed to open file */
        printf("Error opening file\n");
        fclose(input_file);
        return 0;
    }

    /* check magic number to tell whether it is 32-bit or 64-bit */
    unsigned char elf_magic[EI_NIDENT];
    fread((void *)elf_magic, sizeof(unsigned char) * EI_NIDENT, 1, input_file);
    /* sanity checks */
#ifdef DEBUG
    int local_iter = 0;
    for (local_iter = 0; local_iter < EI_NIDENT; local_iter++)
    {
        printf("%x ", elf_magic[local_iter]);
    }
    printf("\n");
#endif
    if (elf_magic[EI_MAG0] == 0x7f &&
        elf_magic[EI_MAG1] == 0x45 &&
        elf_magic[EI_MAG2] == 0x4c &&
        elf_magic[EI_MAG3] == 0x46)
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
    printf("Error loading ELF\n");
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
        printf("Invalid ELF, exiting\n");
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
#ifdef DEBUG
    printf("Loading %d segments\n", loadtable64_num);
#endif
    loadtable64 = (Load_table64*) malloc(sizeof(Load_table64) * loadtable64_num);
    /* read program headers and load ELF */
    int loadtable64_idx = 0;
    heap_start = elf_header.e_entry;
    for (i = 0; i < elf_header.e_phnum; i++)
    {
        if (program_headers[i].p_type != PT_LOAD)
        {
            /* not a loadable segment, pass */
            continue;
        }
        fseek(input_file, program_headers[i].p_offset, SEEK_SET);
        loadtable64[loadtable64_idx].orig_addr = program_headers[i].p_vaddr;
        loadtable64[loadtable64_idx].sz = program_headers[i].p_memsz; /* use memsz since sections like .bss occupies no space in file but the memory must be reserved when loading */
        loadtable64[loadtable64_idx].start_ptr = (uint8_t*) malloc((size_t)program_headers[i].p_memsz); /* we use memsz to allocate memory */
        /* read file into memory. we use filesz here */
        fread(loadtable64[loadtable64_idx].start_ptr, 1, (size_t)program_headers[i].p_filesz, input_file);
#ifdef DEBUG
        printf("Segment loaded at virtual 0x%llx, host 0x%llx, filesize 0x%llx, memorysize 0x%llx\n",
                loadtable64[loadtable64_idx].orig_addr,
                loadtable64[loadtable64_idx].start_ptr,
                program_headers[i].p_filesz,
                program_headers[i].p_memsz);
#endif
        heap_start += program_headers[i].p_filesz;
        loadtable64_idx += 1;
    }
#ifdef DEBUG
    printf("%d segments successfully loaded\n", loadtable64_idx);
#endif

    /* Load Stack */
    mystack.sz = StackSize;
    mystack.stack_pointer = StackPointerPos;
    mystack.start_ptr = (uint8_t*)malloc((size_t)StackSize);
#ifdef DEBUG
        printf("Stack loaded at host 0x%llx, stack pointer 0x%llx, stacksize 0x%llx\n",
                mystack.start_ptr,
                mystack.stack_pointer,
                mystack.sz);
        printf("Stack successfully loaded!\n");
#endif

    /* Initialize Heap */
    myheap.sz = HeapSize;
    myheap.heap_begin = heap_start;
    myheap.heap_end = myheap.heap_begin + myheap.sz;
    myheap.start_ptr = (uint8_t*)malloc((size_t)myheap.sz);
#ifdef DEBUG
        printf("Heap loaded at host 0x%llx, Heap begin: 0x%llx, Heap end: 0x%llx, Heap size: 0x%llx\n",
                myheap.start_ptr,
                myheap.heap_begin,
                myheap.heap_end,
                myheap.sz);
        printf("Heap successfully loaded!\n");
#endif
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
    Elf32_Ehdr elf_header32;
    fread(&elf_header32, sizeof(Elf32_Ehdr), 1, input_file);
 
    /* sanity check */
    if (elf_header32.e_type != ET_EXEC)
    {
        printf("Invalid ELF file, exiting\n");
        fclose(input_file);
        return 0;
    }

    /* read program header */
    fseek(input_file, (long int)elf_header32.e_phoff, SEEK_SET);
    Elf32_Phdr* program_headers = (Elf32_Phdr*) malloc((size_t)(elf_header32.e_phentsize * elf_header32.e_phnum));
    fread(program_headers, (size_t)(elf_header32.e_phentsize), (size_t)(elf_header32.e_phnum), input_file);
    
    /* allocate memory for ELF segments */
    int i;
    loadtable32_num = 0;
    /* check how many segments are loadable */
    for (i = 0; i < elf_header32.e_phnum; i++)
    {
        if (program_headers[i].p_type == PT_LOAD)
        {
            loadtable32_num += 1;
        }
    }
    loadtable32 = (Load_table32*) malloc(sizeof(Load_table32) * loadtable32_num);
    /* read program headers and load ELF */
    int loadtable32_idx = 0;
    for (i = 0; i < elf_header32.e_phnum; i++)
    {
        if (program_headers[i].p_type != PT_LOAD)
        {
            /* not a loadable segment, pass */
            continue;
        }
        loadtable32[loadtable32_idx].orig_addr = program_headers[i].p_vaddr;
        loadtable32[loadtable32_idx].sz = program_headers[i].p_memsz; /* use memsz since sections like .bss occupies no space in file but the memory must be reserved when loading */
        loadtable32[loadtable32_idx].start_ptr = (uint8_t*) malloc((size_t)program_headers[i].p_memsz);
        /* read file into memory */
        fread(loadtable32[loadtable32_idx].start_ptr, 1, (size_t)program_headers[i].p_memsz, input_file);
        loadtable32_idx += 1;
    }
    
    /* do cleaning up */
    free(program_headers);
    fclose(input_file);
    return elf_header32.e_entry;
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
#ifdef DEBUG
    //printf("virtual address: %llx\n", addr);
#endif
    int i;
    uint8_t* result;
    /* we don't handle situations where segments overlap */
    for (i = 0; i < loadtable64_num; i++)
    {
        if ((addr < (loadtable64[i].orig_addr + loadtable64[i].sz)) &&
            (addr >= loadtable64[i].orig_addr))
        {
            result = loadtable64[i].start_ptr + (addr - loadtable64[i].orig_addr);
            //printf("virtual address in segment\n");
            return (void*) result;
        }
    }
    if((addr > mystack.stack_pointer - mystack.sz) && (addr <= mystack.stack_pointer)){
        result = mystack.start_ptr + (mystack.stack_pointer - addr);
        //printf("virtual address in stack\n");
        return (void*) result;
    }
    if(addr >= myheap.heap_begin && addr < myheap.heap_end){
        result = myheap.start_ptr + (addr - myheap.heap_begin);
        //printf("virtual address in heap\n");
        return (void*) result;
    }
    printf("Invalid virtual memory address: 0x%llx\n",addr);
    return NULL;
}

void* getptr32(uint32_t addr)
{
    int i;
    for (i = 0; i < loadtable32_num; i++)
    {
        if ((addr < (loadtable32[i].orig_addr + loadtable32[i].sz)) &&
            (addr >= loadtable32[i].orig_addr))
        {
            uint8_t* result = loadtable32[i].start_ptr + (addr - loadtable32[i].orig_addr);
            return (void*) result;
        }
    }
    printf("Invalid virtual memory address\n");
    return NULL;
}

