#include "decoder.h"
void decode(){
#ifdef DEBUG
    printf("Decoding instruction at %llx\n", pc);
#endif
	/* get instruction and convert to binary char */
	inst = *pc;
	/* get opcode in decimal int */
	opcode = inst & Mask_op;
	/* different cases for opcode*/
	switch(opcode){
		case R_op:{
			R_type();
			pc++;
			break;
		}
		case I_op:{
			I_type();
			pc++;
			break;
		}
		case Load_op:{
			Load_type();
			pc++;
			break;
		}
		case Store_op:{
			Store_type();
			pc++;
			break;
		}
		case Branch_op:{
			Branch_type();
			break;
		}
		case JAL_op:{
			JAL();
			break;
		}
		case JALR_op:{
			JALR();
			break;
		}
		case AUIPC_op:{
			AUIPC();
			break;
		}
		case LUI_op:{
			Reg[rd] = (inst >> 12) << 12;
			pc++;
			break;
		}
		case W_R_op:{
			W_R_type();
			pc++;
			break;
		}
		case W_I_op:{
			W_I_type();
			pc++;
			break;
		}
        default:{
            printf("Error decoding\n");
        }
	}
}
void R_type(){
	/* decode for R_type */
	rd = (inst >> 7) & Mask_Reg;
	func3 = (inst >> 12) & Mask_func3;
	rs1 = (inst >> 15) & Mask_Reg;
	rs2 = (inst >> 20) & Mask_Reg;
	func7 = (inst >> 25) & Mask_func7;
	int shift = Reg[rs2] & 0x3f;
	switch(func3){
		/* ADD and SUB */
		case 0:{
			if(func7 == 0)
				Reg[rd] = Reg[rs1] + Reg[rs2];
			else
				Reg[rd] = Reg[rs1] - Reg[rs2];
			break;
		}
		/* SLL */
		case 1:{
			Reg[rd] = Reg[rs1] << shift;
			break;
		}
		/* SLT */
		case 2:{
			if(Reg[rs1] < Reg[rs2])
				Reg[rd] = 1;
			else
				Reg[rd] = 0;
			break;
		}
		/* SLTU */
		case 3:{
			/* special case if rs1 = x0 */
			if(rs1 == 0 && Reg[rs2] != 0)
				Reg[rd] = 1;
			else if (rs1 == 0 && Reg[rs2] == 0)
				Reg[rd] = 0;
			else if((unsigned long long)Reg[rs1] < (unsigned long long)Reg[rs2])
				Reg[rd] = 1;
			else
				Reg[rd] = 0;
			break;
		}
		/* XOR */
		case 4:{
			Reg[rd] = Reg[rs1] ^ Reg[rs2];
			break;
		}
		/* SRL and SRA */
		case 5:{
			if(func7 != 0)
				Reg[rd] = Reg[rs1] >> shift; // SRA 
			else
				Reg[rd] = (unsigned long long)Reg[rs1] >> shift;
			break;
		}
		/* OR */
		case 6:{
			Reg[rd] = Reg[rs1] | Reg[rs2];
			break;
		}
		/* AND */
		case 7:{
			Reg[rd] = Reg[rs1] & Reg[rs2];
			break;
		}
	}
}
void I_type(){
	/* decode for I_type */
	rd = (inst >> 7) & Mask_Reg;
	rs1 = (inst >> 15) & Mask_Reg;
	func3 = (inst >> 12) & Mask_func3;
	func7 = (inst >> 25) & Mask_func7;
	imm = inst >> 20;
	int shift = (inst >> 20) & 0x3f;
	switch(func3){
		/* ADDI */
		case 0:{
			Reg[rd] = Reg[rs1] + imm;
			break;
		}
		/* SLLI */
		case 1:{
			Reg[rd] = Reg[rs1] << shift;
			break;
		}
		/* SLTI */
		case 2:{
			if(Reg[rs1] < imm)
				Reg[rd] = 1;
			else
				Reg[rd] = 0;
			break;
		}
		/* SLTIU */
		case 3:{
			if((unsigned long long)Reg[rs1] < (unsigned long long)imm)
				Reg[rd] = 1;
			else
				Reg[rd] = 0;
			break;
		}
		/* XORI */
		case 4:{
			Reg[rd] = Reg[rs1] ^ imm;
			break;
		}
		/* SRLI and SRAI */
		case 5:{
			/* SRAI */
			if(func7 != 0)
				Reg[rd] = Reg[rs1] >> shift;
			/* SRLI */
			else
				Reg[rd] = (unsigned long long)Reg[rs1] >> shift;
			break;
		}
		/* ORI */
		case 6:{
			Reg[rd] = Reg[rs1] | imm;
			break;
		}
		/* ANDI */
		case 7:{
			Reg[rd] = Reg[rs1] & imm;
			break;
		}
	}
}
void Branch_type(){
	func3 = (inst >> 12) & Mask_func3;
	rs1 = (inst >> 15) & Mask_Reg;
	rs2 = (inst >> 20) & Mask_Reg;
	/* get imm */
	imm = (inst >> 8) & 0xf;
	imm += ((inst >> 25) & 0x3f) << 4;
	imm += ((inst >> 7) & 0x1) << 10;
	imm += ((inst >> 31) & 0x1) << 11;
	/* turn imm into signed extenssion */
	imm = (imm << 52) >> 52;
	/* muiltiple 2 */ 
	imm = imm << 1;
	switch(func3){
		/* BEQ */
		case 0:{
			if(Reg[rs1] == Reg[rs2])
				pc = (int *)((long long)pc + imm);
			break;
		}
		/* BNE */
		case 1:{
			if(Reg[rs1] != Reg[rs2])
				pc = (int *)((long long)pc + imm);
			break;
		}
		/* BLT */
		case 4:{
			if(Reg[rs1] < Reg[rs2])
				pc = (int *)((long long)pc + imm);
			break;
		}
		/* BGE */
		case 5:{
			if(Reg[rs1] >= Reg[rs2])
				pc = (int *)((long long)pc + imm);
			break;
		}
		/* BLEU */
		case 6:{
			if((unsigned long long)Reg[rs1] < (unsigned long long)Reg[rs2])
				pc = (int *)((long long)pc + imm);
			break;
		}
		/* BGEU */
		case 7:{
			if((unsigned long long)Reg[rs1] >= (unsigned long long)Reg[rs2])
				pc = (int *)((long long)pc + imm);
			break;
		}
	}
}
void Load_type(){
	rd = (inst >> 7) & Mask_Reg;
	func3 = (inst >> 12) & Mask_func3;
	rs1 = (inst >> 15) & Mask_Reg;
	imm = inst >> 20;
	long long* address = (long long*)(Reg[rs1] + imm);
	unsigned long long tmp;
	switch(func3){
		/* LB  */
		case 0:{
			Reg[rd] = *((char*)address);
			break;
		}
		/* LH  */
		case 1:{
			Reg[rd] = *((short*)address);
			break;
		}
		/* LW  */
		case 2:{
			Reg[rd] = *((int*)address);
			break;
		}
		/* LD */
		case 3:{
			Reg[rd] = *address;
			break;
		}
		/* LBU */
		case 4:{
			tmp = *((unsigned char*)address);
			Reg[rd] = tmp;
			break;
		}
		/* LHU */
		case 5:{
			tmp = *((unsigned short*)address);
			Reg[rd] = tmp;
			break;
		}
		/* LWU */
		case 6:{
			tmp = *((unsigned int*)address);
			Reg[rd] = tmp;
			break;
		}
	}
}
void Store_type(){
	func3 = (inst >> 12) & Mask_func3;
	rs1 = (inst >> 15) & Mask_Reg;
	rs2 = (inst >> 20) & Mask_Reg;
	/* get imm and turn into sign extention */
	imm = (inst >> 7) & 0x1f;
	imm += ((inst >> 25) & 0x7f) << 5;
	imm = (imm << 52) >> 52;
	switch(func3){
		/* SB */
		case 0:{
			char* address1 = (char*)(Reg[rs1] + imm);
			*address1 = Reg[rs2];
			break;
		}
		/* SH */
		case 1:{
			short* address2 = (short*)(Reg[rs1] + imm);
			*address2 = Reg[rs2];
			break;
		}
		/* SW */
		case 2:{
			int* address3 = (int*)(Reg[rs1] + imm);
			*address3 = Reg[rs2];
			break;
		}
		/* SD */
		case 3:{
			long long* address3 = (long long*)(Reg[rs1] + imm);
			*address3 = Reg[rs2];
			break;
		}
	}
}
void JAL(){
	/* get imm */
	imm = (inst >> 21) & 0x3ff;
	imm += ((inst >> 20) & 0x1) << 10;
	imm += ((inst >> 12) & 0xff) << 18;
	imm += ((inst >> 31) & 0x1) << 19;
	/* turn imm into sign extension */
	imm = (imm << 44) >> 44;
	/* multiple 2 */
	imm = imm << 1;
	rd = (inst >> 7) & Mask_Reg;
	if(rd != 0)
		Reg[rd] = pc + 1;
	pc = (int *)((long long)pc + imm);
}
void JALR(){
	rd = (inst >> 7) & Mask_Reg;
	rs1 = (inst >> 15) & Mask_Reg;
	imm = inst >> 20;
	Reg[rd] = pc + 1;
	pc = ((Reg[rs1] + imm) >> 1) << 1;
}
void AUIPC(){
	rd = (inst >> 7) & Mask_Reg;
	imm = (inst >> 12) << 12;
	Reg[rd] = pc + imm;
}
void W_R_type(){
	rd = (inst >> 7) & Mask_Reg;
	func3 = (inst >> 12) & Mask_func3;
	rs1 = (inst >> 15) & Mask_Reg;
	rs2 = (inst >> 20) & Mask_Reg;
	func7 = (inst >> 25) & Mask_func7;
	long long a = Reg[rs1] & MASK_Low32;
	long long b = Reg[rs2] & MASK_Low32;
	int shift = Reg[rs2] & 0x1f;
	switch(func3){
		/* ADDW and SUBW */
		case 0:{
			if(func7 == 0)
				Reg[rd] = ((a + b) << 32) >> 32;
			else
				Reg[rd] = ((a - b) << 32) >> 32;
			break;
		}
		/* SLLW */
		case 1:{
			Reg[rd] = Reg[rd] & MASK_High32 + (a << shift) & MASK_Low32;
			break;
		}
		/* SRLW and SRAW */
		case 5:{
			if(func7 == 0)
				Reg[rd] = Reg[rd] & MASK_High32 + (a >> shift) & MASK_Low32;
			else{
				a = (a << 32) >> 32;
				Reg[rd] = Reg[rd] & MASK_High32 + (a >> shift) & MASK_Low32;
			}
			break;
		}
	}
}
void W_I_type(){
	rd = (inst >> 7) & Mask_Reg;
	func3 = (inst >> 12) & Mask_func3;
	rs1 = (inst >> 15) & Mask_Reg;
	func7 = (inst >> 25) & Mask_func7;
	long long a = Reg[rs1] & MASK_Low32;
	imm = inst >> 20;
	imm = imm & MASK_Low32;
	int shift = (inst >> 20) & 0x1f;
	switch(func3){
		/* ADDIW */
		case 0:{
			Reg[rd] = ((Reg[rs1] + imm) << 32) >> 32;
			break;
		}
		/* SLLIW */
		case 1:{
			Reg[rd] = Reg[rd] & MASK_High32 + (a << shift) & MASK_Low32;
			break;
		}
		/* SRLIW and SRAIW */
		case 5:{
			if(func7 == 0)
				Reg[rd] = Reg[rd] & MASK_High32 + (a >> shift) & MASK_Low32;
			else{
				a = (a << 32) >> 32;
				Reg[rd] = Reg[rd] & MASK_High32 + (a >> shift) & MASK_Low32;
			}
			break;
		}
	}
}
