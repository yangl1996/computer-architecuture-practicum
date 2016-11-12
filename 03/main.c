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
    Reg[2] = 0x0000000042dcdb50; //initialize stack pointer sp
#ifdef DEBUG
    printf("Program entry point at virtual %llx\n", Rpc);
#endif
    Exit_flag  = 0;
    while (1)
    {
        pc = getptr64(Rpc);
        decode();
        if(Exit_flag == 1)
            break;
    }
    cleanup64();
}
