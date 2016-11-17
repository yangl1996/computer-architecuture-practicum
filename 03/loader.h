#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define StackSize 0x5000
#define StackPointerPos 0x0000000042dcdb50
/*
 * Load an ELF file
 *
 * path: pointer to a string specifying the path of file to load
 *
 * Return value: entry point address for success, 0 for failed.
 */
uint64_t load(const char* path);

/*
 * Load an N-bit ELF, these functions should be invoked by load()
 *
 * input_file: pointer to a file object containing the ELF file
 *
 * Return value: entry point address for success, 0 for failed
 */
uint32_t load32(FILE* input_file);
uint64_t load64(FILE* input_file);

/*
 * Convert an address in ELF to acutal address
 *
 * addr: address to convert
 *
 * Return value: a void* pointing to the actual address, or NULL if error
 */

void* getptr32(uint32_t addr);
void* getptr64(uint64_t addr);

/*
 * Clean up spaces occupied by load table and ELF
 *
 * Return value: 1 for success (currently will only return 1)
 */
int cleanup32();
int cleanup64();

typedef struct
{
    uint8_t* start_ptr; /* pointer to the start of segment in host memory */
    Elf64_Addr orig_addr; /* address of the start of segment in ELF */
    uint64_t sz;      /* size of the segment in host memory */
} Load_table64;

typedef struct
{
    uint8_t* start_ptr; /* pointer to the start of segment in host memory */
    Elf32_Addr orig_addr; /* address of the start of segment in ELF */
    uint32_t sz;      /* size of the segment in host memory */
} Load_table32;

typedef struct
{
    uint8_t* start_ptr; /* pointer to the start of Stack in host memory */
    Elf64_Addr stack_pointer; /* address of the pointer of Stack in virtual memory */
    uint64_t sz;      /* size of the Stack in host memory */
} Stack;