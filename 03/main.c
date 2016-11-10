#include "decoder.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./riscvemu <executable>\n");
        return 0;
    }
    uint64_t entry_point_vtul = load(argv[1]);
#ifdef DEBUG
    printf("Program entry point at %llx\n", entry_point_vtul);
#endif
    pc = getptr64(entry_point_vtul);
    while (1)
    {
        decode();
    }
    cleanup64();
}
