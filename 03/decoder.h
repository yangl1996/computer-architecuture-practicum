#include <stdio.h>
#include "loader.h"

/* Opcode for different instructions */
#define R_op 0x33
#define I_op 0x13
#define Branch_op 0x63
#define Load_op 0x3
#define Store_op 0x23
#define JAL_op 0x6f
#define JALR_op 0x67
#define AUIPC_op 0x17
#define LUI_op 0x37
#define W_R_op 0x3b
#define W_I_op 0x1b

/* Mask to get different parts of instructions */
#define Mask_op 0x7f
#define Mask_Reg 0x1f
#define Mask_func3 0x7
#define Mask_func7 0x7f
#define MASK_High32 0xffffffff00000000
#define MASK_Low32 0xffffffff

int* pc; //PC Register
long long Reg[32]; //Register File
long long imm;  //immediate number
int inst, opcode, rd, rs1, rs2, func3,func7; //different parts of instruction

/* Decode Instructions */
void decode();


/* 
*  Execute R_type Instructions
*  Including: ADD, SUB, SLL, SLT, SLTU, XOR,
*  SRL, SRA, OR, AND
*/
void R_type();


/* 
*  Execute I_type Instructions
*  Including: ADDI, SLLI, SLTI, SLTIU, XORI,
*  SRLI, SRAI, ORI, ANDI
*/
void I_type();


/* 
*  Execute Branch_type Instructions
*  Including: BEQ, BNE, BLT, BGE, BLEU, BGEU
*/
void Branch_type();


/* 
*  Execute Load_type Instructions
*  Including: LB, LH, LW, LD, LBU, LHU, LWU
*/
void Load_type();


/* 
*  Execute Store_type Instructions
*  Including: SB, SH, SW, SD
*/
void Store_type();


/* Execute JAL Instructions */
void JAL();


/* Execute JALR Instructions */
void JALR();


/* Execute AUIPC Instructions */
void AUIPC();


/* 
*  Execute W_R_type Instructions
*  Including: ADDW, SUBW, SLLW, SRLW, SRAW
*/
void W_R_type();


/* 
*  Execute W_I_type Instructions
*  Including: ADDIW, SLLIW, SRLIW, SRAIW
*/
void W_I_type();
