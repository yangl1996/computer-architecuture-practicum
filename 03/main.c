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
    for(int i = 0;i < 32;i++){
        Reg[i] = 0;
        f_Reg[i] = 0;
        d_Reg[i] = 0;
    }
    Exit_flag = 0;
    Reg[2] = 0x100000; //initialize stack pointer sp
#ifdef DEBUG
    printf("Program entry point at virtual %llx\n", Rpc);
#endif
    verbose = 0;
    int cnt = 0;
    while (1)
    {
        pc = getptr64(Rpc);
        decode();
        cnt++;
        if(Exit_flag == 1)
            break;
    }
    //printf("instruction number: %d\n",cnt);
    cleanup64();
#ifdef DEBUG
    printf("exit successfully!\n");
#endif
}
