#include <stdio.h>
#include <math.h>
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
#define F_Load_op 0x7
#define F_Store_op 0x27
#define F_op 0x53
#define FMADD_op 0x43
#define FMSUB_op 0x47
#define FNMSUB_op 0x4b
#define FNMADD_op 0x4f

/* Mask to get different parts of instructions */
#define Mask_op 0x7f
#define Mask_Reg 0x1f
#define Mask_func3 0x7
#define Mask_func7 0x7f
#define MASK_High32 0xffffffff00000000
#define MASK_Low32 0xffffffff
#define MASK_f31_0 0x7fffffff
#define MASK_f32 0x80000000
#define MASK_f63_0 0x7fffffffffffffff
#define MASK_f64 0x8000000000000000

unsigned long long Rpc;
int* pc; //pointer to actual instruction
/* Register File */
long long Reg[32]; 
float f_Reg[32];
double d_Reg[32];
long long imm;  //immediate number
int inst, opcode, rd, rs1, rs2, func3, func7, rm, fmt, func5, rs3; //different parts of instruction

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
*  Including: BEQ, BNE, BLT, BGE, BLTU, BGEU
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
/*
*  Execute Mul_Div_64_type Instructions
*  Including: MUL, MULH, MULHU, MULHSU, DIV, DIVU, REM, REMU 
*/
void Mul_Div_type();
/*
*  Execute Mul_Div_64_type Instructions
*  Including: MULW, DIVW, DIVUW, REMW, REMUW
*/
void Mul_Div_64_type();
/* rounding function */
float f_Rounding(float a);
double d_Rounding(double a);
/*
*  Execute F_load Instructions
*  Including: FLW, FLD
*/
void F_Load();
/*
*  Execute F_store Instructions
*  Including: FSW, FSD
*/
void F_Store();
/*
*  Execute F_type Instructions
*  Including: FSW, FSD
*/
void F_type();
/*
*  Execute FMADD Instructions
*  Including: FMADD.S, FMADD.D
*/
void FMADD();
/*
*  Execute FMSUB Instructions
*  Including: FMSUB.S, FMSUB.D
*/
void FMSUB();
/*
*  Execute FNMADD Instructions
*  Including: FNMADD.S, FNMADD.D
*/
void FNMADD();
/*
*  Execute FNMSUB Instructions
*  Including: FNMSUB.S, FNMSUB.D
*/
void FNMSUB();
