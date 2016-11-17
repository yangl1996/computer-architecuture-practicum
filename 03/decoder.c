#include "decoder.h"
void decode(){
#ifdef DEBUG
    //printf("Decoding instruction at actual %llx\n", pc);
    printf("INS 0x%x\n", *pc);
    //printf("OPCODE 0x%x\n", *pc & Mask_op);
#endif
	/* get instruction and convert to binary char */
	inst = *pc;
	/* get different parts in decimal int */
	opcode = inst & Mask_op;
	rd = (inst >> 7) & Mask_Reg;
	func3 = (inst >> 12) & Mask_func3;
	rs1 = (inst >> 15) & Mask_Reg;
	rs2 = (inst >> 20) & Mask_Reg;
	func7 = (inst >> 25) & Mask_func7;
	rm = (inst >> 12) & Mask_func3;
	fmt = (inst >> 25) & 0x3;
	func5 = (inst >> 27) & Mask_Reg;
	rs3 =  (inst >> 27) & Mask_Reg;
	/* different cases for opcode*/
	switch(opcode){
		case R_op:{
			if(func7 != 1)
				R_type();
			else
				Mul_Div_type();
			Rpc += 4;
			break;
		}
		case I_op:{
			I_type();
			Rpc += 4;
			break;
		}
		case Load_op:{
			Load_type();
			Rpc += 4;
			break;
		}
		case Store_op:{
			Store_type();
			Rpc += 4;
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
			Rpc += 4;
			break;
		}
		case LUI_op:{
			int imm = inst & 0xfffff000;
			Reg[rd] = imm;
			Rpc += 4;
			break;
		}
		case W_R_op:{
			if(func7 != 1)
				W_R_type();
			else
				Mul_Div_64_type();
			Rpc += 4;
			break;
		}
		case W_I_op:{
			W_I_type();
			Rpc += 4;
			break;
		}
		case F_Load_op:{
			F_Load();
			Rpc += 4;
			break;
		}
		case F_Store_op:{
			F_Store();
			Rpc += 4;
			break;
		}
		case F_op:{
			F_type();
			Rpc += 4;
			break;
		}
		case FMADD_op:{
			FMADD();
			Rpc += 4;
			break;
		}
		case FMSUB_op:{
			FMSUB();
			Rpc += 4;
			break;
		}
		case FNMADD_op:{
			FNMADD();
			Rpc += 4;
			break;
		}
		case FNMSUB_op:{
			FNMSUB();
			Rpc += 4;
			break;
		}
        default:{
            printf("Error decoding\n");
        }
	}
}
void R_type(){
	int shift = Reg[rs2] & 0x3f;
	switch(func3){
		/* ADD and SUB */
		case 0:{
			if(func7 == 0){
				printf("	Reg[rs1] in ADD: %llx\n",Reg[rs1]);
				Reg[rd] = Reg[rs1] + Reg[rs2];
				printf("	Reg[rd] after ADD: %llx\n",Reg[rd]);
			}
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
		default:{
            printf("Error decoding R_type\n");
        }
	}
}
void I_type(){
	int tmp = inst >> 20;
	imm = tmp;
	int shift = (inst >> 20) & 0x3f;
	switch(func3){
		/* ADDI */
		case 0:{
			// printf("rs1 in ADDI: %d\n", rs1);
			 printf("	Reg[rs1] in ADDI: %llx\n",Reg[rs1]);
			// printf("imm in ADDI: %llx\n",imm);
			Reg[rd] = Reg[rs1] + imm;
			// printf("rd in ADDI: %d\n", rd);
			 printf("	Reg[rd] after ADDI: %llx\n",Reg[rd]);
			break;
		}
		/* SLLI */
		case 1:{
			Reg[rd] = Reg[rs1] << shift;
			printf("	Reg[rs1] after SLLI: %llx\n",Reg[rs1]);
			printf("	Reg[rd] after SLLI: %llx\n",Reg[rd]);
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
			if(func7 != 0){
				Reg[rd] = Reg[rs1] >> shift;

				// printf("Reg[rs1] after SRAI:%llx\n",Reg[rs1]);
				// printf("Reg[rd] after SRAI:%llx\n",Reg[rd]);
				// printf("rd after SRAI:%d\n",rd);
			}
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
		default:{
            printf("Error decoding I_type\n");
        }
	}
}
void Branch_type(){
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
			// printf("    Reg[rs1] in BEQ: %llx\n",Reg[rs1]);
			// printf("    Reg[rs2] in BEQ: %llx\n",Reg[rs2]);
			// printf("    rs1 after SRAI:%d\n",rs1);
			// printf("    rs2 after SRAI:%d\n",rs2);
			if(Reg[rs1] == Reg[rs2])
				Rpc += imm;
			else
				Rpc += 4;
			break;
		}
		/* BNE */
		case 1:{
			if(Reg[rs1] != Reg[rs2])
				Rpc += imm;
			else
				Rpc += 4;
			break;
		}
		/* BLT */
		case 4:{
			if(Reg[rs1] < Reg[rs2])
				Rpc += imm;
			else
				Rpc += 4;
			break;
		}
		/* BGE */
		case 5:{
			if(Reg[rs1] >= Reg[rs2])
				Rpc += imm;
			else
				Rpc += 4;
			break;
		}
		/* BLTU */
		case 6:{
			if((unsigned long long)Reg[rs1] < (unsigned long long)Reg[rs2])
			    Rpc += imm;
			else
				Rpc += 4;
            break;
		}
		/* BGEU */
		case 7:{
			if((unsigned long long)Reg[rs1] >= (unsigned long long)Reg[rs2])
			    Rpc += imm;
			else
				Rpc += 4;
            break;
		}
		default:{
            printf("Error decoding Branch_type\n");
        }
	}
}
void Load_type(){
	imm = inst >> 20;
	long long* address = (long long*)(Reg[rs1] + imm);
	// printf("rs1 in Load: %d\n",rs1);
	// printf("Reg[rs1] in Load: %llx\n",Reg[rs1]);
	//printf("imm in Load: %llx\n", imm);
	// printf("virtual address in Load: %llx\n", address);
	address = getptr64(address);
	unsigned long long tmp;
	switch(func3){
		/* LB  */
		case 0:{
			Reg[rd] = *((char*)address);
			break;
		}
		/* LH  */
		case 1:{
			// printf("Reg[rs1] in LW: %llx",Reg[rs1]);
			// printf("imm in LW: %llx\n", imm);
			// printf("address in LW: %llx\n", address);
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
			// printf("rd after LD: %d\n",rd);
			 printf("	Reg[rd] after LD: %llx\n",Reg[rd]);
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
		default:{
            printf("Error decoding Load_type\n");
        }
	}
}
void Store_type(){
	/* get imm and turn into sign extention */
	imm = (inst >> 7) & 0x1f;
	imm += ((inst >> 25) & 0x7f) << 5;
	imm = (imm << 52) >> 52;
	switch(func3){
		/* SB */
		case 0:{
			char* address1 = (char*)(Reg[rs1] + imm);
			address1 = getptr64(address1);
			*address1 = Reg[rs2];
			break;
		}
		/* SH */
		case 1:{
			short* address2 = (short*)(Reg[rs1] + imm);
			address2 = getptr64(address2);
			*address2 = Reg[rs2];
			break;
		}
		/* SW */
		case 2:{
			int* address3 = (int*)(Reg[rs1] + imm);
			address3 = getptr64(address3);
			*address3 = Reg[rs2];
			break;
		}
		/* SD */
		case 3:{
			long long* address4 = (long long*)(Reg[rs1] + imm);
			address4 = getptr64(address4);
			*address4 = Reg[rs2];
			printf("rs2 in SD: %llx\n",Reg[rs2]);
			break;
		}
		default:{
            printf("Error decoding Store_type\n");
        }
	}
}
void JAL(){
	/* get imm */
	imm = (inst >> 21) & 0x3ff;
	imm += ((inst >> 20) & 0x1) << 10;
	imm += ((inst >> 12) & 0xff) << 11;
	imm += ((inst >> 31) & 0x1) << 19;
	/* turn imm into sign extension */
	imm = (imm << 44) >> 44;
	/* multiple 2 */
	imm = imm << 1;
	if(rd != 0)
		Reg[rd] = Rpc + 4;
	Rpc += imm;
}
void JALR(){
	imm = inst >> 20;
	if(rd != 0)
		Reg[rd] = Rpc + 4;
	Rpc = ((Reg[rs1] + imm) >> 1) << 1;
	// printf("Rpc after JALR: %llx\n",Rpc);
}
void AUIPC(){
	int tmp = inst & 0xfffff000;
	imm = tmp;
	Reg[rd] = Rpc + imm;
	// printf("imm in AUIPC: %llx\n", imm);
	// printf("Rpc in AUIPC: %llx\n", Rpc);
	// printf("Reg[rd] after AUIPC: %llx\n",Reg[rd]);
}
void W_R_type(){
	int a = Reg[rs1];
	int b = Reg[rs2];
	int shift = Reg[rs2] & 0x1f;
	switch(func3){
		/* ADDW and SUBW */
		case 0:{
			if(func7 == 0)
				Reg[rd] = a + b;
			else
				Reg[rd] = a - b;
			break;
		}
		/* SLLW */
		case 1:{
			Reg[rd] = a << shift;
			break;
		}
		/* SRLW and SRAW */
		case 5:{
			if(func7 == 0)
				Reg[rd] = (int)((unsigned)a >> shift);
			else
				Reg[rd] = a >> shift;
			break;
		}
		default:{
            printf("Error decoding W_R_type\n");
        }
	}
}
void W_I_type(){
	int a = Reg[rs1];
	int tmp = inst >> 20;
	int shift = (inst >> 20) & 0x1f;
	switch(func3){
		/* ADDIW */
		case 0:{
			Reg[rd] = a + tmp;
			//printf("	Reg[rs1] after ADDIW: %llx\n",Reg[rs1]);
			printf("	Reg[rd] after ADDIW: %llx\n",Reg[rd]);
			break;
		}
		/* SLLIW */
		case 1:{
			Reg[rd] = a << shift;
			printf("	Reg[rd] after SLLIW: %llx\n",Reg[rd]);
			break;
		}
		/* SRLIW and SRAIW */
		case 5:{
			if(func7 == 0)
				Reg[rd] = (int)((unsigned)a >> shift);
			else
				Reg[rd] = a >> shift;
			break;
		}
		default:{
            printf("Error decoding W_I_type\n");
        }
	}
}
void Mul_Div_type(){
	unsigned long long a0,a1,b0,b1, a_x_b_low, a_x_b_mid, b_x_a_mid, a_x_b_high;
	unsigned long long tmp, carry;
	a0 = Reg[rs1] & MASK_Low32;
	a1 = (Reg[rs1] & MASK_High32) >> 32;
	b0 = Reg[rs2] & MASK_Low32;
	b1 = (Reg[rs2] & MASK_High32) >> 32; 
	switch(func3){
		/* MUL */
		case 0:{
			Reg[rd] = Reg[rs1] * Reg[rs2];
			break;
		}
		/* MULH */
		case 1:{

			break;
		}
		/* MULHSU */
		case 2:{

			break;
		}
		/* MULHU */
		case 3:{
			a_x_b_low = a0 * b0;
			a_x_b_mid = a1 * b0;
			b_x_a_mid = b1 * a0;
			a_x_b_high = a1 * b1;
			carry = (a_x_b_low >> 32) + (a_x_b_mid & MASK_Low32) + (b_x_a_mid & MASK_Low32);
			carry = carry >> 32;
			Reg[rd] = (a_x_b_mid >> 32) + (b_x_a_mid >> 32) + (a_x_b_high & MASK_Low32) + carry;
			Reg[rd] += (a_x_b_high & MASK_High32);
			break;
		}
		/* DIV */
		case 4:{
			Reg[rd] = Reg[rs1] / Reg[rs2];
			break;
		}
		/* DIVU */
		case 5:{
			tmp = (unsigned long long)Reg[rs1] / (unsigned long long)Reg[rs2];
			Reg[rd] = tmp;
			break;
		}
		/* REM */
		case 6:{
			Reg[rd] = Reg[rs1] % Reg[rs2];
			break;
		}
		/* REMU */
		case 7:{
		    tmp = (unsigned long long)Reg[rs1] % (unsigned long long)Reg[rs2];
			Reg[rd] = tmp;
			break;
		}
		default:{
            printf("Error decoding Mul_Div_type\n");
        }
	}
}
void Mul_Div_64_type(){
	int a0 = Reg[rs1];
	int b0 = Reg[rs2];
	int tmp;
	switch(func3){
		/* MULW */
		case 0:{
			Reg[rd] = a0 * b0;
			break;
		}
		/* DIVW */
		case 4:{
			Reg[rd] = a0 / b0;
			break;
		}
		/* DIVUW */
		case 5:{
			tmp = (unsigned)a0 / (unsigned)b0;
			Reg[rd] = tmp;
			break;
		}
		/* REMW */
		case 6:{
			Reg[rd] = a0 % b0;
			break;
		}
		/* REMUW */
		case 7:{
			tmp = (unsigned)a0 % (unsigned)b0;
			Reg[rd] = tmp;
			break;
		}
		default:{
            printf("Error decoding Mul_Div_64_type\n");
        }
	}
}
void F_Load(){
	imm = inst >> 20;
	switch(rm){
		/* FLW */
		case 2:{
			float* address1 = (float*)(Reg[rs1] + imm);
			address1 = getptr64(address1);
			f_Reg[rd] = *address1;
			break;
		}
		/* FLD */
		case 3:{
			double* address2 = (double*)(Reg[rs1] + imm);
			address2 = getptr64(address2);
			d_Reg[rd] = *address2;
			break;
		}
		default:{
            printf("Error decoding F_Load\n");
        }
	}
}
void F_Store(){
	imm = (inst >> 7) & 0x1f;
	imm += ((inst >> 25) & 0x7f) << 5;
	imm = (imm << 52) >> 52;
	switch(rm){
		/* FSW */
		case 2:{
			float* address1 = (float*)(Reg[rs1] + imm);
			address1 = getptr64(address1);
			*address1 = Reg[rs2];
			break;
		}
		/* FSD */
		case 3:{
			double* address2 = (double*)(Reg[rs1] + imm);
			address2 = getptr64(address2);
			*address2 = Reg[rs2];
			break;
		}
		default:{
            printf("Error decoding F_Store\n");
        }
	}
}
void F_type(){
	switch(func5){
		/* FADD.S and FADD.D */
		case 0:{
			if(fmt == 0)
				f_Reg[rd] = f_Reg[rs1] + f_Reg[rs2];
			else
				d_Reg[rd] = d_Reg[rs1] + d_Reg[rs2];
			break;
		}
		/* FSUB.S and FSUB.D */
		case 1:{
			if(fmt == 0)
				f_Reg[rd] = f_Reg[rs1] - f_Reg[rs2];
			else
				d_Reg[rd] = d_Reg[rs1] - d_Reg[rs2];
			break;
		}
		/* FMUL.S and FMUL.D */
		case 2:{
			if(fmt == 0)
				f_Reg[rd] = f_Reg[rs1] * f_Reg[rs2];
			else
				d_Reg[rd] = d_Reg[rs1] * d_Reg[rs2];
			break;
		}
		/* FDIV.S and FDIV.D */
		case 3:{
			if(fmt == 0)
				f_Reg[rd] = f_Reg[rs1] / f_Reg[rs2];
			else
				d_Reg[rd] = d_Reg[rs1] / d_Reg[rs2];
			break;
		}
		/* FSGNJ.S, FSGNJN.S, FSGNJX.S, FSGNJ.D, FSGNJN.D, FSGNJX.D*/
		case 4:{
			float tmp1 = f_Reg[rs1], tmp2 = f_Reg[rs2];
			int i_rs1 = *(int*)(&tmp1);
			int i_rs2 = *(int*)(&tmp2);
			int res;
			double tmp3 = d_Reg[rs1], tmp4 = d_Reg[rs2];
			long long ll_rs1 = *(long long*)(&tmp3);
			long long ll_rs2 = *(long long*)(&tmp4);
			long long ll_res;
			/* FSGNJ.S, FSGNJN.S, FSGNJX.S */
			if(fmt == 0){
				if(rm == 0){
					res = (i_rs2 & MASK_f32) + (i_rs1 & MASK_f31_0);
					f_Reg[rd] = *(float*)(&res);
				}
				else if(rm == 1){
					res = ((~i_rs2) & MASK_f32) + (i_rs1 & MASK_f31_0);
					f_Reg[rd] = *(float*)(&res);
				}
				else{
					res = ((i_rs1 ^ i_rs2) & MASK_f32) + (i_rs1 & MASK_f31_0);
					f_Reg[rd] = *(float*)(&res);
				}
			}
			/*FSGNJ.D, FSGNJN.D, FSGNJX.D*/
			else{
				if(rm == 0){
					ll_res = (ll_rs2 & MASK_f64) + (ll_rs1 & MASK_f63_0);
					d_Reg[rd] = *(double*)(&ll_res);
				}
				else if(rm == 1){
					ll_res = ((~ll_rs2) & MASK_f64) + (ll_rs1 & MASK_f63_0);
					d_Reg[rd] = *(double*)(&ll_res);
				}
				else{
					ll_res = ((ll_rs1 ^ ll_rs2) & MASK_f64) + (ll_rs1 & MASK_f63_0);
					d_Reg[rd] = *(double*)(&ll_res);
				}
			}
			break;
		}
		/* FMIN.S, FMIN.D, FMAX.S, FMAX.D  */
		case 5:{
			if(fmt == 0){
				if (rm == 0)
					f_Reg[rd] = f_Reg[rs1] < f_Reg[rs2]? f_Reg[rs1]:f_Reg[rs2]; //FMIN.S
				else
					f_Reg[rd] = f_Reg[rs1] > f_Reg[rs2]? f_Reg[rs1]:f_Reg[rs2]; //FMAX.S
			}
			else{
				if (rm == 0)
					d_Reg[rd] = d_Reg[rs1] < d_Reg[rs2]? d_Reg[rs1]:d_Reg[rs2]; //FMIN.D
				else
					d_Reg[rd] = d_Reg[rs1] > d_Reg[rs2]? d_Reg[rs1]:d_Reg[rs2]; //FMAX.D
			}
			break;
		}
		/* FCVT.S.D and FCVT.D.S */
		case 8:{
			/* FCVT.S.D */
			if(fmt == 0){
				f_Reg[rd] = d_Rounding(d_Reg[rs1]);
			}
			/* FCVT.D.S */
			else{
				d_Reg[rd] = f_Reg[rs1];
			}
			break;
		}
		/* FSQRT.S and FSQRT.D */
		case 11:{
			if(fmt == 0)
				f_Reg[rd] = sqrtf(f_Reg[rs1]);
			else
				d_Reg[rd] = sqrt(d_Reg[rs1]);
			break;
		}
		/* FEQ.S, FLT.S, FLE.S, FEQ.D, FLT.D, FLE.D */
		case 20:{
			if(fmt == 0){
				if(isnan(f_Reg[rs1]) || isnan(f_Reg[rs2]))
					f_Reg[rd] = 0;
				else if(rm == 0)
					f_Reg[rd] = (f_Reg[rs1] <= f_Reg[rs2]);
				else if(rm == 1)
					f_Reg[rd] = (f_Reg[rs1] < f_Reg[rs2]);
				else
					f_Reg[rd] = (f_Reg[rs1] == f_Reg[rs2]);
			}
			else{
				if(isnan(d_Reg[rs1]) || isnan(d_Reg[rs2]))
					d_Reg[rd] = 0;
				else if(rm == 0)
					d_Reg[rd] = (d_Reg[rs1] <= d_Reg[rs2]);
				else if(rm == 1)
					d_Reg[rd] = (d_Reg[rs1] < d_Reg[rs2]);
				else
					d_Reg[rd] = (d_Reg[rs1] == d_Reg[rs2]);
			}
			break;
		}
		/* FCVT.W.S, FCVT.WU.S, FCVT.L.S, FCVT.LU.S, FCVT.W.D, FCVT.WU.D, FCVT.L.D, FCVT.LU.D*/
		case 24:{
			if(fmt == 0){
				switch(rs2){
					/* FCVT.W.S*/
					case 0:{
						int tmp = f_Rounding(f_Reg[rs1]);
						Reg[rd] = tmp;
						break;
					}
					/* FCVT.WU.S*/
					case 1:{
						unsigned int tmp2 = f_Rounding(f_Reg[rs1]);
						unsigned long long tmp3 = tmp2;
						Reg[rd] = tmp3;
						break;
					}
					/* FCVT.L.S */
					case 2:{
						Reg[rd] = f_Rounding(f_Reg[rs1]);
						break;
					}
					/* FCVT.LU.S */
					case 3:{
						unsigned long long tmp7 = f_Rounding(f_Reg[rs1]);
						Reg[rd] = tmp7;
						break;
					}
				}
			}
			else{
				switch(rs2){
					/* FCVT.W.D*/
					case 0:{
						int tmp4 = d_Rounding(d_Reg[rs1]);
						Reg[rd] = tmp4;
						break;
					}
					/* FCVT.WU.D*/
					case 1:{
						unsigned int tmp5 = d_Rounding(d_Reg[rs1]);
						unsigned long long tmp6 = tmp5;
						Reg[rd] = tmp6;
						break;
					}
					/* FCVT.L.D */
					case 2:{
						Reg[rd] = d_Rounding(d_Reg[rs1]);
						break;
					}
					/* FCVT.LU.D */
					case 3:{
						unsigned long long tmp8 = d_Rounding(d_Reg[rs1]);
						Reg[rd] = tmp8;
						break;
					}
				}
			}
			break;
		}
		/* FCVT.S.W, FCVT.S.WU, FCVT.S.L, FCVT.S.LU, FCVT.D.W, FCVT.D.WU, FCVT.D.L, FCVT.D.LU*/
		case 26:{
			if(fmt == 0){
				switch(rs2){
					/* FCVT.S.W */
					case 0:{
						int tmp = Reg[rs1];
						f_Reg[rd] = tmp;
						break;
					}
					/* FCVT.S.WU */
					case 1:{
						unsigned tmp2 = Reg[rs1];
						f_Reg[rd] = tmp2;
						break;
					}
					/* FCVT.S.L */
					case 2:{
						f_Reg[rd] = Reg[rs1];
						break;
					}
					/* FCVT.S.LU */
					case 3:{
						unsigned long long tmp5 = Reg[rs1];
						f_Reg[rd] = tmp5; 
						break;
					}
				}
			}
			else{
				switch(rs2){
					/* FCVT.D.W */
					case 0:{
						int tmp3 = Reg[rs1];
						d_Reg[rd] = tmp3;
						break;
					}
					/* FCVT.D.WU */
					case 1:{
						unsigned tmp4 = Reg[rs1];
						d_Reg[rd] = tmp4;
						break;
					}
					/* FCVT.D.L */
					case 2:{
						d_Reg[rd] = Reg[rs1];
						break;
					}
					/* FCVT.D.LU */
					case 3:{
						unsigned long long tmp6 = Reg[rs1];
						d_Reg[rd] = tmp6;
						break;
					}
				}
			}
			break;
		}
		/* FMV.X.S and FMV.X.D */
		case 28:{
			float f_tmp = f_Reg[rs1];
			double d_tmp = d_Reg[rs1];
			if(fmt == 0){
				int tmp = *(int*)(&f_tmp);
				Reg[rd] = tmp;
			}
			else
				Reg[rd] = *(long long*)(&d_tmp);
			break;
		}
		/* FMV.S.X and FMV.D.X */
		case 30:{
			if(fmt == 0){
				int tmp = Reg[rs1];
				f_Reg[rd] = *(float*)(&tmp);
			}
			else{
				long long tmp2 = Reg[rs1];
				d_Reg[rd] = *(double*)(&tmp2);
			}
			break;
		}
		default:{
            printf("Error decoding F_type\n");
        }
	}
}
void FMADD(){
	if(fmt == 0)
		f_Reg[rd] = f_Reg[rs1] * f_Reg[rs2] + f_Reg[rs3];
	else
		d_Reg[rd] = d_Reg[rs1] * d_Reg[rs2] + d_Reg[rs3];
}
void FMSUB(){
	if(fmt == 0)
		f_Reg[rd] = f_Reg[rs1] * f_Reg[rs2] - f_Reg[rs3];
	else
		d_Reg[rd] = d_Reg[rs1] * d_Reg[rs2] - d_Reg[rs3];
}
void FNMADD(){
	if(fmt == 0)
		f_Reg[rd] = -(f_Reg[rs1] * f_Reg[rs2] + f_Reg[rs3]);
	else
		d_Reg[rd] = -(d_Reg[rs1] * d_Reg[rs2] + d_Reg[rs3]);
}
void FNMSUB(){
	if(fmt == 0)
		f_Reg[rd] = -(f_Reg[rs1] * f_Reg[rs2] - f_Reg[rs3]);
	else
		d_Reg[rd] = -(d_Reg[rs1] * d_Reg[rs2] - d_Reg[rs3]);
}
float f_Rounding(float a){
	switch(rm){
		case 0:{
			return rintf(a);
			break;
		}
		case 1:{
			return truncf(a);
			break;
		}
		case 2:{
			return floorf(a); 
			break;
		}
		case 3:{
			return ceilf(a);
			break;
		}
		default :{
			return a;
		}
	}
}
double d_Rounding(double a){
	switch(rm){
		case 0:{
			return rint(a);
			break;
		}
		case 1:{
			return trunc(a);
			break;
		}
		case 2:{
			return floor(a); 
			break;
		}
		case 3:{
			return ceil(a);
			break;
		}
		default :{
			return a;
		}
	}
}