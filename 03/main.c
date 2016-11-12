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
    Rpc = load(argv[1]);
    unsigned long long entry = Rpc;
#ifdef DEBUG
    printf("Program entry point at virtual %llx\n", Rpc);
#endif
    while (1)
    {
        pc = getptr64(Rpc);
        decode();
    }
    cleanup64();
}
