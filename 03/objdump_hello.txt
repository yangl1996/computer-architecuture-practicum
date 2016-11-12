
hello:     file format elf64-littleriscv


Disassembly of section .text:

0000000000010000 <_ftext>:
   10000:	00005197          	auipc	gp,0x5
   10004:	33018193          	addi	gp,gp,816 # 15330 <_gp>
   10008:	00005297          	auipc	t0,0x5
   1000c:	b6828293          	addi	t0,t0,-1176 # 14b70 <__malloc_max_total_mem>
   10010:	00005317          	auipc	t1,0x5
   10014:	bf030313          	addi	t1,t1,-1040 # 14c00 <_end>
   10018:	0002b023          	sd	zero,0(t0)
   1001c:	00828293          	addi	t0,t0,8
   10020:	fe62ece3          	bltu	t0,t1,10018 <_ftext+0x18>
   10024:	00000517          	auipc	a0,0x0
   10028:	1b850513          	addi	a0,a0,440 # 101dc <__libc_fini_array>
   1002c:	16c000ef          	jal	10198 <atexit>
   10030:	208000ef          	jal	10238 <__libc_init_array>
   10034:	00012503          	lw	a0,0(sp)
   10038:	00810593          	addi	a1,sp,8
   1003c:	00000613          	li	a2,0
   10040:	124000ef          	jal	10164 <main>
   10044:	1680006f          	j	101ac <exit>

0000000000010048 <_fini>:
   10048:	00008067          	ret

000000000001004c <deregister_tm_clones>:
   1004c:	00015537          	lui	a0,0x15
   10050:	000157b7          	lui	a5,0x15
   10054:	b2850713          	addi	a4,a0,-1240 # 14b28 <__TMC_END__>
   10058:	b2f78793          	addi	a5,a5,-1233 # 14b2f <__TMC_END__+0x7>
   1005c:	40e787b3          	sub	a5,a5,a4
   10060:	00e00713          	li	a4,14
   10064:	00f77c63          	bleu	a5,a4,1007c <deregister_tm_clones+0x30>
   10068:	00000337          	lui	t1,0x0
   1006c:	00030313          	mv	t1,t1
   10070:	00030663          	beqz	t1,1007c <deregister_tm_clones+0x30>
   10074:	b2850513          	addi	a0,a0,-1240
   10078:	00030067          	jr	t1
   1007c:	00008067          	ret

0000000000010080 <register_tm_clones>:
   10080:	00015537          	lui	a0,0x15
   10084:	000157b7          	lui	a5,0x15
   10088:	b2850593          	addi	a1,a0,-1240 # 14b28 <__TMC_END__>
   1008c:	b2878793          	addi	a5,a5,-1240 # 14b28 <__TMC_END__>
   10090:	40b787b3          	sub	a5,a5,a1
   10094:	4037d793          	srai	a5,a5,0x3
   10098:	03f7d593          	srli	a1,a5,0x3f
   1009c:	00f585b3          	add	a1,a1,a5
   100a0:	4015d593          	srai	a1,a1,0x1
   100a4:	00058c63          	beqz	a1,100bc <register_tm_clones+0x3c>
   100a8:	00000337          	lui	t1,0x0
   100ac:	00030313          	mv	t1,t1
   100b0:	00030663          	beqz	t1,100bc <register_tm_clones+0x3c>
   100b4:	b2850513          	addi	a0,a0,-1240
   100b8:	00030067          	jr	t1
   100bc:	00008067          	ret

00000000000100c0 <__do_global_dtors_aux>:
   100c0:	ff010113          	addi	sp,sp,-16
   100c4:	00813023          	sd	s0,0(sp)
   100c8:	8601c783          	lbu	a5,-1952(gp) # 14b90 <_bss_start>
   100cc:	00113423          	sd	ra,8(sp)
   100d0:	02079663          	bnez	a5,100fc <__do_global_dtors_aux+0x3c>
   100d4:	f79ff0ef          	jal	1004c <deregister_tm_clones>
   100d8:	000007b7          	lui	a5,0x0
   100dc:	00078793          	mv	a5,a5
   100e0:	00078a63          	beqz	a5,100f4 <__do_global_dtors_aux+0x34>
   100e4:	00013537          	lui	a0,0x13
   100e8:	22050513          	addi	a0,a0,544 # 13220 <__fini_array_end>
   100ec:	ffff0317          	auipc	t1,0xffff0
   100f0:	f14300e7          	jalr	t1,-236 # 0 <_ftext-0x10000>
   100f4:	00100793          	li	a5,1
   100f8:	86f18023          	sb	a5,-1952(gp) # 14b90 <_bss_start>
   100fc:	00813083          	ld	ra,8(sp)
   10100:	00013403          	ld	s0,0(sp)
   10104:	01010113          	addi	sp,sp,16
   10108:	00008067          	ret

000000000001010c <frame_dummy>:
   1010c:	ff010113          	addi	sp,sp,-16
   10110:	000007b7          	lui	a5,0x0
   10114:	00113423          	sd	ra,8(sp)
   10118:	00078793          	mv	a5,a5
   1011c:	00078c63          	beqz	a5,10134 <frame_dummy+0x28>
   10120:	00013537          	lui	a0,0x13
   10124:	86818593          	addi	a1,gp,-1944 # 14b98 <object.3092>
   10128:	22050513          	addi	a0,a0,544 # 13220 <__fini_array_end>
   1012c:	ffff0317          	auipc	t1,0xffff0
   10130:	ed4300e7          	jalr	t1,-300 # 0 <_ftext-0x10000>
   10134:	000147b7          	lui	a5,0x14
   10138:	bc878513          	addi	a0,a5,-1080 # 13bc8 <__JCR_END__>
   1013c:	00053783          	ld	a5,0(a0)
   10140:	00079863          	bnez	a5,10150 <frame_dummy+0x44>
   10144:	00813083          	ld	ra,8(sp)
   10148:	01010113          	addi	sp,sp,16
   1014c:	f35ff06f          	j	10080 <register_tm_clones>
   10150:	000007b7          	lui	a5,0x0
   10154:	00078793          	mv	a5,a5
   10158:	fe0786e3          	beqz	a5,10144 <frame_dummy+0x38>
   1015c:	000780e7          	jalr	a5
   10160:	fe5ff06f          	j	10144 <frame_dummy+0x38>

0000000000010164 <main>:
   10164:	ff010113          	addi	sp,sp,-16
   10168:	00113423          	sd	ra,8(sp)
   1016c:	00813023          	sd	s0,0(sp)
   10170:	01010413          	addi	s0,sp,16
   10174:	000137b7          	lui	a5,0x13
   10178:	1f078513          	addi	a0,a5,496 # 131f0 <__errno+0x8>
   1017c:	20c000ef          	jal	10388 <puts>
   10180:	00000793          	li	a5,0
   10184:	00078513          	mv	a0,a5
   10188:	00813083          	ld	ra,8(sp)
   1018c:	00013403          	ld	s0,0(sp)
   10190:	01010113          	addi	sp,sp,16
   10194:	00008067          	ret

0000000000010198 <atexit>:
   10198:	00050593          	mv	a1,a0
   1019c:	00000693          	li	a3,0
   101a0:	00000613          	li	a2,0
   101a4:	00000513          	li	a0,0
   101a8:	2bc0006f          	j	10464 <__register_exitproc>

00000000000101ac <exit>:
   101ac:	ff010113          	addi	sp,sp,-16
   101b0:	00000593          	li	a1,0
   101b4:	00813023          	sd	s0,0(sp)
   101b8:	00113423          	sd	ra,8(sp)
   101bc:	00050413          	mv	s0,a0
   101c0:	3b8000ef          	jal	10578 <__call_exitprocs>
   101c4:	8081b503          	ld	a0,-2040(gp) # 14b38 <_global_impure_ptr>
   101c8:	05853783          	ld	a5,88(a0)
   101cc:	00078463          	beqz	a5,101d4 <exit+0x28>
   101d0:	000780e7          	jalr	a5
   101d4:	00040513          	mv	a0,s0
   101d8:	7f5020ef          	jal	131cc <_exit>

00000000000101dc <__libc_fini_array>:
   101dc:	fe010113          	addi	sp,sp,-32
   101e0:	00813823          	sd	s0,16(sp)
   101e4:	00913423          	sd	s1,8(sp)
   101e8:	00013437          	lui	s0,0x13
   101ec:	000134b7          	lui	s1,0x13
   101f0:	21848493          	addi	s1,s1,536 # 13218 <__init_array_end>
   101f4:	22040413          	addi	s0,s0,544 # 13220 <__fini_array_end>
   101f8:	40940433          	sub	s0,s0,s1
   101fc:	ff840793          	addi	a5,s0,-8
   10200:	00113c23          	sd	ra,24(sp)
   10204:	40345413          	srai	s0,s0,0x3
   10208:	009784b3          	add	s1,a5,s1
   1020c:	00040c63          	beqz	s0,10224 <__libc_fini_array+0x48>
   10210:	0004b783          	ld	a5,0(s1)
   10214:	fff40413          	addi	s0,s0,-1
   10218:	ff848493          	addi	s1,s1,-8
   1021c:	000780e7          	jalr	a5
   10220:	fe0418e3          	bnez	s0,10210 <__libc_fini_array+0x34>
   10224:	01813083          	ld	ra,24(sp)
   10228:	01013403          	ld	s0,16(sp)
   1022c:	00813483          	ld	s1,8(sp)
   10230:	02010113          	addi	sp,sp,32
   10234:	e15ff06f          	j	10048 <_fini>

0000000000010238 <__libc_init_array>:
   10238:	fe010113          	addi	sp,sp,-32
   1023c:	00813823          	sd	s0,16(sp)
   10240:	000137b7          	lui	a5,0x13
   10244:	00013437          	lui	s0,0x13
   10248:	01213023          	sd	s2,0(sp)
   1024c:	21078793          	addi	a5,a5,528 # 13210 <_etext>
   10250:	21040913          	addi	s2,s0,528 # 13210 <_etext>
   10254:	41278933          	sub	s2,a5,s2
   10258:	00913423          	sd	s1,8(sp)
   1025c:	00113c23          	sd	ra,24(sp)
   10260:	40395913          	srai	s2,s2,0x3
   10264:	21040413          	addi	s0,s0,528
   10268:	00000493          	li	s1,0
   1026c:	00090c63          	beqz	s2,10284 <__libc_init_array+0x4c>
   10270:	00043783          	ld	a5,0(s0)
   10274:	00148493          	addi	s1,s1,1
   10278:	00840413          	addi	s0,s0,8
   1027c:	000780e7          	jalr	a5
   10280:	fe9918e3          	bne	s2,s1,10270 <__libc_init_array+0x38>
   10284:	dc5ff0ef          	jal	10048 <_fini>
   10288:	00013437          	lui	s0,0x13
   1028c:	000137b7          	lui	a5,0x13
   10290:	21040913          	addi	s2,s0,528 # 13210 <_etext>
   10294:	21878793          	addi	a5,a5,536 # 13218 <__init_array_end>
   10298:	41278933          	sub	s2,a5,s2
   1029c:	40395913          	srai	s2,s2,0x3
   102a0:	21040413          	addi	s0,s0,528
   102a4:	00000493          	li	s1,0
   102a8:	00090c63          	beqz	s2,102c0 <__libc_init_array+0x88>
   102ac:	00043783          	ld	a5,0(s0)
   102b0:	00148493          	addi	s1,s1,1
   102b4:	00840413          	addi	s0,s0,8
   102b8:	000780e7          	jalr	a5
   102bc:	fe9918e3          	bne	s2,s1,102ac <__libc_init_array+0x74>
   102c0:	01813083          	ld	ra,24(sp)
   102c4:	01013403          	ld	s0,16(sp)
   102c8:	00813483          	ld	s1,8(sp)
   102cc:	00013903          	ld	s2,0(sp)
   102d0:	02010113          	addi	sp,sp,32
   102d4:	00008067          	ret

00000000000102d8 <_puts_r>:
   102d8:	fa010113          	addi	sp,sp,-96
   102dc:	04813823          	sd	s0,80(sp)
   102e0:	00050413          	mv	s0,a0
   102e4:	00058513          	mv	a0,a1
   102e8:	04913423          	sd	s1,72(sp)
   102ec:	04113c23          	sd	ra,88(sp)
   102f0:	00058493          	mv	s1,a1
   102f4:	0a0000ef          	jal	10394 <strlen>
   102f8:	01043583          	ld	a1,16(s0)
   102fc:	00013737          	lui	a4,0x13
   10300:	20870713          	addi	a4,a4,520 # 13208 <__errno+0x20>
   10304:	01059683          	lh	a3,16(a1)
   10308:	02e13823          	sd	a4,48(sp)
   1030c:	00100713          	li	a4,1
   10310:	02e13c23          	sd	a4,56(sp)
   10314:	02010713          	addi	a4,sp,32
   10318:	00150613          	addi	a2,a0,1
   1031c:	00e13423          	sd	a4,8(sp)
   10320:	00200713          	li	a4,2
   10324:	02913023          	sd	s1,32(sp)
   10328:	02a13423          	sd	a0,40(sp)
   1032c:	00c13c23          	sd	a2,24(sp)
   10330:	00e12823          	sw	a4,16(sp)
   10334:	03269793          	slli	a5,a3,0x32
   10338:	0207c263          	bltz	a5,1035c <_puts_r+0x84>
   1033c:	0ac5a783          	lw	a5,172(a1)
   10340:	ffffe737          	lui	a4,0xffffe
   10344:	00002637          	lui	a2,0x2
   10348:	fff7071b          	addiw	a4,a4,-1
   1034c:	00c6e6b3          	or	a3,a3,a2
   10350:	00e7f733          	and	a4,a5,a4
   10354:	00d59823          	sh	a3,16(a1)
   10358:	0ae5a623          	sw	a4,172(a1)
   1035c:	00810613          	addi	a2,sp,8
   10360:	00040513          	mv	a0,s0
   10364:	3a8000ef          	jal	1070c <__sfvwrite_r>
   10368:	05813083          	ld	ra,88(sp)
   1036c:	00a03533          	snez	a0,a0
   10370:	40a0053b          	negw	a0,a0
   10374:	00a56513          	ori	a0,a0,10
   10378:	05013403          	ld	s0,80(sp)
   1037c:	04813483          	ld	s1,72(sp)
   10380:	06010113          	addi	sp,sp,96
   10384:	00008067          	ret

0000000000010388 <puts>:
   10388:	00050593          	mv	a1,a0
   1038c:	8101b503          	ld	a0,-2032(gp) # 14b40 <_impure_ptr>
   10390:	f49ff06f          	j	102d8 <_puts_r>

0000000000010394 <strlen>:
   10394:	00757793          	andi	a5,a0,7
   10398:	00050593          	mv	a1,a0
   1039c:	06079a63          	bnez	a5,10410 <strlen+0x7c>
   103a0:	000157b7          	lui	a5,0x15
   103a4:	b587b683          	ld	a3,-1192(a5) # 14b58 <__malloc_trim_threshold+0x8>
   103a8:	fff00613          	li	a2,-1
   103ac:	00850513          	addi	a0,a0,8
   103b0:	ff853783          	ld	a5,-8(a0)
   103b4:	00d7f733          	and	a4,a5,a3
   103b8:	00d70733          	add	a4,a4,a3
   103bc:	00d7e7b3          	or	a5,a5,a3
   103c0:	00f767b3          	or	a5,a4,a5
   103c4:	fec784e3          	beq	a5,a2,103ac <strlen+0x18>
   103c8:	ff854783          	lbu	a5,-8(a0)
   103cc:	40b505b3          	sub	a1,a0,a1
   103d0:	06078263          	beqz	a5,10434 <strlen+0xa0>
   103d4:	ff954783          	lbu	a5,-7(a0)
   103d8:	04078a63          	beqz	a5,1042c <strlen+0x98>
   103dc:	ffa54783          	lbu	a5,-6(a0)
   103e0:	06078263          	beqz	a5,10444 <strlen+0xb0>
   103e4:	ffb54783          	lbu	a5,-5(a0)
   103e8:	04078a63          	beqz	a5,1043c <strlen+0xa8>
   103ec:	ffc54783          	lbu	a5,-4(a0)
   103f0:	ffd54703          	lbu	a4,-3(a0)
   103f4:	ffe54683          	lbu	a3,-2(a0)
   103f8:	04078a63          	beqz	a5,1044c <strlen+0xb8>
   103fc:	04070c63          	beqz	a4,10454 <strlen+0xc0>
   10400:	fff58513          	addi	a0,a1,-1
   10404:	04068c63          	beqz	a3,1045c <strlen+0xc8>
   10408:	00008067          	ret
   1040c:	f8070ae3          	beqz	a4,103a0 <strlen+0xc>
   10410:	00054783          	lbu	a5,0(a0)
   10414:	00150513          	addi	a0,a0,1
   10418:	00757713          	andi	a4,a0,7
   1041c:	fe0798e3          	bnez	a5,1040c <strlen+0x78>
   10420:	40b50533          	sub	a0,a0,a1
   10424:	fff50513          	addi	a0,a0,-1
   10428:	00008067          	ret
   1042c:	ff958513          	addi	a0,a1,-7
   10430:	00008067          	ret
   10434:	ff858513          	addi	a0,a1,-8
   10438:	00008067          	ret
   1043c:	ffb58513          	addi	a0,a1,-5
   10440:	00008067          	ret
   10444:	ffa58513          	addi	a0,a1,-6
   10448:	00008067          	ret
   1044c:	ffc58513          	addi	a0,a1,-4
   10450:	00008067          	ret
   10454:	ffd58513          	addi	a0,a1,-3
   10458:	00008067          	ret
   1045c:	ffe58513          	addi	a0,a1,-2
   10460:	00008067          	ret

0000000000010464 <__register_exitproc>:
   10464:	fd010113          	addi	sp,sp,-48
   10468:	02813023          	sd	s0,32(sp)
   1046c:	8081b403          	ld	s0,-2040(gp) # 14b38 <_global_impure_ptr>
   10470:	00913c23          	sd	s1,24(sp)
   10474:	00050493          	mv	s1,a0
   10478:	1f843503          	ld	a0,504(s0)
   1047c:	01213823          	sd	s2,16(sp)
   10480:	01313423          	sd	s3,8(sp)
   10484:	01413023          	sd	s4,0(sp)
   10488:	02113423          	sd	ra,40(sp)
   1048c:	00058913          	mv	s2,a1
   10490:	00060a13          	mv	s4,a2
   10494:	00068993          	mv	s3,a3
   10498:	0c050663          	beqz	a0,10564 <__register_exitproc+0x100>
   1049c:	00852703          	lw	a4,8(a0)
   104a0:	01f00793          	li	a5,31
   104a4:	0017059b          	addiw	a1,a4,1
   104a8:	04e7d063          	ble	a4,a5,104e8 <__register_exitproc+0x84>
   104ac:	000007b7          	lui	a5,0x0
   104b0:	00078793          	mv	a5,a5
   104b4:	0a078e63          	beqz	a5,10570 <__register_exitproc+0x10c>
   104b8:	31800513          	li	a0,792
   104bc:	ffff0317          	auipc	t1,0xffff0
   104c0:	b44300e7          	jalr	t1,-1212 # 0 <_ftext-0x10000>
   104c4:	0a050663          	beqz	a0,10570 <__register_exitproc+0x10c>
   104c8:	1f843783          	ld	a5,504(s0)
   104cc:	00052423          	sw	zero,8(a0)
   104d0:	00100593          	li	a1,1
   104d4:	00f53023          	sd	a5,0(a0)
   104d8:	1ea43c23          	sd	a0,504(s0)
   104dc:	30052823          	sw	zero,784(a0)
   104e0:	30052a23          	sw	zero,788(a0)
   104e4:	00000713          	li	a4,0
   104e8:	00070793          	mv	a5,a4
   104ec:	02049e63          	bnez	s1,10528 <__register_exitproc+0xc4>
   104f0:	00278793          	addi	a5,a5,2 # 2 <_ftext-0xfffe>
   104f4:	00379793          	slli	a5,a5,0x3
   104f8:	00b52423          	sw	a1,8(a0)
   104fc:	00f50533          	add	a0,a0,a5
   10500:	01253023          	sd	s2,0(a0)
   10504:	00000513          	li	a0,0
   10508:	02813083          	ld	ra,40(sp)
   1050c:	02013403          	ld	s0,32(sp)
   10510:	01813483          	ld	s1,24(sp)
   10514:	01013903          	ld	s2,16(sp)
   10518:	00813983          	ld	s3,8(sp)
   1051c:	00013a03          	ld	s4,0(sp)
   10520:	03010113          	addi	sp,sp,48
   10524:	00008067          	ret
   10528:	00371813          	slli	a6,a4,0x3
   1052c:	01050833          	add	a6,a0,a6
   10530:	11483823          	sd	s4,272(a6)
   10534:	31052883          	lw	a7,784(a0)
   10538:	00100613          	li	a2,1
   1053c:	00e6173b          	sllw	a4,a2,a4
   10540:	00e8e633          	or	a2,a7,a4
   10544:	30c52823          	sw	a2,784(a0)
   10548:	21383823          	sd	s3,528(a6)
   1054c:	00200693          	li	a3,2
   10550:	fad490e3          	bne	s1,a3,104f0 <__register_exitproc+0x8c>
   10554:	31452683          	lw	a3,788(a0)
   10558:	00e6e733          	or	a4,a3,a4
   1055c:	30e52a23          	sw	a4,788(a0)
   10560:	f91ff06f          	j	104f0 <__register_exitproc+0x8c>
   10564:	20040513          	addi	a0,s0,512
   10568:	1ea43c23          	sd	a0,504(s0)
   1056c:	f31ff06f          	j	1049c <__register_exitproc+0x38>
   10570:	fff00513          	li	a0,-1
   10574:	f95ff06f          	j	10508 <__register_exitproc+0xa4>

0000000000010578 <__call_exitprocs>:
   10578:	fa010113          	addi	sp,sp,-96
   1057c:	03413823          	sd	s4,48(sp)
   10580:	8081ba03          	ld	s4,-2040(gp) # 14b38 <_global_impure_ptr>
   10584:	03313c23          	sd	s3,56(sp)
   10588:	000009b7          	lui	s3,0x0
   1058c:	04913423          	sd	s1,72(sp)
   10590:	05213023          	sd	s2,64(sp)
   10594:	03513423          	sd	s5,40(sp)
   10598:	01713c23          	sd	s7,24(sp)
   1059c:	01813823          	sd	s8,16(sp)
   105a0:	04113c23          	sd	ra,88(sp)
   105a4:	04813823          	sd	s0,80(sp)
   105a8:	03613023          	sd	s6,32(sp)
   105ac:	01913423          	sd	s9,8(sp)
   105b0:	01a13023          	sd	s10,0(sp)
   105b4:	00050913          	mv	s2,a0
   105b8:	00058b93          	mv	s7,a1
   105bc:	1f8a0a93          	addi	s5,s4,504
   105c0:	00100493          	li	s1,1
   105c4:	fff00c13          	li	s8,-1
   105c8:	00098993          	mv	s3,s3
   105cc:	1f8a3b03          	ld	s6,504(s4)
   105d0:	0c0b0663          	beqz	s6,1069c <__call_exitprocs+0x124>
   105d4:	000a8d13          	mv	s10,s5
   105d8:	008b2403          	lw	s0,8(s6)
   105dc:	fff4041b          	addiw	s0,s0,-1
   105e0:	02045263          	bgez	s0,10604 <__call_exitprocs+0x8c>
   105e4:	08c0006f          	j	10670 <__call_exitprocs+0xf8>
   105e8:	02040793          	addi	a5,s0,32
   105ec:	00379793          	slli	a5,a5,0x3
   105f0:	00fb07b3          	add	a5,s6,a5
   105f4:	1107b783          	ld	a5,272(a5)
   105f8:	00fb8a63          	beq	s7,a5,1060c <__call_exitprocs+0x94>
   105fc:	fff4041b          	addiw	s0,s0,-1
   10600:	07840863          	beq	s0,s8,10670 <__call_exitprocs+0xf8>
   10604:	00040713          	mv	a4,s0
   10608:	fe0b90e3          	bnez	s7,105e8 <__call_exitprocs+0x70>
   1060c:	008b2783          	lw	a5,8(s6)
   10610:	00371713          	slli	a4,a4,0x3
   10614:	00eb0733          	add	a4,s6,a4
   10618:	fff7879b          	addiw	a5,a5,-1
   1061c:	01073683          	ld	a3,16(a4) # ffffffffffffe010 <_gp+0xfffffffffffe8ce0>
   10620:	0a878e63          	beq	a5,s0,106dc <__call_exitprocs+0x164>
   10624:	00073823          	sd	zero,16(a4)
   10628:	fc068ae3          	beqz	a3,105fc <__call_exitprocs+0x84>
   1062c:	310b2783          	lw	a5,784(s6)
   10630:	0084963b          	sllw	a2,s1,s0
   10634:	008b2c83          	lw	s9,8(s6)
   10638:	00f677b3          	and	a5,a2,a5
   1063c:	08078c63          	beqz	a5,106d4 <__call_exitprocs+0x15c>
   10640:	314b2783          	lw	a5,788(s6)
   10644:	00f67633          	and	a2,a2,a5
   10648:	08061e63          	bnez	a2,106e4 <__call_exitprocs+0x16c>
   1064c:	11073583          	ld	a1,272(a4)
   10650:	00090513          	mv	a0,s2
   10654:	000680e7          	jalr	a3
   10658:	008b2783          	lw	a5,8(s6)
   1065c:	f79798e3          	bne	a5,s9,105cc <__call_exitprocs+0x54>
   10660:	000d3783          	ld	a5,0(s10)
   10664:	f76794e3          	bne	a5,s6,105cc <__call_exitprocs+0x54>
   10668:	fff4041b          	addiw	s0,s0,-1
   1066c:	f9841ce3          	bne	s0,s8,10604 <__call_exitprocs+0x8c>
   10670:	02098663          	beqz	s3,1069c <__call_exitprocs+0x124>
   10674:	008b2783          	lw	a5,8(s6)
   10678:	06079c63          	bnez	a5,106f0 <__call_exitprocs+0x178>
   1067c:	000b3783          	ld	a5,0(s6)
   10680:	08078263          	beqz	a5,10704 <__call_exitprocs+0x18c>
   10684:	000b0513          	mv	a0,s6
   10688:	00fd3023          	sd	a5,0(s10)
   1068c:	ffff0317          	auipc	t1,0xffff0
   10690:	974300e7          	jalr	t1,-1676 # 0 <_ftext-0x10000>
   10694:	000d3b03          	ld	s6,0(s10)
   10698:	f40b10e3          	bnez	s6,105d8 <__call_exitprocs+0x60>
   1069c:	05813083          	ld	ra,88(sp)
   106a0:	05013403          	ld	s0,80(sp)
   106a4:	04813483          	ld	s1,72(sp)
   106a8:	04013903          	ld	s2,64(sp)
   106ac:	03813983          	ld	s3,56(sp)
   106b0:	03013a03          	ld	s4,48(sp)
   106b4:	02813a83          	ld	s5,40(sp)
   106b8:	02013b03          	ld	s6,32(sp)
   106bc:	01813b83          	ld	s7,24(sp)
   106c0:	01013c03          	ld	s8,16(sp)
   106c4:	00813c83          	ld	s9,8(sp)
   106c8:	00013d03          	ld	s10,0(sp)
   106cc:	06010113          	addi	sp,sp,96
   106d0:	00008067          	ret
   106d4:	000680e7          	jalr	a3
   106d8:	f81ff06f          	j	10658 <__call_exitprocs+0xe0>
   106dc:	008b2423          	sw	s0,8(s6)
   106e0:	f49ff06f          	j	10628 <__call_exitprocs+0xb0>
   106e4:	11073503          	ld	a0,272(a4)
   106e8:	000680e7          	jalr	a3
   106ec:	f6dff06f          	j	10658 <__call_exitprocs+0xe0>
   106f0:	000b3783          	ld	a5,0(s6)
   106f4:	000b0d13          	mv	s10,s6
   106f8:	00078b13          	mv	s6,a5
   106fc:	ec0b1ee3          	bnez	s6,105d8 <__call_exitprocs+0x60>
   10700:	f9dff06f          	j	1069c <__call_exitprocs+0x124>
   10704:	00000793          	li	a5,0
   10708:	fedff06f          	j	106f4 <__call_exitprocs+0x17c>

000000000001070c <__sfvwrite_r>:
   1070c:	01063783          	ld	a5,16(a2) # 2010 <_ftext-0xdff0>
   10710:	26078a63          	beqz	a5,10984 <__sfvwrite_r+0x278>
   10714:	0105d703          	lhu	a4,16(a1)
   10718:	f9010113          	addi	sp,sp,-112
   1071c:	06813023          	sd	s0,96(sp)
   10720:	03513c23          	sd	s5,56(sp)
   10724:	03613823          	sd	s6,48(sp)
   10728:	06113423          	sd	ra,104(sp)
   1072c:	04913c23          	sd	s1,88(sp)
   10730:	05213823          	sd	s2,80(sp)
   10734:	05313423          	sd	s3,72(sp)
   10738:	05413023          	sd	s4,64(sp)
   1073c:	03713423          	sd	s7,40(sp)
   10740:	03813023          	sd	s8,32(sp)
   10744:	01913c23          	sd	s9,24(sp)
   10748:	01a13823          	sd	s10,16(sp)
   1074c:	01b13423          	sd	s11,8(sp)
   10750:	00877793          	andi	a5,a4,8
   10754:	00058413          	mv	s0,a1
   10758:	00050b13          	mv	s6,a0
   1075c:	00060a93          	mv	s5,a2
   10760:	0a078863          	beqz	a5,10810 <__sfvwrite_r+0x104>
   10764:	0185b783          	ld	a5,24(a1)
   10768:	0a078463          	beqz	a5,10810 <__sfvwrite_r+0x104>
   1076c:	00277793          	andi	a5,a4,2
   10770:	000ab483          	ld	s1,0(s5)
   10774:	0c078063          	beqz	a5,10834 <__sfvwrite_r+0x128>
   10778:	80000a37          	lui	s4,0x80000
   1077c:	00000993          	li	s3,0
   10780:	00000913          	li	s2,0
   10784:	c00a4a13          	xori	s4,s4,-1024
   10788:	00098613          	mv	a2,s3
   1078c:	000b0513          	mv	a0,s6
   10790:	1e090263          	beqz	s2,10974 <__sfvwrite_r+0x268>
   10794:	00090693          	mv	a3,s2
   10798:	012a7463          	bleu	s2,s4,107a0 <__sfvwrite_r+0x94>
   1079c:	000a0693          	mv	a3,s4
   107a0:	04043783          	ld	a5,64(s0)
   107a4:	03043583          	ld	a1,48(s0)
   107a8:	0006869b          	sext.w	a3,a3
   107ac:	000780e7          	jalr	a5
   107b0:	22a05063          	blez	a0,109d0 <__sfvwrite_r+0x2c4>
   107b4:	010ab783          	ld	a5,16(s5)
   107b8:	00a989b3          	add	s3,s3,a0
   107bc:	40a90933          	sub	s2,s2,a0
   107c0:	40a78533          	sub	a0,a5,a0
   107c4:	00aab823          	sd	a0,16(s5)
   107c8:	fc0510e3          	bnez	a0,10788 <__sfvwrite_r+0x7c>
   107cc:	00000793          	li	a5,0
   107d0:	06813083          	ld	ra,104(sp)
   107d4:	00078513          	mv	a0,a5
   107d8:	06013403          	ld	s0,96(sp)
   107dc:	05813483          	ld	s1,88(sp)
   107e0:	05013903          	ld	s2,80(sp)
   107e4:	04813983          	ld	s3,72(sp)
   107e8:	04013a03          	ld	s4,64(sp)
   107ec:	03813a83          	ld	s5,56(sp)
   107f0:	03013b03          	ld	s6,48(sp)
   107f4:	02813b83          	ld	s7,40(sp)
   107f8:	02013c03          	ld	s8,32(sp)
   107fc:	01813c83          	ld	s9,24(sp)
   10800:	01013d03          	ld	s10,16(sp)
   10804:	00813d83          	ld	s11,8(sp)
   10808:	07010113          	addi	sp,sp,112
   1080c:	00008067          	ret
   10810:	00040593          	mv	a1,s0
   10814:	000b0513          	mv	a0,s6
   10818:	3c4010ef          	jal	11bdc <__swsetup_r>
   1081c:	fff00793          	li	a5,-1
   10820:	fa0518e3          	bnez	a0,107d0 <__sfvwrite_r+0xc4>
   10824:	01045703          	lhu	a4,16(s0)
   10828:	000ab483          	ld	s1,0(s5)
   1082c:	00277793          	andi	a5,a4,2
   10830:	f40794e3          	bnez	a5,10778 <__sfvwrite_r+0x6c>
   10834:	00177793          	andi	a5,a4,1
   10838:	1a079663          	bnez	a5,109e4 <__sfvwrite_r+0x2d8>
   1083c:	80000bb7          	lui	s7,0x80000
   10840:	ffebcc13          	xori	s8,s7,-2
   10844:	00000c93          	li	s9,0
   10848:	00000913          	li	s2,0
   1084c:	fffbcb93          	not	s7,s7
   10850:	10090a63          	beqz	s2,10964 <__sfvwrite_r+0x258>
   10854:	00c42983          	lw	s3,12(s0)
   10858:	20077793          	andi	a5,a4,512
   1085c:	00098a13          	mv	s4,s3
   10860:	26078863          	beqz	a5,10ad0 <__sfvwrite_r+0x3c4>
   10864:	2b396a63          	bltu	s2,s3,10b18 <__sfvwrite_r+0x40c>
   10868:	48077793          	andi	a5,a4,1152
   1086c:	2a078663          	beqz	a5,10b18 <__sfvwrite_r+0x40c>
   10870:	02042a03          	lw	s4,32(s0)
   10874:	01843583          	ld	a1,24(s0)
   10878:	00043d03          	ld	s10,0(s0)
   1087c:	001a179b          	slliw	a5,s4,0x1
   10880:	01478a3b          	addw	s4,a5,s4
   10884:	01fa579b          	srliw	a5,s4,0x1f
   10888:	40bd0d3b          	subw	s10,s10,a1
   1088c:	01478a3b          	addw	s4,a5,s4
   10890:	000d0993          	mv	s3,s10
   10894:	401a5a1b          	sraiw	s4,s4,0x1
   10898:	00198793          	addi	a5,s3,1 # 1 <_ftext-0xffff>
   1089c:	000a0613          	mv	a2,s4
   108a0:	012787b3          	add	a5,a5,s2
   108a4:	00f67863          	bleu	a5,a2,108b4 <__sfvwrite_r+0x1a8>
   108a8:	001d0a1b          	addiw	s4,s10,1
   108ac:	01490a3b          	addw	s4,s2,s4
   108b0:	000a0613          	mv	a2,s4
   108b4:	40077713          	andi	a4,a4,1024
   108b8:	2a070a63          	beqz	a4,10b6c <__sfvwrite_r+0x460>
   108bc:	00060593          	mv	a1,a2
   108c0:	000b0513          	mv	a0,s6
   108c4:	2fc000ef          	jal	10bc0 <_malloc_r>
   108c8:	00050d93          	mv	s11,a0
   108cc:	2e050263          	beqz	a0,10bb0 <__sfvwrite_r+0x4a4>
   108d0:	01843583          	ld	a1,24(s0)
   108d4:	00098613          	mv	a2,s3
   108d8:	341000ef          	jal	11418 <memcpy>
   108dc:	01045783          	lhu	a5,16(s0)
   108e0:	b7f7f793          	andi	a5,a5,-1153
   108e4:	0807e793          	ori	a5,a5,128
   108e8:	00f41823          	sh	a5,16(s0)
   108ec:	41aa0d3b          	subw	s10,s4,s10
   108f0:	013d8533          	add	a0,s11,s3
   108f4:	03442023          	sw	s4,32(s0)
   108f8:	01b43c23          	sd	s11,24(s0)
   108fc:	00a43023          	sd	a0,0(s0)
   10900:	00090a13          	mv	s4,s2
   10904:	01a42623          	sw	s10,12(s0)
   10908:	000a0d13          	mv	s10,s4
   1090c:	00090993          	mv	s3,s2
   10910:	01497863          	bleu	s4,s2,10920 <__sfvwrite_r+0x214>
   10914:	00090d13          	mv	s10,s2
   10918:	00090993          	mv	s3,s2
   1091c:	00090a13          	mv	s4,s2
   10920:	000d0613          	mv	a2,s10
   10924:	000c8593          	mv	a1,s9
   10928:	411000ef          	jal	11538 <memmove>
   1092c:	00c42783          	lw	a5,12(s0)
   10930:	00043603          	ld	a2,0(s0)
   10934:	41478a3b          	subw	s4,a5,s4
   10938:	01a60633          	add	a2,a2,s10
   1093c:	01442623          	sw	s4,12(s0)
   10940:	00c43023          	sd	a2,0(s0)
   10944:	010ab503          	ld	a0,16(s5)
   10948:	013c8cb3          	add	s9,s9,s3
   1094c:	41390933          	sub	s2,s2,s3
   10950:	413509b3          	sub	s3,a0,s3
   10954:	013ab823          	sd	s3,16(s5)
   10958:	e6098ae3          	beqz	s3,107cc <__sfvwrite_r+0xc0>
   1095c:	01045703          	lhu	a4,16(s0)
   10960:	ee091ae3          	bnez	s2,10854 <__sfvwrite_r+0x148>
   10964:	0004bc83          	ld	s9,0(s1)
   10968:	0084b903          	ld	s2,8(s1)
   1096c:	01048493          	addi	s1,s1,16
   10970:	ee1ff06f          	j	10850 <__sfvwrite_r+0x144>
   10974:	0004b983          	ld	s3,0(s1)
   10978:	0084b903          	ld	s2,8(s1)
   1097c:	01048493          	addi	s1,s1,16
   10980:	e09ff06f          	j	10788 <__sfvwrite_r+0x7c>
   10984:	00000793          	li	a5,0
   10988:	00078513          	mv	a0,a5
   1098c:	00008067          	ret
   10990:	01397463          	bleu	s3,s2,10998 <__sfvwrite_r+0x28c>
   10994:	00090993          	mv	s3,s2
   10998:	00098613          	mv	a2,s3
   1099c:	000c8593          	mv	a1,s9
   109a0:	399000ef          	jal	11538 <memmove>
   109a4:	00c42783          	lw	a5,12(s0)
   109a8:	00043703          	ld	a4,0(s0)
   109ac:	413787bb          	subw	a5,a5,s3
   109b0:	01370733          	add	a4,a4,s3
   109b4:	00f42623          	sw	a5,12(s0)
   109b8:	00e43023          	sd	a4,0(s0)
   109bc:	f80794e3          	bnez	a5,10944 <__sfvwrite_r+0x238>
   109c0:	00040593          	mv	a1,s0
   109c4:	000b0513          	mv	a0,s6
   109c8:	5e4010ef          	jal	11fac <_fflush_r>
   109cc:	f6050ce3          	beqz	a0,10944 <__sfvwrite_r+0x238>
   109d0:	01041783          	lh	a5,16(s0)
   109d4:	0407e793          	ori	a5,a5,64
   109d8:	00f41823          	sh	a5,16(s0)
   109dc:	fff00793          	li	a5,-1
   109e0:	df1ff06f          	j	107d0 <__sfvwrite_r+0xc4>
   109e4:	00000a13          	li	s4,0
   109e8:	00000c13          	li	s8,0
   109ec:	00000d13          	li	s10,0
   109f0:	00000913          	li	s2,0
   109f4:	06090e63          	beqz	s2,10a70 <__sfvwrite_r+0x364>
   109f8:	140c0863          	beqz	s8,10b48 <__sfvwrite_r+0x43c>
   109fc:	000a0993          	mv	s3,s4
   10a00:	01497463          	bleu	s4,s2,10a08 <__sfvwrite_r+0x2fc>
   10a04:	00090993          	mv	s3,s2
   10a08:	00043503          	ld	a0,0(s0)
   10a0c:	01843783          	ld	a5,24(s0)
   10a10:	00098b93          	mv	s7,s3
   10a14:	02042683          	lw	a3,32(s0)
   10a18:	00a7fa63          	bleu	a0,a5,10a2c <__sfvwrite_r+0x320>
   10a1c:	00c42c83          	lw	s9,12(s0)
   10a20:	01968cbb          	addw	s9,a3,s9
   10a24:	000c8d93          	mv	s11,s9
   10a28:	053dce63          	blt	s11,s3,10a84 <__sfvwrite_r+0x378>
   10a2c:	0ed9ca63          	blt	s3,a3,10b20 <__sfvwrite_r+0x414>
   10a30:	04043783          	ld	a5,64(s0)
   10a34:	03043583          	ld	a1,48(s0)
   10a38:	000d0613          	mv	a2,s10
   10a3c:	000b0513          	mv	a0,s6
   10a40:	000780e7          	jalr	a5
   10a44:	00050b93          	mv	s7,a0
   10a48:	f8a054e3          	blez	a0,109d0 <__sfvwrite_r+0x2c4>
   10a4c:	417a0a3b          	subw	s4,s4,s7
   10a50:	060a0463          	beqz	s4,10ab8 <__sfvwrite_r+0x3ac>
   10a54:	010ab783          	ld	a5,16(s5)
   10a58:	017d0d33          	add	s10,s10,s7
   10a5c:	41790933          	sub	s2,s2,s7
   10a60:	41778bb3          	sub	s7,a5,s7
   10a64:	017ab823          	sd	s7,16(s5)
   10a68:	d60b82e3          	beqz	s7,107cc <__sfvwrite_r+0xc0>
   10a6c:	f80916e3          	bnez	s2,109f8 <__sfvwrite_r+0x2ec>
   10a70:	0004bd03          	ld	s10,0(s1)
   10a74:	0084b903          	ld	s2,8(s1)
   10a78:	00000c13          	li	s8,0
   10a7c:	01048493          	addi	s1,s1,16
   10a80:	f75ff06f          	j	109f4 <__sfvwrite_r+0x2e8>
   10a84:	000d0593          	mv	a1,s10
   10a88:	000c8613          	mv	a2,s9
   10a8c:	2ad000ef          	jal	11538 <memmove>
   10a90:	00043783          	ld	a5,0(s0)
   10a94:	00040593          	mv	a1,s0
   10a98:	000b0513          	mv	a0,s6
   10a9c:	01b78db3          	add	s11,a5,s11
   10aa0:	01b43023          	sd	s11,0(s0)
   10aa4:	508010ef          	jal	11fac <_fflush_r>
   10aa8:	f20514e3          	bnez	a0,109d0 <__sfvwrite_r+0x2c4>
   10aac:	000c8b93          	mv	s7,s9
   10ab0:	417a0a3b          	subw	s4,s4,s7
   10ab4:	fa0a10e3          	bnez	s4,10a54 <__sfvwrite_r+0x348>
   10ab8:	00040593          	mv	a1,s0
   10abc:	000b0513          	mv	a0,s6
   10ac0:	4ec010ef          	jal	11fac <_fflush_r>
   10ac4:	f00516e3          	bnez	a0,109d0 <__sfvwrite_r+0x2c4>
   10ac8:	00000c13          	li	s8,0
   10acc:	f89ff06f          	j	10a54 <__sfvwrite_r+0x348>
   10ad0:	00043503          	ld	a0,0(s0)
   10ad4:	01843783          	ld	a5,24(s0)
   10ad8:	eaa7ece3          	bltu	a5,a0,10990 <__sfvwrite_r+0x284>
   10adc:	02042783          	lw	a5,32(s0)
   10ae0:	eaf968e3          	bltu	s2,a5,10990 <__sfvwrite_r+0x284>
   10ae4:	000b8693          	mv	a3,s7
   10ae8:	012c6463          	bltu	s8,s2,10af0 <__sfvwrite_r+0x3e4>
   10aec:	0009069b          	sext.w	a3,s2
   10af0:	02f6c6bb          	divw	a3,a3,a5
   10af4:	04043703          	ld	a4,64(s0)
   10af8:	03043583          	ld	a1,48(s0)
   10afc:	000c8613          	mv	a2,s9
   10b00:	000b0513          	mv	a0,s6
   10b04:	02f686bb          	mulw	a3,a3,a5
   10b08:	000700e7          	jalr	a4
   10b0c:	eca052e3          	blez	a0,109d0 <__sfvwrite_r+0x2c4>
   10b10:	00050993          	mv	s3,a0
   10b14:	e31ff06f          	j	10944 <__sfvwrite_r+0x238>
   10b18:	00043503          	ld	a0,0(s0)
   10b1c:	dedff06f          	j	10908 <__sfvwrite_r+0x1fc>
   10b20:	00098613          	mv	a2,s3
   10b24:	000d0593          	mv	a1,s10
   10b28:	211000ef          	jal	11538 <memmove>
   10b2c:	00c42703          	lw	a4,12(s0)
   10b30:	00043783          	ld	a5,0(s0)
   10b34:	4137073b          	subw	a4,a4,s3
   10b38:	013789b3          	add	s3,a5,s3
   10b3c:	00e42623          	sw	a4,12(s0)
   10b40:	01343023          	sd	s3,0(s0)
   10b44:	f09ff06f          	j	10a4c <__sfvwrite_r+0x340>
   10b48:	00090613          	mv	a2,s2
   10b4c:	00a00593          	li	a1,10
   10b50:	000d0513          	mv	a0,s10
   10b54:	7dc000ef          	jal	11330 <memchr>
   10b58:	04050663          	beqz	a0,10ba4 <__sfvwrite_r+0x498>
   10b5c:	00150a13          	addi	s4,a0,1
   10b60:	41aa0a3b          	subw	s4,s4,s10
   10b64:	00100c13          	li	s8,1
   10b68:	e95ff06f          	j	109fc <__sfvwrite_r+0x2f0>
   10b6c:	000b0513          	mv	a0,s6
   10b70:	2f1000ef          	jal	11660 <_realloc_r>
   10b74:	00050d93          	mv	s11,a0
   10b78:	d6051ae3          	bnez	a0,108ec <__sfvwrite_r+0x1e0>
   10b7c:	01843583          	ld	a1,24(s0)
   10b80:	000b0513          	mv	a0,s6
   10b84:	12d010ef          	jal	124b0 <_free_r>
   10b88:	01045783          	lhu	a5,16(s0)
   10b8c:	00c00713          	li	a4,12
   10b90:	00eb2023          	sw	a4,0(s6)
   10b94:	f7f7f793          	andi	a5,a5,-129
   10b98:	0107979b          	slliw	a5,a5,0x10
   10b9c:	4107d79b          	sraiw	a5,a5,0x10
   10ba0:	e35ff06f          	j	109d4 <__sfvwrite_r+0x2c8>
   10ba4:	00190a1b          	addiw	s4,s2,1
   10ba8:	00100c13          	li	s8,1
   10bac:	e51ff06f          	j	109fc <__sfvwrite_r+0x2f0>
   10bb0:	00c00793          	li	a5,12
   10bb4:	00fb2023          	sw	a5,0(s6)
   10bb8:	01041783          	lh	a5,16(s0)
   10bbc:	e19ff06f          	j	109d4 <__sfvwrite_r+0x2c8>

0000000000010bc0 <_malloc_r>:
   10bc0:	fa010113          	addi	sp,sp,-96
   10bc4:	04913423          	sd	s1,72(sp)
   10bc8:	03313c23          	sd	s3,56(sp)
   10bcc:	04113c23          	sd	ra,88(sp)
   10bd0:	04813823          	sd	s0,80(sp)
   10bd4:	05213023          	sd	s2,64(sp)
   10bd8:	03413823          	sd	s4,48(sp)
   10bdc:	03513423          	sd	s5,40(sp)
   10be0:	03613023          	sd	s6,32(sp)
   10be4:	01713c23          	sd	s7,24(sp)
   10be8:	01813823          	sd	s8,16(sp)
   10bec:	01913423          	sd	s9,8(sp)
   10bf0:	01758493          	addi	s1,a1,23
   10bf4:	02e00793          	li	a5,46
   10bf8:	00050993          	mv	s3,a0
   10bfc:	1c97fa63          	bleu	s1,a5,10dd0 <_malloc_r+0x210>
   10c00:	800007b7          	lui	a5,0x80000
   10c04:	ff04f493          	andi	s1,s1,-16
   10c08:	fff7c793          	not	a5,a5
   10c0c:	2497ee63          	bltu	a5,s1,10e68 <_malloc_r+0x2a8>
   10c10:	24b4ec63          	bltu	s1,a1,10e68 <_malloc_r+0x2a8>
   10c14:	245000ef          	jal	11658 <__malloc_lock>
   10c18:	1f700793          	li	a5,503
   10c1c:	7097f063          	bleu	s1,a5,1131c <_malloc_r+0x75c>
   10c20:	0094d793          	srli	a5,s1,0x9
   10c24:	08000693          	li	a3,128
   10c28:	04000513          	li	a0,64
   10c2c:	03f00593          	li	a1,63
   10c30:	24079463          	bnez	a5,10e78 <_malloc_r+0x2b8>
   10c34:	00014937          	lui	s2,0x14
   10c38:	31890913          	addi	s2,s2,792 # 14318 <__malloc_av_>
   10c3c:	00369693          	slli	a3,a3,0x3
   10c40:	00d906b3          	add	a3,s2,a3
   10c44:	0086b403          	ld	s0,8(a3)
   10c48:	ff068693          	addi	a3,a3,-16
   10c4c:	24868663          	beq	a3,s0,10e98 <_malloc_r+0x2d8>
   10c50:	00843783          	ld	a5,8(s0)
   10c54:	01f00613          	li	a2,31
   10c58:	ffc7f793          	andi	a5,a5,-4
   10c5c:	40978733          	sub	a4,a5,s1
   10c60:	02e64063          	blt	a2,a4,10c80 <_malloc_r+0xc0>
   10c64:	22075e63          	bgez	a4,10ea0 <_malloc_r+0x2e0>
   10c68:	01843403          	ld	s0,24(s0)
   10c6c:	22868663          	beq	a3,s0,10e98 <_malloc_r+0x2d8>
   10c70:	00843783          	ld	a5,8(s0)
   10c74:	ffc7f793          	andi	a5,a5,-4
   10c78:	40978733          	sub	a4,a5,s1
   10c7c:	fee654e3          	ble	a4,a2,10c64 <_malloc_r+0xa4>
   10c80:	00058693          	mv	a3,a1
   10c84:	02093403          	ld	s0,32(s2)
   10c88:	01090813          	addi	a6,s2,16
   10c8c:	47040a63          	beq	s0,a6,11100 <_malloc_r+0x540>
   10c90:	00843783          	ld	a5,8(s0)
   10c94:	01f00613          	li	a2,31
   10c98:	ffc7f793          	andi	a5,a5,-4
   10c9c:	40978733          	sub	a4,a5,s1
   10ca0:	44e64a63          	blt	a2,a4,110f4 <_malloc_r+0x534>
   10ca4:	03093423          	sd	a6,40(s2)
   10ca8:	03093023          	sd	a6,32(s2)
   10cac:	20075063          	bgez	a4,10eac <_malloc_r+0x2ec>
   10cb0:	1ff00713          	li	a4,511
   10cb4:	3cf76c63          	bltu	a4,a5,1108c <_malloc_r+0x4cc>
   10cb8:	0037d793          	srli	a5,a5,0x3
   10cbc:	0007879b          	sext.w	a5,a5
   10cc0:	0017861b          	addiw	a2,a5,1
   10cc4:	0016161b          	slliw	a2,a2,0x1
   10cc8:	00361613          	slli	a2,a2,0x3
   10ccc:	00893703          	ld	a4,8(s2)
   10cd0:	00c90633          	add	a2,s2,a2
   10cd4:	00063503          	ld	a0,0(a2)
   10cd8:	4027d79b          	sraiw	a5,a5,0x2
   10cdc:	00100593          	li	a1,1
   10ce0:	00f597b3          	sll	a5,a1,a5
   10ce4:	00e7e7b3          	or	a5,a5,a4
   10ce8:	ff060713          	addi	a4,a2,-16
   10cec:	00e43c23          	sd	a4,24(s0)
   10cf0:	00a43823          	sd	a0,16(s0)
   10cf4:	00f93423          	sd	a5,8(s2)
   10cf8:	00863023          	sd	s0,0(a2)
   10cfc:	00853c23          	sd	s0,24(a0)
   10d00:	4026d61b          	sraiw	a2,a3,0x2
   10d04:	00100713          	li	a4,1
   10d08:	00c71633          	sll	a2,a4,a2
   10d0c:	1cc7e063          	bltu	a5,a2,10ecc <_malloc_r+0x30c>
   10d10:	00f67733          	and	a4,a2,a5
   10d14:	02071463          	bnez	a4,10d3c <_malloc_r+0x17c>
   10d18:	00161613          	slli	a2,a2,0x1
   10d1c:	ffc6f693          	andi	a3,a3,-4
   10d20:	00f67733          	and	a4,a2,a5
   10d24:	0046869b          	addiw	a3,a3,4
   10d28:	00071a63          	bnez	a4,10d3c <_malloc_r+0x17c>
   10d2c:	00161613          	slli	a2,a2,0x1
   10d30:	00f67733          	and	a4,a2,a5
   10d34:	0046869b          	addiw	a3,a3,4
   10d38:	fe070ae3          	beqz	a4,10d2c <_malloc_r+0x16c>
   10d3c:	01f00513          	li	a0,31
   10d40:	0016889b          	addiw	a7,a3,1
   10d44:	0018989b          	slliw	a7,a7,0x1
   10d48:	00389893          	slli	a7,a7,0x3
   10d4c:	011908b3          	add	a7,s2,a7
   10d50:	ff088893          	addi	a7,a7,-16
   10d54:	00088593          	mv	a1,a7
   10d58:	00068313          	mv	t1,a3
   10d5c:	0185b403          	ld	s0,24(a1)
   10d60:	00859a63          	bne	a1,s0,10d74 <_malloc_r+0x1b4>
   10d64:	3a40006f          	j	11108 <_malloc_r+0x548>
   10d68:	3c075263          	bgez	a4,1112c <_malloc_r+0x56c>
   10d6c:	01843403          	ld	s0,24(s0)
   10d70:	38858c63          	beq	a1,s0,11108 <_malloc_r+0x548>
   10d74:	00843783          	ld	a5,8(s0)
   10d78:	ffc7f793          	andi	a5,a5,-4
   10d7c:	40978733          	sub	a4,a5,s1
   10d80:	fee554e3          	ble	a4,a0,10d68 <_malloc_r+0x1a8>
   10d84:	01843783          	ld	a5,24(s0)
   10d88:	01043683          	ld	a3,16(s0)
   10d8c:	0014e613          	ori	a2,s1,1
   10d90:	00c43423          	sd	a2,8(s0)
   10d94:	00f6bc23          	sd	a5,24(a3)
   10d98:	00d7b823          	sd	a3,16(a5) # ffffffff80000010 <_gp+0xffffffff7ffeace0>
   10d9c:	009404b3          	add	s1,s0,s1
   10da0:	02993423          	sd	s1,40(s2)
   10da4:	02993023          	sd	s1,32(s2)
   10da8:	00176793          	ori	a5,a4,1
   10dac:	0104bc23          	sd	a6,24(s1)
   10db0:	0104b823          	sd	a6,16(s1)
   10db4:	00f4b423          	sd	a5,8(s1)
   10db8:	00e484b3          	add	s1,s1,a4
   10dbc:	00098513          	mv	a0,s3
   10dc0:	00e4b023          	sd	a4,0(s1)
   10dc4:	099000ef          	jal	1165c <__malloc_unlock>
   10dc8:	01040513          	addi	a0,s0,16
   10dcc:	0680006f          	j	10e34 <_malloc_r+0x274>
   10dd0:	02000493          	li	s1,32
   10dd4:	08b4ea63          	bltu	s1,a1,10e68 <_malloc_r+0x2a8>
   10dd8:	081000ef          	jal	11658 <__malloc_lock>
   10ddc:	00a00793          	li	a5,10
   10de0:	00400693          	li	a3,4
   10de4:	00014937          	lui	s2,0x14
   10de8:	31890913          	addi	s2,s2,792 # 14318 <__malloc_av_>
   10dec:	00379793          	slli	a5,a5,0x3
   10df0:	00f907b3          	add	a5,s2,a5
   10df4:	0087b403          	ld	s0,8(a5)
   10df8:	ff078713          	addi	a4,a5,-16
   10dfc:	32e40063          	beq	s0,a4,1111c <_malloc_r+0x55c>
   10e00:	00843783          	ld	a5,8(s0)
   10e04:	01843683          	ld	a3,24(s0)
   10e08:	01043603          	ld	a2,16(s0)
   10e0c:	ffc7f793          	andi	a5,a5,-4
   10e10:	00f407b3          	add	a5,s0,a5
   10e14:	0087b703          	ld	a4,8(a5)
   10e18:	00d63c23          	sd	a3,24(a2)
   10e1c:	00c6b823          	sd	a2,16(a3)
   10e20:	00176713          	ori	a4,a4,1
   10e24:	00098513          	mv	a0,s3
   10e28:	00e7b423          	sd	a4,8(a5)
   10e2c:	031000ef          	jal	1165c <__malloc_unlock>
   10e30:	01040513          	addi	a0,s0,16
   10e34:	05813083          	ld	ra,88(sp)
   10e38:	05013403          	ld	s0,80(sp)
   10e3c:	04813483          	ld	s1,72(sp)
   10e40:	04013903          	ld	s2,64(sp)
   10e44:	03813983          	ld	s3,56(sp)
   10e48:	03013a03          	ld	s4,48(sp)
   10e4c:	02813a83          	ld	s5,40(sp)
   10e50:	02013b03          	ld	s6,32(sp)
   10e54:	01813b83          	ld	s7,24(sp)
   10e58:	01013c03          	ld	s8,16(sp)
   10e5c:	00813c83          	ld	s9,8(sp)
   10e60:	06010113          	addi	sp,sp,96
   10e64:	00008067          	ret
   10e68:	00c00793          	li	a5,12
   10e6c:	00f9a023          	sw	a5,0(s3)
   10e70:	00000513          	li	a0,0
   10e74:	fc1ff06f          	j	10e34 <_malloc_r+0x274>
   10e78:	00400713          	li	a4,4
   10e7c:	1ef76463          	bltu	a4,a5,11064 <_malloc_r+0x4a4>
   10e80:	0064d593          	srli	a1,s1,0x6
   10e84:	0005859b          	sext.w	a1,a1
   10e88:	0395851b          	addiw	a0,a1,57
   10e8c:	0015169b          	slliw	a3,a0,0x1
   10e90:	0385859b          	addiw	a1,a1,56
   10e94:	da1ff06f          	j	10c34 <_malloc_r+0x74>
   10e98:	00050693          	mv	a3,a0
   10e9c:	de9ff06f          	j	10c84 <_malloc_r+0xc4>
   10ea0:	01843683          	ld	a3,24(s0)
   10ea4:	01043603          	ld	a2,16(s0)
   10ea8:	f69ff06f          	j	10e10 <_malloc_r+0x250>
   10eac:	00f407b3          	add	a5,s0,a5
   10eb0:	0087b703          	ld	a4,8(a5)
   10eb4:	00098513          	mv	a0,s3
   10eb8:	00176713          	ori	a4,a4,1
   10ebc:	00e7b423          	sd	a4,8(a5)
   10ec0:	79c000ef          	jal	1165c <__malloc_unlock>
   10ec4:	01040513          	addi	a0,s0,16
   10ec8:	f6dff06f          	j	10e34 <_malloc_r+0x274>
   10ecc:	01093403          	ld	s0,16(s2)
   10ed0:	00843703          	ld	a4,8(s0)
   10ed4:	ffc77b93          	andi	s7,a4,-4
   10ed8:	009be863          	bltu	s7,s1,10ee8 <_malloc_r+0x328>
   10edc:	409b87b3          	sub	a5,s7,s1
   10ee0:	01f00713          	li	a4,31
   10ee4:	14f74c63          	blt	a4,a5,1103c <_malloc_r+0x47c>
   10ee8:	8501b783          	ld	a5,-1968(gp) # 14b80 <__malloc_top_pad>
   10eec:	8181b683          	ld	a3,-2024(gp) # 14b48 <__malloc_sbrk_base>
   10ef0:	fff00713          	li	a4,-1
   10ef4:	00f487b3          	add	a5,s1,a5
   10ef8:	01740a33          	add	s4,s0,s7
   10efc:	02078b13          	addi	s6,a5,32
   10f00:	00e68c63          	beq	a3,a4,10f18 <_malloc_r+0x358>
   10f04:	00001b37          	lui	s6,0x1
   10f08:	01fb0b13          	addi	s6,s6,31 # 101f <_ftext-0xefe1>
   10f0c:	01678b33          	add	s6,a5,s6
   10f10:	fffff7b7          	lui	a5,0xfffff
   10f14:	00fb7b33          	and	s6,s6,a5
   10f18:	000b0513          	mv	a0,s6
   10f1c:	260020ef          	jal	1317c <sbrk>
   10f20:	fff00793          	li	a5,-1
   10f24:	00050a93          	mv	s5,a0
   10f28:	26f50263          	beq	a0,a5,1118c <_malloc_r+0x5cc>
   10f2c:	25456e63          	bltu	a0,s4,11188 <_malloc_r+0x5c8>
   10f30:	89818c13          	addi	s8,gp,-1896 # 14bc8 <__malloc_current_mallinfo>
   10f34:	000c2783          	lw	a5,0(s8)
   10f38:	00fb07bb          	addw	a5,s6,a5
   10f3c:	00fc2023          	sw	a5,0(s8)
   10f40:	355a0463          	beq	s4,s5,11288 <_malloc_r+0x6c8>
   10f44:	8181b683          	ld	a3,-2024(gp) # 14b48 <__malloc_sbrk_base>
   10f48:	fff00713          	li	a4,-1
   10f4c:	36e68263          	beq	a3,a4,112b0 <_malloc_r+0x6f0>
   10f50:	414a8a33          	sub	s4,s5,s4
   10f54:	00fa07bb          	addw	a5,s4,a5
   10f58:	00fc2023          	sw	a5,0(s8)
   10f5c:	00faf713          	andi	a4,s5,15
   10f60:	000017b7          	lui	a5,0x1
   10f64:	00070a63          	beqz	a4,10f78 <_malloc_r+0x3b8>
   10f68:	40ea8ab3          	sub	s5,s5,a4
   10f6c:	01078a13          	addi	s4,a5,16 # 1010 <_ftext-0xeff0>
   10f70:	010a8a93          	addi	s5,s5,16
   10f74:	40ea07b3          	sub	a5,s4,a4
   10f78:	00001a37          	lui	s4,0x1
   10f7c:	fffa0a13          	addi	s4,s4,-1 # fff <_ftext-0xf001>
   10f80:	016a8b33          	add	s6,s5,s6
   10f84:	014b7b33          	and	s6,s6,s4
   10f88:	41678a33          	sub	s4,a5,s6
   10f8c:	000a0513          	mv	a0,s4
   10f90:	1ec020ef          	jal	1317c <sbrk>
   10f94:	fff00793          	li	a5,-1
   10f98:	30f50663          	beq	a0,a5,112a4 <_malloc_r+0x6e4>
   10f9c:	41550733          	sub	a4,a0,s5
   10fa0:	01470733          	add	a4,a4,s4
   10fa4:	00176713          	ori	a4,a4,1
   10fa8:	000a0a1b          	sext.w	s4,s4
   10fac:	000c2783          	lw	a5,0(s8)
   10fb0:	01593823          	sd	s5,16(s2)
   10fb4:	00eab423          	sd	a4,8(s5)
   10fb8:	00fa07bb          	addw	a5,s4,a5
   10fbc:	00fc2023          	sw	a5,0(s8)
   10fc0:	03240c63          	beq	s0,s2,10ff8 <_malloc_r+0x438>
   10fc4:	01f00613          	li	a2,31
   10fc8:	27767463          	bleu	s7,a2,11230 <_malloc_r+0x670>
   10fcc:	00843683          	ld	a3,8(s0)
   10fd0:	fe8b8713          	addi	a4,s7,-24 # ffffffff7fffffe8 <_gp+0xffffffff7ffeacb8>
   10fd4:	ff077713          	andi	a4,a4,-16
   10fd8:	0016f693          	andi	a3,a3,1
   10fdc:	00e6e6b3          	or	a3,a3,a4
   10fe0:	00d43423          	sd	a3,8(s0)
   10fe4:	00900593          	li	a1,9
   10fe8:	00e406b3          	add	a3,s0,a4
   10fec:	00b6b423          	sd	a1,8(a3)
   10ff0:	00b6b823          	sd	a1,16(a3)
   10ff4:	2ce66263          	bltu	a2,a4,112b8 <_malloc_r+0x6f8>
   10ff8:	8481b683          	ld	a3,-1976(gp) # 14b78 <__malloc_max_sbrked_mem>
   10ffc:	00f6f463          	bleu	a5,a3,11004 <_malloc_r+0x444>
   11000:	84f1b423          	sd	a5,-1976(gp) # 14b78 <__malloc_max_sbrked_mem>
   11004:	8401b683          	ld	a3,-1984(gp) # 14b70 <__malloc_max_total_mem>
   11008:	01093403          	ld	s0,16(s2)
   1100c:	00f6f463          	bleu	a5,a3,11014 <_malloc_r+0x454>
   11010:	84f1b023          	sd	a5,-1984(gp) # 14b70 <__malloc_max_total_mem>
   11014:	00843703          	ld	a4,8(s0)
   11018:	ffc77713          	andi	a4,a4,-4
   1101c:	409707b3          	sub	a5,a4,s1
   11020:	00976663          	bltu	a4,s1,1102c <_malloc_r+0x46c>
   11024:	01f00713          	li	a4,31
   11028:	00f74a63          	blt	a4,a5,1103c <_malloc_r+0x47c>
   1102c:	00098513          	mv	a0,s3
   11030:	62c000ef          	jal	1165c <__malloc_unlock>
   11034:	00000513          	li	a0,0
   11038:	dfdff06f          	j	10e34 <_malloc_r+0x274>
   1103c:	0014e713          	ori	a4,s1,1
   11040:	00e43423          	sd	a4,8(s0)
   11044:	009404b3          	add	s1,s0,s1
   11048:	00993823          	sd	s1,16(s2)
   1104c:	0017e793          	ori	a5,a5,1
   11050:	00098513          	mv	a0,s3
   11054:	00f4b423          	sd	a5,8(s1)
   11058:	604000ef          	jal	1165c <__malloc_unlock>
   1105c:	01040513          	addi	a0,s0,16
   11060:	dd5ff06f          	j	10e34 <_malloc_r+0x274>
   11064:	01400713          	li	a4,20
   11068:	0ef77a63          	bleu	a5,a4,1115c <_malloc_r+0x59c>
   1106c:	05400713          	li	a4,84
   11070:	18f76063          	bltu	a4,a5,111f0 <_malloc_r+0x630>
   11074:	00c4d593          	srli	a1,s1,0xc
   11078:	0005859b          	sext.w	a1,a1
   1107c:	06f5851b          	addiw	a0,a1,111
   11080:	0015169b          	slliw	a3,a0,0x1
   11084:	06e5859b          	addiw	a1,a1,110
   11088:	badff06f          	j	10c34 <_malloc_r+0x74>
   1108c:	0097d713          	srli	a4,a5,0x9
   11090:	00400613          	li	a2,4
   11094:	0ce67e63          	bleu	a4,a2,11170 <_malloc_r+0x5b0>
   11098:	01400613          	li	a2,20
   1109c:	1ce66663          	bltu	a2,a4,11268 <_malloc_r+0x6a8>
   110a0:	0007071b          	sext.w	a4,a4
   110a4:	05c7059b          	addiw	a1,a4,92
   110a8:	05b7061b          	addiw	a2,a4,91
   110ac:	0015959b          	slliw	a1,a1,0x1
   110b0:	00359593          	slli	a1,a1,0x3
   110b4:	00b905b3          	add	a1,s2,a1
   110b8:	0005b703          	ld	a4,0(a1)
   110bc:	ff058593          	addi	a1,a1,-16
   110c0:	14e58863          	beq	a1,a4,11210 <_malloc_r+0x650>
   110c4:	00873603          	ld	a2,8(a4)
   110c8:	ffc67613          	andi	a2,a2,-4
   110cc:	00c7f663          	bleu	a2,a5,110d8 <_malloc_r+0x518>
   110d0:	01073703          	ld	a4,16(a4)
   110d4:	fee598e3          	bne	a1,a4,110c4 <_malloc_r+0x504>
   110d8:	01873583          	ld	a1,24(a4)
   110dc:	00893783          	ld	a5,8(s2)
   110e0:	00b43c23          	sd	a1,24(s0)
   110e4:	00e43823          	sd	a4,16(s0)
   110e8:	0085b823          	sd	s0,16(a1)
   110ec:	00873c23          	sd	s0,24(a4)
   110f0:	c11ff06f          	j	10d00 <_malloc_r+0x140>
   110f4:	0014e793          	ori	a5,s1,1
   110f8:	00f43423          	sd	a5,8(s0)
   110fc:	ca1ff06f          	j	10d9c <_malloc_r+0x1dc>
   11100:	00893783          	ld	a5,8(s2)
   11104:	bfdff06f          	j	10d00 <_malloc_r+0x140>
   11108:	0013031b          	addiw	t1,t1,1
   1110c:	00337793          	andi	a5,t1,3
   11110:	01058593          	addi	a1,a1,16
   11114:	c40794e3          	bnez	a5,10d5c <_malloc_r+0x19c>
   11118:	0900006f          	j	111a8 <_malloc_r+0x5e8>
   1111c:	0187b403          	ld	s0,24(a5)
   11120:	0026869b          	addiw	a3,a3,2
   11124:	b68780e3          	beq	a5,s0,10c84 <_malloc_r+0xc4>
   11128:	cd9ff06f          	j	10e00 <_malloc_r+0x240>
   1112c:	00f407b3          	add	a5,s0,a5
   11130:	0087b703          	ld	a4,8(a5)
   11134:	01843683          	ld	a3,24(s0)
   11138:	01043603          	ld	a2,16(s0)
   1113c:	00176713          	ori	a4,a4,1
   11140:	00e7b423          	sd	a4,8(a5)
   11144:	00d63c23          	sd	a3,24(a2)
   11148:	00098513          	mv	a0,s3
   1114c:	00c6b823          	sd	a2,16(a3)
   11150:	50c000ef          	jal	1165c <__malloc_unlock>
   11154:	01040513          	addi	a0,s0,16
   11158:	cddff06f          	j	10e34 <_malloc_r+0x274>
   1115c:	0007879b          	sext.w	a5,a5
   11160:	05c7851b          	addiw	a0,a5,92
   11164:	05b7859b          	addiw	a1,a5,91
   11168:	0015169b          	slliw	a3,a0,0x1
   1116c:	ac9ff06f          	j	10c34 <_malloc_r+0x74>
   11170:	0067d713          	srli	a4,a5,0x6
   11174:	0007071b          	sext.w	a4,a4
   11178:	0397059b          	addiw	a1,a4,57
   1117c:	0387061b          	addiw	a2,a4,56
   11180:	0015959b          	slliw	a1,a1,0x1
   11184:	f2dff06f          	j	110b0 <_malloc_r+0x4f0>
   11188:	db2404e3          	beq	s0,s2,10f30 <_malloc_r+0x370>
   1118c:	01093403          	ld	s0,16(s2)
   11190:	00843703          	ld	a4,8(s0)
   11194:	ffc77713          	andi	a4,a4,-4
   11198:	e85ff06f          	j	1101c <_malloc_r+0x45c>
   1119c:	0108b783          	ld	a5,16(a7)
   111a0:	fff6869b          	addiw	a3,a3,-1
   111a4:	16f89863          	bne	a7,a5,11314 <_malloc_r+0x754>
   111a8:	0036f793          	andi	a5,a3,3
   111ac:	ff088893          	addi	a7,a7,-16
   111b0:	fe0796e3          	bnez	a5,1119c <_malloc_r+0x5dc>
   111b4:	00893783          	ld	a5,8(s2)
   111b8:	fff64713          	not	a4,a2
   111bc:	00f777b3          	and	a5,a4,a5
   111c0:	00f93423          	sd	a5,8(s2)
   111c4:	00161613          	slli	a2,a2,0x1
   111c8:	d0c7e2e3          	bltu	a5,a2,10ecc <_malloc_r+0x30c>
   111cc:	d00600e3          	beqz	a2,10ecc <_malloc_r+0x30c>
   111d0:	00f67733          	and	a4,a2,a5
   111d4:	00030693          	mv	a3,t1
   111d8:	b60714e3          	bnez	a4,10d40 <_malloc_r+0x180>
   111dc:	00161613          	slli	a2,a2,0x1
   111e0:	00f67733          	and	a4,a2,a5
   111e4:	0046869b          	addiw	a3,a3,4
   111e8:	fe070ae3          	beqz	a4,111dc <_malloc_r+0x61c>
   111ec:	b55ff06f          	j	10d40 <_malloc_r+0x180>
   111f0:	15400713          	li	a4,340
   111f4:	04f76463          	bltu	a4,a5,1123c <_malloc_r+0x67c>
   111f8:	00f4d593          	srli	a1,s1,0xf
   111fc:	0005859b          	sext.w	a1,a1
   11200:	0785851b          	addiw	a0,a1,120
   11204:	0015169b          	slliw	a3,a0,0x1
   11208:	0775859b          	addiw	a1,a1,119
   1120c:	a29ff06f          	j	10c34 <_malloc_r+0x74>
   11210:	00893783          	ld	a5,8(s2)
   11214:	4026571b          	sraiw	a4,a2,0x2
   11218:	00100613          	li	a2,1
   1121c:	00e61733          	sll	a4,a2,a4
   11220:	00f767b3          	or	a5,a4,a5
   11224:	00f93423          	sd	a5,8(s2)
   11228:	00058713          	mv	a4,a1
   1122c:	eb5ff06f          	j	110e0 <_malloc_r+0x520>
   11230:	00100793          	li	a5,1
   11234:	00fab423          	sd	a5,8(s5)
   11238:	df5ff06f          	j	1102c <_malloc_r+0x46c>
   1123c:	55400713          	li	a4,1364
   11240:	0fe00693          	li	a3,254
   11244:	07f00513          	li	a0,127
   11248:	07e00593          	li	a1,126
   1124c:	9ef764e3          	bltu	a4,a5,10c34 <_malloc_r+0x74>
   11250:	0124d593          	srli	a1,s1,0x12
   11254:	0005859b          	sext.w	a1,a1
   11258:	07d5851b          	addiw	a0,a1,125
   1125c:	0015169b          	slliw	a3,a0,0x1
   11260:	07c5859b          	addiw	a1,a1,124
   11264:	9d1ff06f          	j	10c34 <_malloc_r+0x74>
   11268:	05400613          	li	a2,84
   1126c:	06e66063          	bltu	a2,a4,112cc <_malloc_r+0x70c>
   11270:	00c7d713          	srli	a4,a5,0xc
   11274:	0007071b          	sext.w	a4,a4
   11278:	06f7059b          	addiw	a1,a4,111
   1127c:	06e7061b          	addiw	a2,a4,110
   11280:	0015959b          	slliw	a1,a1,0x1
   11284:	e2dff06f          	j	110b0 <_malloc_r+0x4f0>
   11288:	034a1713          	slli	a4,s4,0x34
   1128c:	ca071ce3          	bnez	a4,10f44 <_malloc_r+0x384>
   11290:	01093683          	ld	a3,16(s2)
   11294:	016b8733          	add	a4,s7,s6
   11298:	00176713          	ori	a4,a4,1
   1129c:	00e6b423          	sd	a4,8(a3)
   112a0:	d59ff06f          	j	10ff8 <_malloc_r+0x438>
   112a4:	00100713          	li	a4,1
   112a8:	00000a13          	li	s4,0
   112ac:	d01ff06f          	j	10fac <_malloc_r+0x3ec>
   112b0:	8151bc23          	sd	s5,-2024(gp) # 14b48 <__malloc_sbrk_base>
   112b4:	ca9ff06f          	j	10f5c <_malloc_r+0x39c>
   112b8:	01040593          	addi	a1,s0,16
   112bc:	00098513          	mv	a0,s3
   112c0:	1f0010ef          	jal	124b0 <_free_r>
   112c4:	000c2783          	lw	a5,0(s8)
   112c8:	d31ff06f          	j	10ff8 <_malloc_r+0x438>
   112cc:	15400613          	li	a2,340
   112d0:	00e66e63          	bltu	a2,a4,112ec <_malloc_r+0x72c>
   112d4:	00f7d713          	srli	a4,a5,0xf
   112d8:	0007071b          	sext.w	a4,a4
   112dc:	0787059b          	addiw	a1,a4,120
   112e0:	0777061b          	addiw	a2,a4,119
   112e4:	0015959b          	slliw	a1,a1,0x1
   112e8:	dc9ff06f          	j	110b0 <_malloc_r+0x4f0>
   112ec:	55400513          	li	a0,1364
   112f0:	0fe00593          	li	a1,254
   112f4:	07e00613          	li	a2,126
   112f8:	dae56ce3          	bltu	a0,a4,110b0 <_malloc_r+0x4f0>
   112fc:	0127d713          	srli	a4,a5,0x12
   11300:	0007071b          	sext.w	a4,a4
   11304:	07d7059b          	addiw	a1,a4,125
   11308:	07c7061b          	addiw	a2,a4,124
   1130c:	0015959b          	slliw	a1,a1,0x1
   11310:	da1ff06f          	j	110b0 <_malloc_r+0x4f0>
   11314:	00893783          	ld	a5,8(s2)
   11318:	eadff06f          	j	111c4 <_malloc_r+0x604>
   1131c:	0034d693          	srli	a3,s1,0x3
   11320:	0006869b          	sext.w	a3,a3
   11324:	0016879b          	addiw	a5,a3,1
   11328:	0017979b          	slliw	a5,a5,0x1
   1132c:	ab9ff06f          	j	10de4 <_malloc_r+0x224>

0000000000011330 <memchr>:
   11330:	00757793          	andi	a5,a0,7
   11334:	0ff5f813          	andi	a6,a1,255
   11338:	0c078c63          	beqz	a5,11410 <memchr+0xe0>
   1133c:	fff60793          	addi	a5,a2,-1
   11340:	06060463          	beqz	a2,113a8 <memchr+0x78>
   11344:	00054703          	lbu	a4,0(a0)
   11348:	07070263          	beq	a4,a6,113ac <memchr+0x7c>
   1134c:	00080693          	mv	a3,a6
   11350:	0140006f          	j	11364 <memchr+0x34>
   11354:	04078a63          	beqz	a5,113a8 <memchr+0x78>
   11358:	00054703          	lbu	a4,0(a0)
   1135c:	fff78793          	addi	a5,a5,-1
   11360:	04d70663          	beq	a4,a3,113ac <memchr+0x7c>
   11364:	00150513          	addi	a0,a0,1
   11368:	00757713          	andi	a4,a0,7
   1136c:	fe0714e3          	bnez	a4,11354 <memchr+0x24>
   11370:	00700693          	li	a3,7
   11374:	02f6ee63          	bltu	a3,a5,113b0 <memchr+0x80>
   11378:	02078863          	beqz	a5,113a8 <memchr+0x78>
   1137c:	00054703          	lbu	a4,0(a0)
   11380:	03070663          	beq	a4,a6,113ac <memchr+0x7c>
   11384:	00150713          	addi	a4,a0,1
   11388:	00f507b3          	add	a5,a0,a5
   1138c:	00080613          	mv	a2,a6
   11390:	0100006f          	j	113a0 <memchr+0x70>
   11394:	00170713          	addi	a4,a4,1
   11398:	fff74683          	lbu	a3,-1(a4)
   1139c:	00c68863          	beq	a3,a2,113ac <memchr+0x7c>
   113a0:	00070513          	mv	a0,a4
   113a4:	fee798e3          	bne	a5,a4,11394 <memchr+0x64>
   113a8:	00000513          	li	a0,0
   113ac:	00008067          	ret
   113b0:	0ff5f593          	andi	a1,a1,255
   113b4:	0085971b          	slliw	a4,a1,0x8
   113b8:	00b765b3          	or	a1,a4,a1
   113bc:	00058713          	mv	a4,a1
   113c0:	01071613          	slli	a2,a4,0x10
   113c4:	00c76733          	or	a4,a4,a2
   113c8:	00015637          	lui	a2,0x15
   113cc:	b6063303          	ld	t1,-1184(a2) # 14b60 <__malloc_trim_threshold+0x10>
   113d0:	00015637          	lui	a2,0x15
   113d4:	b6863883          	ld	a7,-1176(a2) # 14b68 <__malloc_trim_threshold+0x18>
   113d8:	02071613          	slli	a2,a4,0x20
   113dc:	00e66633          	or	a2,a2,a4
   113e0:	00068593          	mv	a1,a3
   113e4:	00053703          	ld	a4,0(a0)
   113e8:	00e64733          	xor	a4,a2,a4
   113ec:	006706b3          	add	a3,a4,t1
   113f0:	fff74713          	not	a4,a4
   113f4:	00e6f733          	and	a4,a3,a4
   113f8:	01177733          	and	a4,a4,a7
   113fc:	f80710e3          	bnez	a4,1137c <memchr+0x4c>
   11400:	ff878793          	addi	a5,a5,-8
   11404:	00850513          	addi	a0,a0,8
   11408:	fcf5eee3          	bltu	a1,a5,113e4 <memchr+0xb4>
   1140c:	f6dff06f          	j	11378 <memchr+0x48>
   11410:	00060793          	mv	a5,a2
   11414:	f5dff06f          	j	11370 <memchr+0x40>

0000000000011418 <memcpy>:
   11418:	00a5c7b3          	xor	a5,a1,a0
   1141c:	0077f793          	andi	a5,a5,7
   11420:	00c508b3          	add	a7,a0,a2
   11424:	0e079263          	bnez	a5,11508 <memcpy+0xf0>
   11428:	00700793          	li	a5,7
   1142c:	0ec7fe63          	bleu	a2,a5,11528 <memcpy+0x110>
   11430:	00757793          	andi	a5,a0,7
   11434:	04079a63          	bnez	a5,11488 <memcpy+0x70>
   11438:	ff88f813          	andi	a6,a7,-8
   1143c:	fc080793          	addi	a5,a6,-64
   11440:	00050713          	mv	a4,a0
   11444:	06f56663          	bltu	a0,a5,114b0 <memcpy+0x98>
   11448:	00058693          	mv	a3,a1
   1144c:	00070793          	mv	a5,a4
   11450:	03077863          	bleu	a6,a4,11480 <memcpy+0x68>
   11454:	0006b603          	ld	a2,0(a3)
   11458:	00878793          	addi	a5,a5,8
   1145c:	00868693          	addi	a3,a3,8
   11460:	fec7bc23          	sd	a2,-8(a5)
   11464:	ff07e8e3          	bltu	a5,a6,11454 <memcpy+0x3c>
   11468:	fff74793          	not	a5,a4
   1146c:	01078833          	add	a6,a5,a6
   11470:	ff887813          	andi	a6,a6,-8
   11474:	00880813          	addi	a6,a6,8
   11478:	01070733          	add	a4,a4,a6
   1147c:	010585b3          	add	a1,a1,a6
   11480:	09176863          	bltu	a4,a7,11510 <memcpy+0xf8>
   11484:	00008067          	ret
   11488:	00050713          	mv	a4,a0
   1148c:	0005c683          	lbu	a3,0(a1)
   11490:	00170713          	addi	a4,a4,1
   11494:	00777793          	andi	a5,a4,7
   11498:	fed70fa3          	sb	a3,-1(a4)
   1149c:	00158593          	addi	a1,a1,1
   114a0:	fe0796e3          	bnez	a5,1148c <memcpy+0x74>
   114a4:	ff88f813          	andi	a6,a7,-8
   114a8:	fc080793          	addi	a5,a6,-64
   114ac:	f8f77ee3          	bleu	a5,a4,11448 <memcpy+0x30>
   114b0:	0005b383          	ld	t2,0(a1)
   114b4:	0085b283          	ld	t0,8(a1)
   114b8:	0105bf83          	ld	t6,16(a1)
   114bc:	0185bf03          	ld	t5,24(a1)
   114c0:	0205be83          	ld	t4,32(a1)
   114c4:	0285be03          	ld	t3,40(a1)
   114c8:	0305b303          	ld	t1,48(a1)
   114cc:	0385b603          	ld	a2,56(a1)
   114d0:	04858593          	addi	a1,a1,72
   114d4:	04870713          	addi	a4,a4,72
   114d8:	ff85b683          	ld	a3,-8(a1)
   114dc:	fa773c23          	sd	t2,-72(a4)
   114e0:	fc573023          	sd	t0,-64(a4)
   114e4:	fdf73423          	sd	t6,-56(a4)
   114e8:	fde73823          	sd	t5,-48(a4)
   114ec:	fdd73c23          	sd	t4,-40(a4)
   114f0:	ffc73023          	sd	t3,-32(a4)
   114f4:	fe673423          	sd	t1,-24(a4)
   114f8:	fec73823          	sd	a2,-16(a4)
   114fc:	fed73c23          	sd	a3,-8(a4)
   11500:	faf768e3          	bltu	a4,a5,114b0 <memcpy+0x98>
   11504:	f45ff06f          	j	11448 <memcpy+0x30>
   11508:	00050713          	mv	a4,a0
   1150c:	03157463          	bleu	a7,a0,11534 <memcpy+0x11c>
   11510:	0005c783          	lbu	a5,0(a1)
   11514:	00170713          	addi	a4,a4,1
   11518:	00158593          	addi	a1,a1,1
   1151c:	fef70fa3          	sb	a5,-1(a4)
   11520:	ff1768e3          	bltu	a4,a7,11510 <memcpy+0xf8>
   11524:	00008067          	ret
   11528:	00050713          	mv	a4,a0
   1152c:	ff1562e3          	bltu	a0,a7,11510 <memcpy+0xf8>
   11530:	f55ff06f          	j	11484 <memcpy+0x6c>
   11534:	00008067          	ret

0000000000011538 <memmove>:
   11538:	02a5f863          	bleu	a0,a1,11568 <memmove+0x30>
   1153c:	00c58733          	add	a4,a1,a2
   11540:	02e57463          	bleu	a4,a0,11568 <memmove+0x30>
   11544:	00c507b3          	add	a5,a0,a2
   11548:	40c785b3          	sub	a1,a5,a2
   1154c:	0e060263          	beqz	a2,11630 <memmove+0xf8>
   11550:	fff70713          	addi	a4,a4,-1
   11554:	00074683          	lbu	a3,0(a4)
   11558:	fff78793          	addi	a5,a5,-1
   1155c:	00d78023          	sb	a3,0(a5)
   11560:	fef598e3          	bne	a1,a5,11550 <memmove+0x18>
   11564:	00008067          	ret
   11568:	01f00893          	li	a7,31
   1156c:	0cc8f463          	bleu	a2,a7,11634 <memmove+0xfc>
   11570:	00a5e7b3          	or	a5,a1,a0
   11574:	0077f793          	andi	a5,a5,7
   11578:	0c079463          	bnez	a5,11640 <memmove+0x108>
   1157c:	00058713          	mv	a4,a1
   11580:	00050793          	mv	a5,a0
   11584:	00060693          	mv	a3,a2
   11588:	00073803          	ld	a6,0(a4)
   1158c:	02078793          	addi	a5,a5,32
   11590:	02070713          	addi	a4,a4,32
   11594:	ff07b023          	sd	a6,-32(a5)
   11598:	fe873803          	ld	a6,-24(a4)
   1159c:	fe068693          	addi	a3,a3,-32
   115a0:	ff07b423          	sd	a6,-24(a5)
   115a4:	ff073803          	ld	a6,-16(a4)
   115a8:	ff07b823          	sd	a6,-16(a5)
   115ac:	ff873803          	ld	a6,-8(a4)
   115b0:	ff07bc23          	sd	a6,-8(a5)
   115b4:	fcd8eae3          	bltu	a7,a3,11588 <memmove+0x50>
   115b8:	fe060713          	addi	a4,a2,-32
   115bc:	fe077713          	andi	a4,a4,-32
   115c0:	02070713          	addi	a4,a4,32
   115c4:	01f67e13          	andi	t3,a2,31
   115c8:	00700313          	li	t1,7
   115cc:	00e507b3          	add	a5,a0,a4
   115d0:	00e585b3          	add	a1,a1,a4
   115d4:	07c37c63          	bleu	t3,t1,1164c <memmove+0x114>
   115d8:	00058813          	mv	a6,a1
   115dc:	00078693          	mv	a3,a5
   115e0:	000e0713          	mv	a4,t3
   115e4:	00880813          	addi	a6,a6,8
   115e8:	ff883883          	ld	a7,-8(a6)
   115ec:	00868693          	addi	a3,a3,8
   115f0:	ff870713          	addi	a4,a4,-8
   115f4:	ff16bc23          	sd	a7,-8(a3)
   115f8:	fee366e3          	bltu	t1,a4,115e4 <memmove+0xac>
   115fc:	ff8e0713          	addi	a4,t3,-8
   11600:	ff877713          	andi	a4,a4,-8
   11604:	00870713          	addi	a4,a4,8
   11608:	00767613          	andi	a2,a2,7
   1160c:	00e787b3          	add	a5,a5,a4
   11610:	00e585b3          	add	a1,a1,a4
   11614:	02060a63          	beqz	a2,11648 <memmove+0x110>
   11618:	00c78633          	add	a2,a5,a2
   1161c:	00158593          	addi	a1,a1,1
   11620:	fff5c703          	lbu	a4,-1(a1)
   11624:	00178793          	addi	a5,a5,1
   11628:	fee78fa3          	sb	a4,-1(a5)
   1162c:	fec798e3          	bne	a5,a2,1161c <memmove+0xe4>
   11630:	00008067          	ret
   11634:	00050793          	mv	a5,a0
   11638:	fe0610e3          	bnez	a2,11618 <memmove+0xe0>
   1163c:	00c0006f          	j	11648 <memmove+0x110>
   11640:	00050793          	mv	a5,a0
   11644:	fd5ff06f          	j	11618 <memmove+0xe0>
   11648:	00008067          	ret
   1164c:	000e0613          	mv	a2,t3
   11650:	fc0614e3          	bnez	a2,11618 <memmove+0xe0>
   11654:	ff5ff06f          	j	11648 <memmove+0x110>

0000000000011658 <__malloc_lock>:
   11658:	00008067          	ret

000000000001165c <__malloc_unlock>:
   1165c:	00008067          	ret

0000000000011660 <_realloc_r>:
   11660:	fb010113          	addi	sp,sp,-80
   11664:	02913c23          	sd	s1,56(sp)
   11668:	04113423          	sd	ra,72(sp)
   1166c:	04813023          	sd	s0,64(sp)
   11670:	03213823          	sd	s2,48(sp)
   11674:	03313423          	sd	s3,40(sp)
   11678:	03413023          	sd	s4,32(sp)
   1167c:	01513c23          	sd	s5,24(sp)
   11680:	01613823          	sd	s6,16(sp)
   11684:	01713423          	sd	s7,8(sp)
   11688:	01813023          	sd	s8,0(sp)
   1168c:	00060493          	mv	s1,a2
   11690:	1c058a63          	beqz	a1,11864 <_realloc_r+0x204>
   11694:	00058993          	mv	s3,a1
   11698:	00050913          	mv	s2,a0
   1169c:	fbdff0ef          	jal	11658 <__malloc_lock>
   116a0:	ff89b783          	ld	a5,-8(s3)
   116a4:	01748413          	addi	s0,s1,23
   116a8:	02e00713          	li	a4,46
   116ac:	ff098a93          	addi	s5,s3,-16
   116b0:	ffc7fa13          	andi	s4,a5,-4
   116b4:	0c877463          	bleu	s0,a4,1177c <_realloc_r+0x11c>
   116b8:	80000737          	lui	a4,0x80000
   116bc:	ff047413          	andi	s0,s0,-16
   116c0:	fff74713          	not	a4,a4
   116c4:	14876a63          	bltu	a4,s0,11818 <_realloc_r+0x1b8>
   116c8:	14946863          	bltu	s0,s1,11818 <_realloc_r+0x1b8>
   116cc:	0a8a5c63          	ble	s0,s4,11784 <_realloc_r+0x124>
   116d0:	00014b37          	lui	s6,0x14
   116d4:	318b0b13          	addi	s6,s6,792 # 14318 <__malloc_av_>
   116d8:	010b3703          	ld	a4,16(s6)
   116dc:	014a86b3          	add	a3,s5,s4
   116e0:	2ee68e63          	beq	a3,a4,119dc <_realloc_r+0x37c>
   116e4:	0086b703          	ld	a4,8(a3)
   116e8:	ffe77613          	andi	a2,a4,-2
   116ec:	00c68633          	add	a2,a3,a2
   116f0:	00863603          	ld	a2,8(a2)
   116f4:	00167613          	andi	a2,a2,1
   116f8:	0e060c63          	beqz	a2,117f0 <_realloc_r+0x190>
   116fc:	0017f793          	andi	a5,a5,1
   11700:	26078063          	beqz	a5,11960 <_realloc_r+0x300>
   11704:	00048593          	mv	a1,s1
   11708:	00090513          	mv	a0,s2
   1170c:	cb4ff0ef          	jal	10bc0 <_malloc_r>
   11710:	00050493          	mv	s1,a0
   11714:	48050e63          	beqz	a0,11bb0 <_realloc_r+0x550>
   11718:	ff89b783          	ld	a5,-8(s3)
   1171c:	ff050713          	addi	a4,a0,-16
   11720:	ffe7f793          	andi	a5,a5,-2
   11724:	00fa87b3          	add	a5,s5,a5
   11728:	40f70e63          	beq	a4,a5,11b44 <_realloc_r+0x4e4>
   1172c:	ff8a0613          	addi	a2,s4,-8
   11730:	04800793          	li	a5,72
   11734:	3ec7e263          	bltu	a5,a2,11b18 <_realloc_r+0x4b8>
   11738:	02700713          	li	a4,39
   1173c:	36c76663          	bltu	a4,a2,11aa8 <_realloc_r+0x448>
   11740:	00050793          	mv	a5,a0
   11744:	00098713          	mv	a4,s3
   11748:	00073683          	ld	a3,0(a4) # ffffffff80000000 <_gp+0xffffffff7ffeacd0>
   1174c:	00d7b023          	sd	a3,0(a5)
   11750:	00873683          	ld	a3,8(a4)
   11754:	00d7b423          	sd	a3,8(a5)
   11758:	01073703          	ld	a4,16(a4)
   1175c:	00e7b823          	sd	a4,16(a5)
   11760:	00098593          	mv	a1,s3
   11764:	00090513          	mv	a0,s2
   11768:	549000ef          	jal	124b0 <_free_r>
   1176c:	00090513          	mv	a0,s2
   11770:	eedff0ef          	jal	1165c <__malloc_unlock>
   11774:	00048513          	mv	a0,s1
   11778:	0480006f          	j	117c0 <_realloc_r+0x160>
   1177c:	02000413          	li	s0,32
   11780:	f49ff06f          	j	116c8 <_realloc_r+0x68>
   11784:	00098493          	mv	s1,s3
   11788:	408a07b3          	sub	a5,s4,s0
   1178c:	01f00713          	li	a4,31
   11790:	08f76c63          	bltu	a4,a5,11828 <_realloc_r+0x1c8>
   11794:	008ab783          	ld	a5,8(s5)
   11798:	014a8733          	add	a4,s5,s4
   1179c:	0017f793          	andi	a5,a5,1
   117a0:	0147e633          	or	a2,a5,s4
   117a4:	00cab423          	sd	a2,8(s5)
   117a8:	00873783          	ld	a5,8(a4)
   117ac:	0017e793          	ori	a5,a5,1
   117b0:	00f73423          	sd	a5,8(a4)
   117b4:	00090513          	mv	a0,s2
   117b8:	ea5ff0ef          	jal	1165c <__malloc_unlock>
   117bc:	00048513          	mv	a0,s1
   117c0:	04813083          	ld	ra,72(sp)
   117c4:	04013403          	ld	s0,64(sp)
   117c8:	03813483          	ld	s1,56(sp)
   117cc:	03013903          	ld	s2,48(sp)
   117d0:	02813983          	ld	s3,40(sp)
   117d4:	02013a03          	ld	s4,32(sp)
   117d8:	01813a83          	ld	s5,24(sp)
   117dc:	01013b03          	ld	s6,16(sp)
   117e0:	00813b83          	ld	s7,8(sp)
   117e4:	00013c03          	ld	s8,0(sp)
   117e8:	05010113          	addi	sp,sp,80
   117ec:	00008067          	ret
   117f0:	ffc77713          	andi	a4,a4,-4
   117f4:	01470733          	add	a4,a4,s4
   117f8:	0a874063          	blt	a4,s0,11898 <_realloc_r+0x238>
   117fc:	0186b783          	ld	a5,24(a3)
   11800:	0106b683          	ld	a3,16(a3)
   11804:	00098493          	mv	s1,s3
   11808:	00070a13          	mv	s4,a4
   1180c:	00f6bc23          	sd	a5,24(a3)
   11810:	00d7b823          	sd	a3,16(a5)
   11814:	f75ff06f          	j	11788 <_realloc_r+0x128>
   11818:	00c00793          	li	a5,12
   1181c:	00f92023          	sw	a5,0(s2)
   11820:	00000513          	li	a0,0
   11824:	f9dff06f          	j	117c0 <_realloc_r+0x160>
   11828:	008ab703          	ld	a4,8(s5)
   1182c:	008a85b3          	add	a1,s5,s0
   11830:	0017e693          	ori	a3,a5,1
   11834:	00177713          	andi	a4,a4,1
   11838:	00876433          	or	s0,a4,s0
   1183c:	008ab423          	sd	s0,8(s5)
   11840:	00d5b423          	sd	a3,8(a1)
   11844:	00f587b3          	add	a5,a1,a5
   11848:	0087b703          	ld	a4,8(a5)
   1184c:	01058593          	addi	a1,a1,16
   11850:	00090513          	mv	a0,s2
   11854:	00176713          	ori	a4,a4,1
   11858:	00e7b423          	sd	a4,8(a5)
   1185c:	455000ef          	jal	124b0 <_free_r>
   11860:	f55ff06f          	j	117b4 <_realloc_r+0x154>
   11864:	04813083          	ld	ra,72(sp)
   11868:	04013403          	ld	s0,64(sp)
   1186c:	03813483          	ld	s1,56(sp)
   11870:	03013903          	ld	s2,48(sp)
   11874:	02813983          	ld	s3,40(sp)
   11878:	02013a03          	ld	s4,32(sp)
   1187c:	01813a83          	ld	s5,24(sp)
   11880:	01013b03          	ld	s6,16(sp)
   11884:	00813b83          	ld	s7,8(sp)
   11888:	00013c03          	ld	s8,0(sp)
   1188c:	00060593          	mv	a1,a2
   11890:	05010113          	addi	sp,sp,80
   11894:	b2cff06f          	j	10bc0 <_malloc_r>
   11898:	0017f793          	andi	a5,a5,1
   1189c:	e60794e3          	bnez	a5,11704 <_realloc_r+0xa4>
   118a0:	ff09bb83          	ld	s7,-16(s3)
   118a4:	417a8bb3          	sub	s7,s5,s7
   118a8:	008bb783          	ld	a5,8(s7)
   118ac:	ffc7f793          	andi	a5,a5,-4
   118b0:	00f70b33          	add	s6,a4,a5
   118b4:	0a8b4e63          	blt	s6,s0,11970 <_realloc_r+0x310>
   118b8:	0186b783          	ld	a5,24(a3)
   118bc:	0106b703          	ld	a4,16(a3)
   118c0:	ff8a0613          	addi	a2,s4,-8
   118c4:	010b8493          	addi	s1,s7,16
   118c8:	00f73c23          	sd	a5,24(a4)
   118cc:	00e7b823          	sd	a4,16(a5)
   118d0:	010bb703          	ld	a4,16(s7)
   118d4:	018bb783          	ld	a5,24(s7)
   118d8:	00f73c23          	sd	a5,24(a4)
   118dc:	00e7b823          	sd	a4,16(a5)
   118e0:	04800793          	li	a5,72
   118e4:	1ec7e463          	bltu	a5,a2,11acc <_realloc_r+0x46c>
   118e8:	02700713          	li	a4,39
   118ec:	00048793          	mv	a5,s1
   118f0:	04c77663          	bleu	a2,a4,1193c <_realloc_r+0x2dc>
   118f4:	0009b783          	ld	a5,0(s3)
   118f8:	00fbb823          	sd	a5,16(s7)
   118fc:	0089b783          	ld	a5,8(s3)
   11900:	00fbbc23          	sd	a5,24(s7)
   11904:	03700793          	li	a5,55
   11908:	24c7f863          	bleu	a2,a5,11b58 <_realloc_r+0x4f8>
   1190c:	0109b783          	ld	a5,16(s3)
   11910:	02fbb023          	sd	a5,32(s7)
   11914:	0189b783          	ld	a5,24(s3)
   11918:	02fbb423          	sd	a5,40(s7)
   1191c:	04800793          	li	a5,72
   11920:	0af61863          	bne	a2,a5,119d0 <_realloc_r+0x370>
   11924:	0209b703          	ld	a4,32(s3)
   11928:	040b8793          	addi	a5,s7,64
   1192c:	03098993          	addi	s3,s3,48
   11930:	02ebb823          	sd	a4,48(s7)
   11934:	ff89b703          	ld	a4,-8(s3)
   11938:	02ebbc23          	sd	a4,56(s7)
   1193c:	0009b703          	ld	a4,0(s3)
   11940:	000b0a13          	mv	s4,s6
   11944:	000b8a93          	mv	s5,s7
   11948:	00e7b023          	sd	a4,0(a5)
   1194c:	0089b703          	ld	a4,8(s3)
   11950:	00e7b423          	sd	a4,8(a5)
   11954:	0109b703          	ld	a4,16(s3)
   11958:	00e7b823          	sd	a4,16(a5)
   1195c:	e2dff06f          	j	11788 <_realloc_r+0x128>
   11960:	ff09bb83          	ld	s7,-16(s3)
   11964:	417a8bb3          	sub	s7,s5,s7
   11968:	008bb783          	ld	a5,8(s7)
   1196c:	ffc7f793          	andi	a5,a5,-4
   11970:	00fa0b33          	add	s6,s4,a5
   11974:	d88b48e3          	blt	s6,s0,11704 <_realloc_r+0xa4>
   11978:	018bb783          	ld	a5,24(s7)
   1197c:	010bb703          	ld	a4,16(s7)
   11980:	ff8a0613          	addi	a2,s4,-8
   11984:	04800693          	li	a3,72
   11988:	00f73c23          	sd	a5,24(a4)
   1198c:	00e7b823          	sd	a4,16(a5)
   11990:	010b8493          	addi	s1,s7,16
   11994:	12c6ec63          	bltu	a3,a2,11acc <_realloc_r+0x46c>
   11998:	02700713          	li	a4,39
   1199c:	00048793          	mv	a5,s1
   119a0:	f8c77ee3          	bleu	a2,a4,1193c <_realloc_r+0x2dc>
   119a4:	0009b783          	ld	a5,0(s3)
   119a8:	00fbb823          	sd	a5,16(s7)
   119ac:	0089b783          	ld	a5,8(s3)
   119b0:	00fbbc23          	sd	a5,24(s7)
   119b4:	03700793          	li	a5,55
   119b8:	1ac7f063          	bleu	a2,a5,11b58 <_realloc_r+0x4f8>
   119bc:	0109b783          	ld	a5,16(s3)
   119c0:	02fbb023          	sd	a5,32(s7)
   119c4:	0189b783          	ld	a5,24(s3)
   119c8:	02fbb423          	sd	a5,40(s7)
   119cc:	f4d60ce3          	beq	a2,a3,11924 <_realloc_r+0x2c4>
   119d0:	030b8793          	addi	a5,s7,48
   119d4:	02098993          	addi	s3,s3,32
   119d8:	f65ff06f          	j	1193c <_realloc_r+0x2dc>
   119dc:	0086b703          	ld	a4,8(a3)
   119e0:	02040693          	addi	a3,s0,32
   119e4:	ffc77713          	andi	a4,a4,-4
   119e8:	01470733          	add	a4,a4,s4
   119ec:	0ed75c63          	ble	a3,a4,11ae4 <_realloc_r+0x484>
   119f0:	0017f793          	andi	a5,a5,1
   119f4:	d00798e3          	bnez	a5,11704 <_realloc_r+0xa4>
   119f8:	ff09bb83          	ld	s7,-16(s3)
   119fc:	417a8bb3          	sub	s7,s5,s7
   11a00:	008bb783          	ld	a5,8(s7)
   11a04:	ffc7f793          	andi	a5,a5,-4
   11a08:	00e78c33          	add	s8,a5,a4
   11a0c:	f6dc42e3          	blt	s8,a3,11970 <_realloc_r+0x310>
   11a10:	018bb783          	ld	a5,24(s7)
   11a14:	010bb703          	ld	a4,16(s7)
   11a18:	ff8a0613          	addi	a2,s4,-8
   11a1c:	04800693          	li	a3,72
   11a20:	00f73c23          	sd	a5,24(a4)
   11a24:	00e7b823          	sd	a4,16(a5)
   11a28:	010b8493          	addi	s1,s7,16
   11a2c:	14c6ea63          	bltu	a3,a2,11b80 <_realloc_r+0x520>
   11a30:	02700713          	li	a4,39
   11a34:	00048793          	mv	a5,s1
   11a38:	02c77263          	bleu	a2,a4,11a5c <_realloc_r+0x3fc>
   11a3c:	0009b783          	ld	a5,0(s3)
   11a40:	00fbb823          	sd	a5,16(s7)
   11a44:	0089b783          	ld	a5,8(s3)
   11a48:	00fbbc23          	sd	a5,24(s7)
   11a4c:	03700793          	li	a5,55
   11a50:	14c7e063          	bltu	a5,a2,11b90 <_realloc_r+0x530>
   11a54:	020b8793          	addi	a5,s7,32
   11a58:	01098993          	addi	s3,s3,16
   11a5c:	0009b703          	ld	a4,0(s3)
   11a60:	00e7b023          	sd	a4,0(a5)
   11a64:	0089b703          	ld	a4,8(s3)
   11a68:	00e7b423          	sd	a4,8(a5)
   11a6c:	0109b703          	ld	a4,16(s3)
   11a70:	00e7b823          	sd	a4,16(a5)
   11a74:	008b8733          	add	a4,s7,s0
   11a78:	408c07b3          	sub	a5,s8,s0
   11a7c:	00eb3823          	sd	a4,16(s6)
   11a80:	0017e793          	ori	a5,a5,1
   11a84:	00f73423          	sd	a5,8(a4)
   11a88:	008bb783          	ld	a5,8(s7)
   11a8c:	00090513          	mv	a0,s2
   11a90:	0017f793          	andi	a5,a5,1
   11a94:	0087e433          	or	s0,a5,s0
   11a98:	008bb423          	sd	s0,8(s7)
   11a9c:	bc1ff0ef          	jal	1165c <__malloc_unlock>
   11aa0:	00048513          	mv	a0,s1
   11aa4:	d1dff06f          	j	117c0 <_realloc_r+0x160>
   11aa8:	0009b703          	ld	a4,0(s3)
   11aac:	00e53023          	sd	a4,0(a0)
   11ab0:	0089b703          	ld	a4,8(s3)
   11ab4:	00e53423          	sd	a4,8(a0)
   11ab8:	03700713          	li	a4,55
   11abc:	06c76463          	bltu	a4,a2,11b24 <_realloc_r+0x4c4>
   11ac0:	01050793          	addi	a5,a0,16
   11ac4:	01098713          	addi	a4,s3,16
   11ac8:	c81ff06f          	j	11748 <_realloc_r+0xe8>
   11acc:	00098593          	mv	a1,s3
   11ad0:	00048513          	mv	a0,s1
   11ad4:	a65ff0ef          	jal	11538 <memmove>
   11ad8:	000b0a13          	mv	s4,s6
   11adc:	000b8a93          	mv	s5,s7
   11ae0:	ca9ff06f          	j	11788 <_realloc_r+0x128>
   11ae4:	008a8ab3          	add	s5,s5,s0
   11ae8:	408707b3          	sub	a5,a4,s0
   11aec:	015b3823          	sd	s5,16(s6)
   11af0:	0017e793          	ori	a5,a5,1
   11af4:	00fab423          	sd	a5,8(s5)
   11af8:	ff89b783          	ld	a5,-8(s3)
   11afc:	00090513          	mv	a0,s2
   11b00:	0017f793          	andi	a5,a5,1
   11b04:	0087e433          	or	s0,a5,s0
   11b08:	fe89bc23          	sd	s0,-8(s3)
   11b0c:	b51ff0ef          	jal	1165c <__malloc_unlock>
   11b10:	00098513          	mv	a0,s3
   11b14:	cadff06f          	j	117c0 <_realloc_r+0x160>
   11b18:	00098593          	mv	a1,s3
   11b1c:	a1dff0ef          	jal	11538 <memmove>
   11b20:	c41ff06f          	j	11760 <_realloc_r+0x100>
   11b24:	0109b703          	ld	a4,16(s3)
   11b28:	00e53823          	sd	a4,16(a0)
   11b2c:	0189b703          	ld	a4,24(s3)
   11b30:	00e53c23          	sd	a4,24(a0)
   11b34:	02f60863          	beq	a2,a5,11b64 <_realloc_r+0x504>
   11b38:	02050793          	addi	a5,a0,32
   11b3c:	02098713          	addi	a4,s3,32
   11b40:	c09ff06f          	j	11748 <_realloc_r+0xe8>
   11b44:	ff853783          	ld	a5,-8(a0)
   11b48:	00098493          	mv	s1,s3
   11b4c:	ffc7f793          	andi	a5,a5,-4
   11b50:	00fa0a33          	add	s4,s4,a5
   11b54:	c35ff06f          	j	11788 <_realloc_r+0x128>
   11b58:	020b8793          	addi	a5,s7,32
   11b5c:	01098993          	addi	s3,s3,16
   11b60:	dddff06f          	j	1193c <_realloc_r+0x2dc>
   11b64:	0209b683          	ld	a3,32(s3)
   11b68:	03050793          	addi	a5,a0,48
   11b6c:	03098713          	addi	a4,s3,48
   11b70:	02d53023          	sd	a3,32(a0)
   11b74:	0289b683          	ld	a3,40(s3)
   11b78:	02d53423          	sd	a3,40(a0)
   11b7c:	bcdff06f          	j	11748 <_realloc_r+0xe8>
   11b80:	00098593          	mv	a1,s3
   11b84:	00048513          	mv	a0,s1
   11b88:	9b1ff0ef          	jal	11538 <memmove>
   11b8c:	ee9ff06f          	j	11a74 <_realloc_r+0x414>
   11b90:	0109b783          	ld	a5,16(s3)
   11b94:	02fbb023          	sd	a5,32(s7)
   11b98:	0189b783          	ld	a5,24(s3)
   11b9c:	02fbb423          	sd	a5,40(s7)
   11ba0:	02d60063          	beq	a2,a3,11bc0 <_realloc_r+0x560>
   11ba4:	030b8793          	addi	a5,s7,48
   11ba8:	02098993          	addi	s3,s3,32
   11bac:	eb1ff06f          	j	11a5c <_realloc_r+0x3fc>
   11bb0:	00090513          	mv	a0,s2
   11bb4:	aa9ff0ef          	jal	1165c <__malloc_unlock>
   11bb8:	00000513          	li	a0,0
   11bbc:	c05ff06f          	j	117c0 <_realloc_r+0x160>
   11bc0:	0209b703          	ld	a4,32(s3)
   11bc4:	040b8793          	addi	a5,s7,64
   11bc8:	03098993          	addi	s3,s3,48
   11bcc:	02ebb823          	sd	a4,48(s7)
   11bd0:	ff89b703          	ld	a4,-8(s3)
   11bd4:	02ebbc23          	sd	a4,56(s7)
   11bd8:	e85ff06f          	j	11a5c <_realloc_r+0x3fc>

0000000000011bdc <__swsetup_r>:
   11bdc:	8101b783          	ld	a5,-2032(gp) # 14b40 <_impure_ptr>
   11be0:	fe010113          	addi	sp,sp,-32
   11be4:	00813823          	sd	s0,16(sp)
   11be8:	00913423          	sd	s1,8(sp)
   11bec:	00113c23          	sd	ra,24(sp)
   11bf0:	00050493          	mv	s1,a0
   11bf4:	00058413          	mv	s0,a1
   11bf8:	00078663          	beqz	a5,11c04 <__swsetup_r+0x28>
   11bfc:	0507a703          	lw	a4,80(a5)
   11c00:	0e070063          	beqz	a4,11ce0 <__swsetup_r+0x104>
   11c04:	01041703          	lh	a4,16(s0)
   11c08:	03071793          	slli	a5,a4,0x30
   11c0c:	0307d793          	srli	a5,a5,0x30
   11c10:	0087f693          	andi	a3,a5,8
   11c14:	04068263          	beqz	a3,11c58 <__swsetup_r+0x7c>
   11c18:	01843683          	ld	a3,24(s0)
   11c1c:	06068663          	beqz	a3,11c88 <__swsetup_r+0xac>
   11c20:	0017f713          	andi	a4,a5,1
   11c24:	08071463          	bnez	a4,11cac <__swsetup_r+0xd0>
   11c28:	0027f793          	andi	a5,a5,2
   11c2c:	00000713          	li	a4,0
   11c30:	00079463          	bnez	a5,11c38 <__swsetup_r+0x5c>
   11c34:	02042703          	lw	a4,32(s0)
   11c38:	00e42623          	sw	a4,12(s0)
   11c3c:	00000513          	li	a0,0
   11c40:	08068263          	beqz	a3,11cc4 <__swsetup_r+0xe8>
   11c44:	01813083          	ld	ra,24(sp)
   11c48:	01013403          	ld	s0,16(sp)
   11c4c:	00813483          	ld	s1,8(sp)
   11c50:	02010113          	addi	sp,sp,32
   11c54:	00008067          	ret
   11c58:	0107f693          	andi	a3,a5,16
   11c5c:	0c068663          	beqz	a3,11d28 <__swsetup_r+0x14c>
   11c60:	0047f793          	andi	a5,a5,4
   11c64:	08079463          	bnez	a5,11cec <__swsetup_r+0x110>
   11c68:	01843683          	ld	a3,24(s0)
   11c6c:	00876793          	ori	a5,a4,8
   11c70:	0107979b          	slliw	a5,a5,0x10
   11c74:	4107d79b          	sraiw	a5,a5,0x10
   11c78:	00f41823          	sh	a5,16(s0)
   11c7c:	03079793          	slli	a5,a5,0x30
   11c80:	0307d793          	srli	a5,a5,0x30
   11c84:	f8069ee3          	bnez	a3,11c20 <__swsetup_r+0x44>
   11c88:	2807f713          	andi	a4,a5,640
   11c8c:	20000613          	li	a2,512
   11c90:	f8c708e3          	beq	a4,a2,11c20 <__swsetup_r+0x44>
   11c94:	00040593          	mv	a1,s0
   11c98:	00048513          	mv	a0,s1
   11c9c:	495000ef          	jal	12930 <__smakebuf_r>
   11ca0:	01045783          	lhu	a5,16(s0)
   11ca4:	01843683          	ld	a3,24(s0)
   11ca8:	f79ff06f          	j	11c20 <__swsetup_r+0x44>
   11cac:	02042783          	lw	a5,32(s0)
   11cb0:	00042623          	sw	zero,12(s0)
   11cb4:	00000513          	li	a0,0
   11cb8:	40f007bb          	negw	a5,a5
   11cbc:	02f42423          	sw	a5,40(s0)
   11cc0:	f80692e3          	bnez	a3,11c44 <__swsetup_r+0x68>
   11cc4:	01041783          	lh	a5,16(s0)
   11cc8:	0807f713          	andi	a4,a5,128
   11ccc:	f6070ce3          	beqz	a4,11c44 <__swsetup_r+0x68>
   11cd0:	0407e793          	ori	a5,a5,64
   11cd4:	00f41823          	sh	a5,16(s0)
   11cd8:	fff00513          	li	a0,-1
   11cdc:	f69ff06f          	j	11c44 <__swsetup_r+0x68>
   11ce0:	00078513          	mv	a0,a5
   11ce4:	674000ef          	jal	12358 <__sinit>
   11ce8:	f1dff06f          	j	11c04 <__swsetup_r+0x28>
   11cec:	05843583          	ld	a1,88(s0)
   11cf0:	00058e63          	beqz	a1,11d0c <__swsetup_r+0x130>
   11cf4:	07440793          	addi	a5,s0,116
   11cf8:	00f58863          	beq	a1,a5,11d08 <__swsetup_r+0x12c>
   11cfc:	00048513          	mv	a0,s1
   11d00:	7b0000ef          	jal	124b0 <_free_r>
   11d04:	01041703          	lh	a4,16(s0)
   11d08:	04043c23          	sd	zero,88(s0)
   11d0c:	01843683          	ld	a3,24(s0)
   11d10:	fdb77713          	andi	a4,a4,-37
   11d14:	0107171b          	slliw	a4,a4,0x10
   11d18:	4107571b          	sraiw	a4,a4,0x10
   11d1c:	00042423          	sw	zero,8(s0)
   11d20:	00d43023          	sd	a3,0(s0)
   11d24:	f49ff06f          	j	11c6c <__swsetup_r+0x90>
   11d28:	00900793          	li	a5,9
   11d2c:	00f4a023          	sw	a5,0(s1)
   11d30:	04076713          	ori	a4,a4,64
   11d34:	00e41823          	sh	a4,16(s0)
   11d38:	fff00513          	li	a0,-1
   11d3c:	f09ff06f          	j	11c44 <__swsetup_r+0x68>

0000000000011d40 <__sflush_r>:
   11d40:	01059683          	lh	a3,16(a1)
   11d44:	fd010113          	addi	sp,sp,-48
   11d48:	00913c23          	sd	s1,24(sp)
   11d4c:	03069713          	slli	a4,a3,0x30
   11d50:	03075713          	srli	a4,a4,0x30
   11d54:	01313423          	sd	s3,8(sp)
   11d58:	02113423          	sd	ra,40(sp)
   11d5c:	02813023          	sd	s0,32(sp)
   11d60:	01213823          	sd	s2,16(sp)
   11d64:	00877793          	andi	a5,a4,8
   11d68:	00058493          	mv	s1,a1
   11d6c:	00050993          	mv	s3,a0
   11d70:	0e079863          	bnez	a5,11e60 <__sflush_r+0x120>
   11d74:	000017b7          	lui	a5,0x1
   11d78:	8007879b          	addiw	a5,a5,-2048
   11d7c:	00f6e7b3          	or	a5,a3,a5
   11d80:	0107979b          	slliw	a5,a5,0x10
   11d84:	0085a703          	lw	a4,8(a1)
   11d88:	4107d79b          	sraiw	a5,a5,0x10
   11d8c:	00f59823          	sh	a5,16(a1)
   11d90:	1ae05863          	blez	a4,11f40 <__sflush_r+0x200>
   11d94:	0484b703          	ld	a4,72(s1)
   11d98:	0a070463          	beqz	a4,11e40 <__sflush_r+0x100>
   11d9c:	03079793          	slli	a5,a5,0x30
   11da0:	0307d793          	srli	a5,a5,0x30
   11da4:	0009a403          	lw	s0,0(s3)
   11da8:	03379693          	slli	a3,a5,0x33
   11dac:	0009a023          	sw	zero,0(s3)
   11db0:	1806de63          	bgez	a3,11f4c <__sflush_r+0x20c>
   11db4:	0904b603          	ld	a2,144(s1)
   11db8:	0047f793          	andi	a5,a5,4
   11dbc:	00078e63          	beqz	a5,11dd8 <__sflush_r+0x98>
   11dc0:	0084a683          	lw	a3,8(s1)
   11dc4:	0584b783          	ld	a5,88(s1)
   11dc8:	40d60633          	sub	a2,a2,a3
   11dcc:	00078663          	beqz	a5,11dd8 <__sflush_r+0x98>
   11dd0:	0704a783          	lw	a5,112(s1)
   11dd4:	40f60633          	sub	a2,a2,a5
   11dd8:	0304b583          	ld	a1,48(s1)
   11ddc:	00000693          	li	a3,0
   11de0:	00098513          	mv	a0,s3
   11de4:	000700e7          	jalr	a4
   11de8:	fff00793          	li	a5,-1
   11dec:	0ef50c63          	beq	a0,a5,11ee4 <__sflush_r+0x1a4>
   11df0:	0104d683          	lhu	a3,16(s1)
   11df4:	fffff7b7          	lui	a5,0xfffff
   11df8:	7ff7879b          	addiw	a5,a5,2047
   11dfc:	0184b703          	ld	a4,24(s1)
   11e00:	00f6f7b3          	and	a5,a3,a5
   11e04:	0107979b          	slliw	a5,a5,0x10
   11e08:	4107d79b          	sraiw	a5,a5,0x10
   11e0c:	00e4b023          	sd	a4,0(s1)
   11e10:	00f49823          	sh	a5,16(s1)
   11e14:	0004a423          	sw	zero,8(s1)
   11e18:	03379713          	slli	a4,a5,0x33
   11e1c:	10074e63          	bltz	a4,11f38 <__sflush_r+0x1f8>
   11e20:	0584b583          	ld	a1,88(s1)
   11e24:	0089a023          	sw	s0,0(s3)
   11e28:	00058c63          	beqz	a1,11e40 <__sflush_r+0x100>
   11e2c:	07448793          	addi	a5,s1,116
   11e30:	00f58663          	beq	a1,a5,11e3c <__sflush_r+0xfc>
   11e34:	00098513          	mv	a0,s3
   11e38:	678000ef          	jal	124b0 <_free_r>
   11e3c:	0404bc23          	sd	zero,88(s1)
   11e40:	00000513          	li	a0,0
   11e44:	02813083          	ld	ra,40(sp)
   11e48:	02013403          	ld	s0,32(sp)
   11e4c:	01813483          	ld	s1,24(sp)
   11e50:	01013903          	ld	s2,16(sp)
   11e54:	00813983          	ld	s3,8(sp)
   11e58:	03010113          	addi	sp,sp,48
   11e5c:	00008067          	ret
   11e60:	0185b903          	ld	s2,24(a1)
   11e64:	fc090ee3          	beqz	s2,11e40 <__sflush_r+0x100>
   11e68:	0005b403          	ld	s0,0(a1)
   11e6c:	00377713          	andi	a4,a4,3
   11e70:	0125b023          	sd	s2,0(a1)
   11e74:	4124043b          	subw	s0,s0,s2
   11e78:	00000793          	li	a5,0
   11e7c:	00071463          	bnez	a4,11e84 <__sflush_r+0x144>
   11e80:	0205a783          	lw	a5,32(a1)
   11e84:	00f4a623          	sw	a5,12(s1)
   11e88:	00804863          	bgtz	s0,11e98 <__sflush_r+0x158>
   11e8c:	fb5ff06f          	j	11e40 <__sflush_r+0x100>
   11e90:	00a90933          	add	s2,s2,a0
   11e94:	fa8056e3          	blez	s0,11e40 <__sflush_r+0x100>
   11e98:	0404b783          	ld	a5,64(s1)
   11e9c:	0304b583          	ld	a1,48(s1)
   11ea0:	00040693          	mv	a3,s0
   11ea4:	00090613          	mv	a2,s2
   11ea8:	00098513          	mv	a0,s3
   11eac:	000780e7          	jalr	a5
   11eb0:	40a4043b          	subw	s0,s0,a0
   11eb4:	fca04ee3          	bgtz	a0,11e90 <__sflush_r+0x150>
   11eb8:	0104d783          	lhu	a5,16(s1)
   11ebc:	02813083          	ld	ra,40(sp)
   11ec0:	fff00513          	li	a0,-1
   11ec4:	0407e793          	ori	a5,a5,64
   11ec8:	00f49823          	sh	a5,16(s1)
   11ecc:	02013403          	ld	s0,32(sp)
   11ed0:	01813483          	ld	s1,24(sp)
   11ed4:	01013903          	ld	s2,16(sp)
   11ed8:	00813983          	ld	s3,8(sp)
   11edc:	03010113          	addi	sp,sp,48
   11ee0:	00008067          	ret
   11ee4:	0009a703          	lw	a4,0(s3)
   11ee8:	01d00793          	li	a5,29
   11eec:	fce7e6e3          	bltu	a5,a4,11eb8 <__sflush_r+0x178>
   11ef0:	204007b7          	lui	a5,0x20400
   11ef4:	00178793          	addi	a5,a5,1 # 20400001 <_gp+0x203eacd1>
   11ef8:	00e7d7b3          	srl	a5,a5,a4
   11efc:	0017f793          	andi	a5,a5,1
   11f00:	fa078ce3          	beqz	a5,11eb8 <__sflush_r+0x178>
   11f04:	0104d603          	lhu	a2,16(s1)
   11f08:	fffff7b7          	lui	a5,0xfffff
   11f0c:	7ff7879b          	addiw	a5,a5,2047
   11f10:	0184b683          	ld	a3,24(s1)
   11f14:	00f677b3          	and	a5,a2,a5
   11f18:	0107979b          	slliw	a5,a5,0x10
   11f1c:	4107d79b          	sraiw	a5,a5,0x10
   11f20:	00d4b023          	sd	a3,0(s1)
   11f24:	00f49823          	sh	a5,16(s1)
   11f28:	0004a423          	sw	zero,8(s1)
   11f2c:	03379693          	slli	a3,a5,0x33
   11f30:	ee06d8e3          	bgez	a3,11e20 <__sflush_r+0xe0>
   11f34:	ee0716e3          	bnez	a4,11e20 <__sflush_r+0xe0>
   11f38:	08a4b823          	sd	a0,144(s1)
   11f3c:	ee5ff06f          	j	11e20 <__sflush_r+0xe0>
   11f40:	0705a703          	lw	a4,112(a1)
   11f44:	e4e048e3          	bgtz	a4,11d94 <__sflush_r+0x54>
   11f48:	ef9ff06f          	j	11e40 <__sflush_r+0x100>
   11f4c:	0304b583          	ld	a1,48(s1)
   11f50:	00000613          	li	a2,0
   11f54:	00100693          	li	a3,1
   11f58:	00098513          	mv	a0,s3
   11f5c:	000700e7          	jalr	a4
   11f60:	fff00793          	li	a5,-1
   11f64:	00050613          	mv	a2,a0
   11f68:	00f50863          	beq	a0,a5,11f78 <__sflush_r+0x238>
   11f6c:	0104d783          	lhu	a5,16(s1)
   11f70:	0484b703          	ld	a4,72(s1)
   11f74:	e45ff06f          	j	11db8 <__sflush_r+0x78>
   11f78:	0009a783          	lw	a5,0(s3)
   11f7c:	fe0788e3          	beqz	a5,11f6c <__sflush_r+0x22c>
   11f80:	01d00713          	li	a4,29
   11f84:	00e78663          	beq	a5,a4,11f90 <__sflush_r+0x250>
   11f88:	01600713          	li	a4,22
   11f8c:	00e79863          	bne	a5,a4,11f9c <__sflush_r+0x25c>
   11f90:	0089a023          	sw	s0,0(s3)
   11f94:	00000513          	li	a0,0
   11f98:	eadff06f          	j	11e44 <__sflush_r+0x104>
   11f9c:	0104d783          	lhu	a5,16(s1)
   11fa0:	0407e793          	ori	a5,a5,64
   11fa4:	00f49823          	sh	a5,16(s1)
   11fa8:	e9dff06f          	j	11e44 <__sflush_r+0x104>

0000000000011fac <_fflush_r>:
   11fac:	fe010113          	addi	sp,sp,-32
   11fb0:	00813823          	sd	s0,16(sp)
   11fb4:	00113c23          	sd	ra,24(sp)
   11fb8:	00050413          	mv	s0,a0
   11fbc:	00050663          	beqz	a0,11fc8 <_fflush_r+0x1c>
   11fc0:	05052783          	lw	a5,80(a0)
   11fc4:	02078a63          	beqz	a5,11ff8 <_fflush_r+0x4c>
   11fc8:	01059783          	lh	a5,16(a1)
   11fcc:	00079c63          	bnez	a5,11fe4 <_fflush_r+0x38>
   11fd0:	01813083          	ld	ra,24(sp)
   11fd4:	00000513          	li	a0,0
   11fd8:	01013403          	ld	s0,16(sp)
   11fdc:	02010113          	addi	sp,sp,32
   11fe0:	00008067          	ret
   11fe4:	00040513          	mv	a0,s0
   11fe8:	01813083          	ld	ra,24(sp)
   11fec:	01013403          	ld	s0,16(sp)
   11ff0:	02010113          	addi	sp,sp,32
   11ff4:	d4dff06f          	j	11d40 <__sflush_r>
   11ff8:	00b13423          	sd	a1,8(sp)
   11ffc:	35c000ef          	jal	12358 <__sinit>
   12000:	00813583          	ld	a1,8(sp)
   12004:	fc5ff06f          	j	11fc8 <_fflush_r+0x1c>

0000000000012008 <fflush>:
   12008:	00050593          	mv	a1,a0
   1200c:	00050663          	beqz	a0,12018 <fflush+0x10>
   12010:	8101b503          	ld	a0,-2032(gp) # 14b40 <_impure_ptr>
   12014:	f99ff06f          	j	11fac <_fflush_r>
   12018:	8081b503          	ld	a0,-2040(gp) # 14b38 <_global_impure_ptr>
   1201c:	000125b7          	lui	a1,0x12
   12020:	fac58593          	addi	a1,a1,-84 # 11fac <_fflush_r>
   12024:	04d0006f          	j	12870 <_fwalk_reent>

0000000000012028 <__fp_unlock>:
   12028:	00000513          	li	a0,0
   1202c:	00008067          	ret

0000000000012030 <_cleanup_r>:
   12030:	000135b7          	lui	a1,0x13
   12034:	d0858593          	addi	a1,a1,-760 # 12d08 <_fclose_r>
   12038:	0390006f          	j	12870 <_fwalk_reent>

000000000001203c <__sinit.part.1>:
   1203c:	fc010113          	addi	sp,sp,-64
   12040:	000127b7          	lui	a5,0x12
   12044:	02113c23          	sd	ra,56(sp)
   12048:	02813823          	sd	s0,48(sp)
   1204c:	02913423          	sd	s1,40(sp)
   12050:	00853403          	ld	s0,8(a0)
   12054:	03213023          	sd	s2,32(sp)
   12058:	01313c23          	sd	s3,24(sp)
   1205c:	01413823          	sd	s4,16(sp)
   12060:	01513423          	sd	s5,8(sp)
   12064:	01613023          	sd	s6,0(sp)
   12068:	03078793          	addi	a5,a5,48 # 12030 <_cleanup_r>
   1206c:	04f53c23          	sd	a5,88(a0)
   12070:	53850713          	addi	a4,a0,1336
   12074:	00300793          	li	a5,3
   12078:	52e53823          	sd	a4,1328(a0)
   1207c:	52f52423          	sw	a5,1320(a0)
   12080:	52053023          	sd	zero,1312(a0)
   12084:	00400793          	li	a5,4
   12088:	00050913          	mv	s2,a0
   1208c:	00f41823          	sh	a5,16(s0)
   12090:	00800613          	li	a2,8
   12094:	00000593          	li	a1,0
   12098:	00043023          	sd	zero,0(s0)
   1209c:	00042423          	sw	zero,8(s0)
   120a0:	00042623          	sw	zero,12(s0)
   120a4:	0a042623          	sw	zero,172(s0)
   120a8:	00041923          	sh	zero,18(s0)
   120ac:	00043c23          	sd	zero,24(s0)
   120b0:	02042023          	sw	zero,32(s0)
   120b4:	02042423          	sw	zero,40(s0)
   120b8:	0a440513          	addi	a0,s0,164
   120bc:	221000ef          	jal	12adc <memset>
   120c0:	00013b37          	lui	s6,0x13
   120c4:	01093483          	ld	s1,16(s2)
   120c8:	00013ab7          	lui	s5,0x13
   120cc:	00013a37          	lui	s4,0x13
   120d0:	000139b7          	lui	s3,0x13
   120d4:	bb8b0b13          	addi	s6,s6,-1096 # 12bb8 <__sread>
   120d8:	c24a8a93          	addi	s5,s5,-988 # 12c24 <__swrite>
   120dc:	c94a0a13          	addi	s4,s4,-876 # 12c94 <__sseek>
   120e0:	d0098993          	addi	s3,s3,-768 # 12d00 <__sclose>
   120e4:	03643c23          	sd	s6,56(s0)
   120e8:	05543023          	sd	s5,64(s0)
   120ec:	05443423          	sd	s4,72(s0)
   120f0:	05343823          	sd	s3,80(s0)
   120f4:	02843823          	sd	s0,48(s0)
   120f8:	00900793          	li	a5,9
   120fc:	00f49823          	sh	a5,16(s1)
   12100:	00100793          	li	a5,1
   12104:	00f49923          	sh	a5,18(s1)
   12108:	00800613          	li	a2,8
   1210c:	00000593          	li	a1,0
   12110:	0004b023          	sd	zero,0(s1)
   12114:	0004a423          	sw	zero,8(s1)
   12118:	0004a623          	sw	zero,12(s1)
   1211c:	0a04a623          	sw	zero,172(s1)
   12120:	0004bc23          	sd	zero,24(s1)
   12124:	0204a023          	sw	zero,32(s1)
   12128:	0204a423          	sw	zero,40(s1)
   1212c:	0a448513          	addi	a0,s1,164
   12130:	1ad000ef          	jal	12adc <memset>
   12134:	01893403          	ld	s0,24(s2)
   12138:	01200793          	li	a5,18
   1213c:	0364bc23          	sd	s6,56(s1)
   12140:	0554b023          	sd	s5,64(s1)
   12144:	0544b423          	sd	s4,72(s1)
   12148:	0534b823          	sd	s3,80(s1)
   1214c:	0294b823          	sd	s1,48(s1)
   12150:	00f41823          	sh	a5,16(s0)
   12154:	00200793          	li	a5,2
   12158:	00f41923          	sh	a5,18(s0)
   1215c:	00043023          	sd	zero,0(s0)
   12160:	00042423          	sw	zero,8(s0)
   12164:	00042623          	sw	zero,12(s0)
   12168:	0a042623          	sw	zero,172(s0)
   1216c:	00043c23          	sd	zero,24(s0)
   12170:	02042023          	sw	zero,32(s0)
   12174:	02042423          	sw	zero,40(s0)
   12178:	0a440513          	addi	a0,s0,164
   1217c:	00800613          	li	a2,8
   12180:	00000593          	li	a1,0
   12184:	159000ef          	jal	12adc <memset>
   12188:	03813083          	ld	ra,56(sp)
   1218c:	03643c23          	sd	s6,56(s0)
   12190:	05543023          	sd	s5,64(s0)
   12194:	05443423          	sd	s4,72(s0)
   12198:	05343823          	sd	s3,80(s0)
   1219c:	02843823          	sd	s0,48(s0)
   121a0:	00100793          	li	a5,1
   121a4:	04f92823          	sw	a5,80(s2)
   121a8:	03013403          	ld	s0,48(sp)
   121ac:	02813483          	ld	s1,40(sp)
   121b0:	02013903          	ld	s2,32(sp)
   121b4:	01813983          	ld	s3,24(sp)
   121b8:	01013a03          	ld	s4,16(sp)
   121bc:	00813a83          	ld	s5,8(sp)
   121c0:	00013b03          	ld	s6,0(sp)
   121c4:	04010113          	addi	sp,sp,64
   121c8:	00008067          	ret

00000000000121cc <__fp_lock>:
   121cc:	00000513          	li	a0,0
   121d0:	00008067          	ret

00000000000121d4 <__sfmoreglue>:
   121d4:	fe010113          	addi	sp,sp,-32
   121d8:	fff5879b          	addiw	a5,a1,-1
   121dc:	00913423          	sd	s1,8(sp)
   121e0:	0b000493          	li	s1,176
   121e4:	029784b3          	mul	s1,a5,s1
   121e8:	01213023          	sd	s2,0(sp)
   121ec:	00058913          	mv	s2,a1
   121f0:	00813823          	sd	s0,16(sp)
   121f4:	00113c23          	sd	ra,24(sp)
   121f8:	0c848593          	addi	a1,s1,200
   121fc:	9c5fe0ef          	jal	10bc0 <_malloc_r>
   12200:	00050413          	mv	s0,a0
   12204:	02050063          	beqz	a0,12224 <__sfmoreglue+0x50>
   12208:	01850513          	addi	a0,a0,24
   1220c:	00043023          	sd	zero,0(s0)
   12210:	01242423          	sw	s2,8(s0)
   12214:	00a43823          	sd	a0,16(s0)
   12218:	0b048613          	addi	a2,s1,176
   1221c:	00000593          	li	a1,0
   12220:	0bd000ef          	jal	12adc <memset>
   12224:	01813083          	ld	ra,24(sp)
   12228:	00040513          	mv	a0,s0
   1222c:	00813483          	ld	s1,8(sp)
   12230:	01013403          	ld	s0,16(sp)
   12234:	00013903          	ld	s2,0(sp)
   12238:	02010113          	addi	sp,sp,32
   1223c:	00008067          	ret

0000000000012240 <__sfp>:
   12240:	fd010113          	addi	sp,sp,-48
   12244:	01213823          	sd	s2,16(sp)
   12248:	8081b903          	ld	s2,-2040(gp) # 14b38 <_global_impure_ptr>
   1224c:	01313423          	sd	s3,8(sp)
   12250:	02113423          	sd	ra,40(sp)
   12254:	05092783          	lw	a5,80(s2)
   12258:	02813023          	sd	s0,32(sp)
   1225c:	00913c23          	sd	s1,24(sp)
   12260:	00050993          	mv	s3,a0
   12264:	00079663          	bnez	a5,12270 <__sfp+0x30>
   12268:	00090513          	mv	a0,s2
   1226c:	dd1ff0ef          	jal	1203c <__sinit.part.1>
   12270:	52090913          	addi	s2,s2,1312
   12274:	fff00493          	li	s1,-1
   12278:	00892783          	lw	a5,8(s2)
   1227c:	01093403          	ld	s0,16(s2)
   12280:	fff7879b          	addiw	a5,a5,-1
   12284:	0007da63          	bgez	a5,12298 <__sfp+0x58>
   12288:	0840006f          	j	1230c <__sfp+0xcc>
   1228c:	fff7879b          	addiw	a5,a5,-1
   12290:	0b040413          	addi	s0,s0,176
   12294:	06978c63          	beq	a5,s1,1230c <__sfp+0xcc>
   12298:	01041703          	lh	a4,16(s0)
   1229c:	fe0718e3          	bnez	a4,1228c <__sfp+0x4c>
   122a0:	fff00793          	li	a5,-1
   122a4:	00f41923          	sh	a5,18(s0)
   122a8:	00100793          	li	a5,1
   122ac:	00f41823          	sh	a5,16(s0)
   122b0:	0a042623          	sw	zero,172(s0)
   122b4:	00043023          	sd	zero,0(s0)
   122b8:	00042623          	sw	zero,12(s0)
   122bc:	00042423          	sw	zero,8(s0)
   122c0:	00043c23          	sd	zero,24(s0)
   122c4:	02042023          	sw	zero,32(s0)
   122c8:	02042423          	sw	zero,40(s0)
   122cc:	00800613          	li	a2,8
   122d0:	00000593          	li	a1,0
   122d4:	0a440513          	addi	a0,s0,164
   122d8:	005000ef          	jal	12adc <memset>
   122dc:	00040513          	mv	a0,s0
   122e0:	04043c23          	sd	zero,88(s0)
   122e4:	06042023          	sw	zero,96(s0)
   122e8:	06043c23          	sd	zero,120(s0)
   122ec:	08042023          	sw	zero,128(s0)
   122f0:	02813083          	ld	ra,40(sp)
   122f4:	02013403          	ld	s0,32(sp)
   122f8:	01813483          	ld	s1,24(sp)
   122fc:	01013903          	ld	s2,16(sp)
   12300:	00813983          	ld	s3,8(sp)
   12304:	03010113          	addi	sp,sp,48
   12308:	00008067          	ret
   1230c:	00093783          	ld	a5,0(s2)
   12310:	00078663          	beqz	a5,1231c <__sfp+0xdc>
   12314:	00078913          	mv	s2,a5
   12318:	f61ff06f          	j	12278 <__sfp+0x38>
   1231c:	00400593          	li	a1,4
   12320:	00098513          	mv	a0,s3
   12324:	eb1ff0ef          	jal	121d4 <__sfmoreglue>
   12328:	00a93023          	sd	a0,0(s2)
   1232c:	00050663          	beqz	a0,12338 <__sfp+0xf8>
   12330:	00050913          	mv	s2,a0
   12334:	f45ff06f          	j	12278 <__sfp+0x38>
   12338:	00c00793          	li	a5,12
   1233c:	00f9a023          	sw	a5,0(s3)
   12340:	00000513          	li	a0,0
   12344:	fadff06f          	j	122f0 <__sfp+0xb0>

0000000000012348 <_cleanup>:
   12348:	8081b503          	ld	a0,-2040(gp) # 14b38 <_global_impure_ptr>
   1234c:	000135b7          	lui	a1,0x13
   12350:	d0858593          	addi	a1,a1,-760 # 12d08 <_fclose_r>
   12354:	51c0006f          	j	12870 <_fwalk_reent>

0000000000012358 <__sinit>:
   12358:	05052783          	lw	a5,80(a0)
   1235c:	00078463          	beqz	a5,12364 <__sinit+0xc>
   12360:	00008067          	ret
   12364:	cd9ff06f          	j	1203c <__sinit.part.1>

0000000000012368 <__sfp_lock_acquire>:
   12368:	00008067          	ret

000000000001236c <__sfp_lock_release>:
   1236c:	00008067          	ret

0000000000012370 <__sinit_lock_acquire>:
   12370:	00008067          	ret

0000000000012374 <__sinit_lock_release>:
   12374:	00008067          	ret

0000000000012378 <__fp_lock_all>:
   12378:	8101b503          	ld	a0,-2032(gp) # 14b40 <_impure_ptr>
   1237c:	000125b7          	lui	a1,0x12
   12380:	1cc58593          	addi	a1,a1,460 # 121cc <__fp_lock>
   12384:	43c0006f          	j	127c0 <_fwalk>

0000000000012388 <__fp_unlock_all>:
   12388:	8101b503          	ld	a0,-2032(gp) # 14b40 <_impure_ptr>
   1238c:	000125b7          	lui	a1,0x12
   12390:	02858593          	addi	a1,a1,40 # 12028 <__fp_unlock>
   12394:	42c0006f          	j	127c0 <_fwalk>

0000000000012398 <_malloc_trim_r>:
   12398:	fd010113          	addi	sp,sp,-48
   1239c:	01213823          	sd	s2,16(sp)
   123a0:	00014937          	lui	s2,0x14
   123a4:	02813023          	sd	s0,32(sp)
   123a8:	00913c23          	sd	s1,24(sp)
   123ac:	00058413          	mv	s0,a1
   123b0:	01313423          	sd	s3,8(sp)
   123b4:	02113423          	sd	ra,40(sp)
   123b8:	00050993          	mv	s3,a0
   123bc:	31890913          	addi	s2,s2,792 # 14318 <__malloc_av_>
   123c0:	a98ff0ef          	jal	11658 <__malloc_lock>
   123c4:	01093703          	ld	a4,16(s2)
   123c8:	000017b7          	lui	a5,0x1
   123cc:	fdf78593          	addi	a1,a5,-33 # fdf <_ftext-0xf021>
   123d0:	00873483          	ld	s1,8(a4)
   123d4:	ffc4f493          	andi	s1,s1,-4
   123d8:	40848433          	sub	s0,s1,s0
   123dc:	00b40433          	add	s0,s0,a1
   123e0:	00c45413          	srli	s0,s0,0xc
   123e4:	fff40413          	addi	s0,s0,-1
   123e8:	00c41413          	slli	s0,s0,0xc
   123ec:	00f44c63          	blt	s0,a5,12404 <_malloc_trim_r+0x6c>
   123f0:	00000513          	li	a0,0
   123f4:	589000ef          	jal	1317c <sbrk>
   123f8:	01093783          	ld	a5,16(s2)
   123fc:	009787b3          	add	a5,a5,s1
   12400:	02f50663          	beq	a0,a5,1242c <_malloc_trim_r+0x94>
   12404:	00098513          	mv	a0,s3
   12408:	a54ff0ef          	jal	1165c <__malloc_unlock>
   1240c:	02813083          	ld	ra,40(sp)
   12410:	00000513          	li	a0,0
   12414:	02013403          	ld	s0,32(sp)
   12418:	01813483          	ld	s1,24(sp)
   1241c:	01013903          	ld	s2,16(sp)
   12420:	00813983          	ld	s3,8(sp)
   12424:	03010113          	addi	sp,sp,48
   12428:	00008067          	ret
   1242c:	40800533          	neg	a0,s0
   12430:	54d000ef          	jal	1317c <sbrk>
   12434:	fff00793          	li	a5,-1
   12438:	04f50463          	beq	a0,a5,12480 <_malloc_trim_r+0xe8>
   1243c:	8981a783          	lw	a5,-1896(gp) # 14bc8 <__malloc_current_mallinfo>
   12440:	01093683          	ld	a3,16(s2)
   12444:	408484b3          	sub	s1,s1,s0
   12448:	0014e493          	ori	s1,s1,1
   1244c:	4087843b          	subw	s0,a5,s0
   12450:	00098513          	mv	a0,s3
   12454:	0096b423          	sd	s1,8(a3)
   12458:	8881ac23          	sw	s0,-1896(gp) # 14bc8 <__malloc_current_mallinfo>
   1245c:	a00ff0ef          	jal	1165c <__malloc_unlock>
   12460:	02813083          	ld	ra,40(sp)
   12464:	00100513          	li	a0,1
   12468:	02013403          	ld	s0,32(sp)
   1246c:	01813483          	ld	s1,24(sp)
   12470:	01013903          	ld	s2,16(sp)
   12474:	00813983          	ld	s3,8(sp)
   12478:	03010113          	addi	sp,sp,48
   1247c:	00008067          	ret
   12480:	00000513          	li	a0,0
   12484:	4f9000ef          	jal	1317c <sbrk>
   12488:	01093703          	ld	a4,16(s2)
   1248c:	01f00693          	li	a3,31
   12490:	40e507b3          	sub	a5,a0,a4
   12494:	f6f6d8e3          	ble	a5,a3,12404 <_malloc_trim_r+0x6c>
   12498:	8181b683          	ld	a3,-2024(gp) # 14b48 <__malloc_sbrk_base>
   1249c:	0017e793          	ori	a5,a5,1
   124a0:	00f73423          	sd	a5,8(a4)
   124a4:	40d50533          	sub	a0,a0,a3
   124a8:	88a1ac23          	sw	a0,-1896(gp) # 14bc8 <__malloc_current_mallinfo>
   124ac:	f59ff06f          	j	12404 <_malloc_trim_r+0x6c>

00000000000124b0 <_free_r>:
   124b0:	10058263          	beqz	a1,125b4 <_free_r+0x104>
   124b4:	fe010113          	addi	sp,sp,-32
   124b8:	00813823          	sd	s0,16(sp)
   124bc:	00913423          	sd	s1,8(sp)
   124c0:	00058413          	mv	s0,a1
   124c4:	00050493          	mv	s1,a0
   124c8:	00113c23          	sd	ra,24(sp)
   124cc:	98cff0ef          	jal	11658 <__malloc_lock>
   124d0:	ff843503          	ld	a0,-8(s0)
   124d4:	ff040693          	addi	a3,s0,-16
   124d8:	000145b7          	lui	a1,0x14
   124dc:	ffe57793          	andi	a5,a0,-2
   124e0:	00f68633          	add	a2,a3,a5
   124e4:	31858593          	addi	a1,a1,792 # 14318 <__malloc_av_>
   124e8:	00863703          	ld	a4,8(a2)
   124ec:	0105b803          	ld	a6,16(a1)
   124f0:	ffc77713          	andi	a4,a4,-4
   124f4:	17060663          	beq	a2,a6,12660 <_free_r+0x1b0>
   124f8:	00e63423          	sd	a4,8(a2)
   124fc:	00157513          	andi	a0,a0,1
   12500:	02051663          	bnez	a0,1252c <_free_r+0x7c>
   12504:	ff043503          	ld	a0,-16(s0)
   12508:	40a686b3          	sub	a3,a3,a0
   1250c:	0106b803          	ld	a6,16(a3)
   12510:	00a787b3          	add	a5,a5,a0
   12514:	00014537          	lui	a0,0x14
   12518:	32850513          	addi	a0,a0,808 # 14328 <__malloc_av_+0x10>
   1251c:	18a80863          	beq	a6,a0,126ac <_free_r+0x1fc>
   12520:	0186b503          	ld	a0,24(a3)
   12524:	00a83c23          	sd	a0,24(a6)
   12528:	01053823          	sd	a6,16(a0)
   1252c:	00e60533          	add	a0,a2,a4
   12530:	00853503          	ld	a0,8(a0)
   12534:	00157513          	andi	a0,a0,1
   12538:	0e050a63          	beqz	a0,1262c <_free_r+0x17c>
   1253c:	0017e713          	ori	a4,a5,1
   12540:	00e6b423          	sd	a4,8(a3)
   12544:	00f68733          	add	a4,a3,a5
   12548:	00f73023          	sd	a5,0(a4)
   1254c:	1ff00713          	li	a4,511
   12550:	06f76463          	bltu	a4,a5,125b8 <_free_r+0x108>
   12554:	0037d793          	srli	a5,a5,0x3
   12558:	0007879b          	sext.w	a5,a5
   1255c:	0017871b          	addiw	a4,a5,1
   12560:	0017171b          	slliw	a4,a4,0x1
   12564:	00371713          	slli	a4,a4,0x3
   12568:	0085b603          	ld	a2,8(a1)
   1256c:	00e58733          	add	a4,a1,a4
   12570:	00073803          	ld	a6,0(a4)
   12574:	4027d79b          	sraiw	a5,a5,0x2
   12578:	00100513          	li	a0,1
   1257c:	00f517b3          	sll	a5,a0,a5
   12580:	00c7e7b3          	or	a5,a5,a2
   12584:	ff070613          	addi	a2,a4,-16
   12588:	00c6bc23          	sd	a2,24(a3)
   1258c:	0106b823          	sd	a6,16(a3)
   12590:	00f5b423          	sd	a5,8(a1)
   12594:	00d73023          	sd	a3,0(a4)
   12598:	00d83c23          	sd	a3,24(a6)
   1259c:	00048513          	mv	a0,s1
   125a0:	01813083          	ld	ra,24(sp)
   125a4:	01013403          	ld	s0,16(sp)
   125a8:	00813483          	ld	s1,8(sp)
   125ac:	02010113          	addi	sp,sp,32
   125b0:	8acff06f          	j	1165c <__malloc_unlock>
   125b4:	00008067          	ret
   125b8:	0097d713          	srli	a4,a5,0x9
   125bc:	00400613          	li	a2,4
   125c0:	12e66263          	bltu	a2,a4,126e4 <_free_r+0x234>
   125c4:	0067d713          	srli	a4,a5,0x6
   125c8:	0007071b          	sext.w	a4,a4
   125cc:	0397051b          	addiw	a0,a4,57
   125d0:	0387061b          	addiw	a2,a4,56
   125d4:	0015151b          	slliw	a0,a0,0x1
   125d8:	00351513          	slli	a0,a0,0x3
   125dc:	00a58533          	add	a0,a1,a0
   125e0:	00053703          	ld	a4,0(a0)
   125e4:	ff050513          	addi	a0,a0,-16
   125e8:	10e50c63          	beq	a0,a4,12700 <_free_r+0x250>
   125ec:	00873603          	ld	a2,8(a4)
   125f0:	ffc67613          	andi	a2,a2,-4
   125f4:	00c7f663          	bleu	a2,a5,12600 <_free_r+0x150>
   125f8:	01073703          	ld	a4,16(a4)
   125fc:	fee518e3          	bne	a0,a4,125ec <_free_r+0x13c>
   12600:	01873503          	ld	a0,24(a4)
   12604:	00a6bc23          	sd	a0,24(a3)
   12608:	00e6b823          	sd	a4,16(a3)
   1260c:	00d53823          	sd	a3,16(a0)
   12610:	01813083          	ld	ra,24(sp)
   12614:	00048513          	mv	a0,s1
   12618:	01013403          	ld	s0,16(sp)
   1261c:	00813483          	ld	s1,8(sp)
   12620:	00d73c23          	sd	a3,24(a4)
   12624:	02010113          	addi	sp,sp,32
   12628:	834ff06f          	j	1165c <__malloc_unlock>
   1262c:	01063503          	ld	a0,16(a2)
   12630:	00e787b3          	add	a5,a5,a4
   12634:	00014737          	lui	a4,0x14
   12638:	32870713          	addi	a4,a4,808 # 14328 <__malloc_av_+0x10>
   1263c:	0ee50263          	beq	a0,a4,12720 <_free_r+0x270>
   12640:	01863803          	ld	a6,24(a2)
   12644:	0017e613          	ori	a2,a5,1
   12648:	00f68733          	add	a4,a3,a5
   1264c:	01053c23          	sd	a6,24(a0)
   12650:	00a83823          	sd	a0,16(a6)
   12654:	00c6b423          	sd	a2,8(a3)
   12658:	00f73023          	sd	a5,0(a4)
   1265c:	ef1ff06f          	j	1254c <_free_r+0x9c>
   12660:	00157513          	andi	a0,a0,1
   12664:	00e787b3          	add	a5,a5,a4
   12668:	02051063          	bnez	a0,12688 <_free_r+0x1d8>
   1266c:	ff043503          	ld	a0,-16(s0)
   12670:	40a686b3          	sub	a3,a3,a0
   12674:	0186b703          	ld	a4,24(a3)
   12678:	0106b603          	ld	a2,16(a3)
   1267c:	00a787b3          	add	a5,a5,a0
   12680:	00e63c23          	sd	a4,24(a2)
   12684:	00c73823          	sd	a2,16(a4)
   12688:	0017e613          	ori	a2,a5,1
   1268c:	8201b703          	ld	a4,-2016(gp) # 14b50 <__malloc_trim_threshold>
   12690:	00c6b423          	sd	a2,8(a3)
   12694:	00d5b823          	sd	a3,16(a1)
   12698:	f0e7e2e3          	bltu	a5,a4,1259c <_free_r+0xec>
   1269c:	8501b583          	ld	a1,-1968(gp) # 14b80 <__malloc_top_pad>
   126a0:	00048513          	mv	a0,s1
   126a4:	cf5ff0ef          	jal	12398 <_malloc_trim_r>
   126a8:	ef5ff06f          	j	1259c <_free_r+0xec>
   126ac:	00e605b3          	add	a1,a2,a4
   126b0:	0085b583          	ld	a1,8(a1)
   126b4:	0015f593          	andi	a1,a1,1
   126b8:	0e059a63          	bnez	a1,127ac <_free_r+0x2fc>
   126bc:	01063583          	ld	a1,16(a2)
   126c0:	01863603          	ld	a2,24(a2)
   126c4:	00f707b3          	add	a5,a4,a5
   126c8:	0017e713          	ori	a4,a5,1
   126cc:	00c5bc23          	sd	a2,24(a1)
   126d0:	00b63823          	sd	a1,16(a2)
   126d4:	00e6b423          	sd	a4,8(a3)
   126d8:	00f686b3          	add	a3,a3,a5
   126dc:	00f6b023          	sd	a5,0(a3)
   126e0:	ebdff06f          	j	1259c <_free_r+0xec>
   126e4:	01400613          	li	a2,20
   126e8:	04e66e63          	bltu	a2,a4,12744 <_free_r+0x294>
   126ec:	0007071b          	sext.w	a4,a4
   126f0:	05c7051b          	addiw	a0,a4,92
   126f4:	05b7061b          	addiw	a2,a4,91
   126f8:	0015151b          	slliw	a0,a0,0x1
   126fc:	eddff06f          	j	125d8 <_free_r+0x128>
   12700:	0085b783          	ld	a5,8(a1)
   12704:	4026571b          	sraiw	a4,a2,0x2
   12708:	00100613          	li	a2,1
   1270c:	00e61733          	sll	a4,a2,a4
   12710:	00f767b3          	or	a5,a4,a5
   12714:	00f5b423          	sd	a5,8(a1)
   12718:	00050713          	mv	a4,a0
   1271c:	ee9ff06f          	j	12604 <_free_r+0x154>
   12720:	02d5b423          	sd	a3,40(a1)
   12724:	02d5b023          	sd	a3,32(a1)
   12728:	0017e713          	ori	a4,a5,1
   1272c:	00a6bc23          	sd	a0,24(a3)
   12730:	00a6b823          	sd	a0,16(a3)
   12734:	00e6b423          	sd	a4,8(a3)
   12738:	00f686b3          	add	a3,a3,a5
   1273c:	00f6b023          	sd	a5,0(a3)
   12740:	e5dff06f          	j	1259c <_free_r+0xec>
   12744:	05400613          	li	a2,84
   12748:	00e66e63          	bltu	a2,a4,12764 <_free_r+0x2b4>
   1274c:	00c7d713          	srli	a4,a5,0xc
   12750:	0007071b          	sext.w	a4,a4
   12754:	06f7051b          	addiw	a0,a4,111
   12758:	06e7061b          	addiw	a2,a4,110
   1275c:	0015151b          	slliw	a0,a0,0x1
   12760:	e79ff06f          	j	125d8 <_free_r+0x128>
   12764:	15400613          	li	a2,340
   12768:	00e66e63          	bltu	a2,a4,12784 <_free_r+0x2d4>
   1276c:	00f7d713          	srli	a4,a5,0xf
   12770:	0007071b          	sext.w	a4,a4
   12774:	0787051b          	addiw	a0,a4,120
   12778:	0777061b          	addiw	a2,a4,119
   1277c:	0015151b          	slliw	a0,a0,0x1
   12780:	e59ff06f          	j	125d8 <_free_r+0x128>
   12784:	55400813          	li	a6,1364
   12788:	0fe00513          	li	a0,254
   1278c:	07e00613          	li	a2,126
   12790:	e4e864e3          	bltu	a6,a4,125d8 <_free_r+0x128>
   12794:	0127d713          	srli	a4,a5,0x12
   12798:	0007071b          	sext.w	a4,a4
   1279c:	07d7051b          	addiw	a0,a4,125
   127a0:	07c7061b          	addiw	a2,a4,124
   127a4:	0015151b          	slliw	a0,a0,0x1
   127a8:	e31ff06f          	j	125d8 <_free_r+0x128>
   127ac:	0017e713          	ori	a4,a5,1
   127b0:	00e6b423          	sd	a4,8(a3)
   127b4:	00f686b3          	add	a3,a3,a5
   127b8:	00f6b023          	sd	a5,0(a3)
   127bc:	de1ff06f          	j	1259c <_free_r+0xec>

00000000000127c0 <_fwalk>:
   127c0:	fc010113          	addi	sp,sp,-64
   127c4:	01513423          	sd	s5,8(sp)
   127c8:	02113c23          	sd	ra,56(sp)
   127cc:	02813823          	sd	s0,48(sp)
   127d0:	02913423          	sd	s1,40(sp)
   127d4:	03213023          	sd	s2,32(sp)
   127d8:	01313c23          	sd	s3,24(sp)
   127dc:	01413823          	sd	s4,16(sp)
   127e0:	01613023          	sd	s6,0(sp)
   127e4:	52050a93          	addi	s5,a0,1312
   127e8:	080a8063          	beqz	s5,12868 <_fwalk+0xa8>
   127ec:	00058b13          	mv	s6,a1
   127f0:	00000a13          	li	s4,0
   127f4:	00100993          	li	s3,1
   127f8:	fff00913          	li	s2,-1
   127fc:	008aa483          	lw	s1,8(s5)
   12800:	010ab403          	ld	s0,16(s5)
   12804:	fff4849b          	addiw	s1,s1,-1
   12808:	0204c663          	bltz	s1,12834 <_fwalk+0x74>
   1280c:	01045783          	lhu	a5,16(s0)
   12810:	fff4849b          	addiw	s1,s1,-1
   12814:	00f9fc63          	bleu	a5,s3,1282c <_fwalk+0x6c>
   12818:	01241783          	lh	a5,18(s0)
   1281c:	00040513          	mv	a0,s0
   12820:	01278663          	beq	a5,s2,1282c <_fwalk+0x6c>
   12824:	000b00e7          	jalr	s6
   12828:	00aa6a33          	or	s4,s4,a0
   1282c:	0b040413          	addi	s0,s0,176
   12830:	fd249ee3          	bne	s1,s2,1280c <_fwalk+0x4c>
   12834:	000aba83          	ld	s5,0(s5)
   12838:	fc0a92e3          	bnez	s5,127fc <_fwalk+0x3c>
   1283c:	03813083          	ld	ra,56(sp)
   12840:	000a0513          	mv	a0,s4
   12844:	03013403          	ld	s0,48(sp)
   12848:	02813483          	ld	s1,40(sp)
   1284c:	02013903          	ld	s2,32(sp)
   12850:	01813983          	ld	s3,24(sp)
   12854:	01013a03          	ld	s4,16(sp)
   12858:	00813a83          	ld	s5,8(sp)
   1285c:	00013b03          	ld	s6,0(sp)
   12860:	04010113          	addi	sp,sp,64
   12864:	00008067          	ret
   12868:	00000a13          	li	s4,0
   1286c:	fd1ff06f          	j	1283c <_fwalk+0x7c>

0000000000012870 <_fwalk_reent>:
   12870:	fb010113          	addi	sp,sp,-80
   12874:	01613823          	sd	s6,16(sp)
   12878:	04113423          	sd	ra,72(sp)
   1287c:	04813023          	sd	s0,64(sp)
   12880:	02913c23          	sd	s1,56(sp)
   12884:	03213823          	sd	s2,48(sp)
   12888:	03313423          	sd	s3,40(sp)
   1288c:	03413023          	sd	s4,32(sp)
   12890:	01513c23          	sd	s5,24(sp)
   12894:	01713423          	sd	s7,8(sp)
   12898:	52050b13          	addi	s6,a0,1312
   1289c:	080b0663          	beqz	s6,12928 <_fwalk_reent+0xb8>
   128a0:	00058b93          	mv	s7,a1
   128a4:	00050a93          	mv	s5,a0
   128a8:	00000a13          	li	s4,0
   128ac:	00100993          	li	s3,1
   128b0:	fff00913          	li	s2,-1
   128b4:	008b2483          	lw	s1,8(s6)
   128b8:	010b3403          	ld	s0,16(s6)
   128bc:	fff4849b          	addiw	s1,s1,-1
   128c0:	0204c863          	bltz	s1,128f0 <_fwalk_reent+0x80>
   128c4:	01045783          	lhu	a5,16(s0)
   128c8:	fff4849b          	addiw	s1,s1,-1
   128cc:	00f9fe63          	bleu	a5,s3,128e8 <_fwalk_reent+0x78>
   128d0:	01241783          	lh	a5,18(s0)
   128d4:	00040593          	mv	a1,s0
   128d8:	000a8513          	mv	a0,s5
   128dc:	01278663          	beq	a5,s2,128e8 <_fwalk_reent+0x78>
   128e0:	000b80e7          	jalr	s7
   128e4:	00aa6a33          	or	s4,s4,a0
   128e8:	0b040413          	addi	s0,s0,176
   128ec:	fd249ce3          	bne	s1,s2,128c4 <_fwalk_reent+0x54>
   128f0:	000b3b03          	ld	s6,0(s6)
   128f4:	fc0b10e3          	bnez	s6,128b4 <_fwalk_reent+0x44>
   128f8:	04813083          	ld	ra,72(sp)
   128fc:	000a0513          	mv	a0,s4
   12900:	04013403          	ld	s0,64(sp)
   12904:	03813483          	ld	s1,56(sp)
   12908:	03013903          	ld	s2,48(sp)
   1290c:	02813983          	ld	s3,40(sp)
   12910:	02013a03          	ld	s4,32(sp)
   12914:	01813a83          	ld	s5,24(sp)
   12918:	01013b03          	ld	s6,16(sp)
   1291c:	00813b83          	ld	s7,8(sp)
   12920:	05010113          	addi	sp,sp,80
   12924:	00008067          	ret
   12928:	00000a13          	li	s4,0
   1292c:	fcdff06f          	j	128f8 <_fwalk_reent+0x88>

0000000000012930 <__smakebuf_r>:
   12930:	01059783          	lh	a5,16(a1)
   12934:	f5010113          	addi	sp,sp,-176
   12938:	08913c23          	sd	s1,152(sp)
   1293c:	03079493          	slli	s1,a5,0x30
   12940:	0304d493          	srli	s1,s1,0x30
   12944:	0a113423          	sd	ra,168(sp)
   12948:	0a813023          	sd	s0,160(sp)
   1294c:	09213823          	sd	s2,144(sp)
   12950:	09313423          	sd	s3,136(sp)
   12954:	0024f713          	andi	a4,s1,2
   12958:	0e071063          	bnez	a4,12a38 <__smakebuf_r+0x108>
   1295c:	00050913          	mv	s2,a0
   12960:	01259503          	lh	a0,18(a1)
   12964:	00058413          	mv	s0,a1
   12968:	04054c63          	bltz	a0,129c0 <__smakebuf_r+0x90>
   1296c:	00010593          	mv	a1,sp
   12970:	540000ef          	jal	12eb0 <fstat>
   12974:	04054063          	bltz	a0,129b4 <__smakebuf_r+0x84>
   12978:	01012703          	lw	a4,16(sp)
   1297c:	0000f7b7          	lui	a5,0xf
   12980:	ffffe9b7          	lui	s3,0xffffe
   12984:	00f777b3          	and	a5,a4,a5
   12988:	013789bb          	addw	s3,a5,s3
   1298c:	00008737          	lui	a4,0x8
   12990:	0019b993          	seqz	s3,s3
   12994:	0ce78a63          	beq	a5,a4,12a68 <__smakebuf_r+0x138>
   12998:	01045703          	lhu	a4,16(s0)
   1299c:	000017b7          	lui	a5,0x1
   129a0:	8007879b          	addiw	a5,a5,-2048
   129a4:	00f767b3          	or	a5,a4,a5
   129a8:	00f41823          	sh	a5,16(s0)
   129ac:	40000493          	li	s1,1024
   129b0:	0340006f          	j	129e4 <__smakebuf_r+0xb4>
   129b4:	01041783          	lh	a5,16(s0)
   129b8:	03079493          	slli	s1,a5,0x30
   129bc:	0304d493          	srli	s1,s1,0x30
   129c0:	03849493          	slli	s1,s1,0x38
   129c4:	00001737          	lui	a4,0x1
   129c8:	43f4d493          	srai	s1,s1,0x3f
   129cc:	8007071b          	addiw	a4,a4,-2048
   129d0:	c404f493          	andi	s1,s1,-960
   129d4:	00e7e7b3          	or	a5,a5,a4
   129d8:	40048493          	addi	s1,s1,1024
   129dc:	00f41823          	sh	a5,16(s0)
   129e0:	00000993          	li	s3,0
   129e4:	00048593          	mv	a1,s1
   129e8:	00090513          	mv	a0,s2
   129ec:	9d4fe0ef          	jal	10bc0 <_malloc_r>
   129f0:	0c050063          	beqz	a0,12ab0 <__smakebuf_r+0x180>
   129f4:	01045783          	lhu	a5,16(s0)
   129f8:	00012737          	lui	a4,0x12
   129fc:	03070713          	addi	a4,a4,48 # 12030 <_cleanup_r>
   12a00:	04e93c23          	sd	a4,88(s2)
   12a04:	0807e793          	ori	a5,a5,128
   12a08:	00f41823          	sh	a5,16(s0)
   12a0c:	00a43023          	sd	a0,0(s0)
   12a10:	00a43c23          	sd	a0,24(s0)
   12a14:	02942023          	sw	s1,32(s0)
   12a18:	06099e63          	bnez	s3,12a94 <__smakebuf_r+0x164>
   12a1c:	0a813083          	ld	ra,168(sp)
   12a20:	0a013403          	ld	s0,160(sp)
   12a24:	09813483          	ld	s1,152(sp)
   12a28:	09013903          	ld	s2,144(sp)
   12a2c:	08813983          	ld	s3,136(sp)
   12a30:	0b010113          	addi	sp,sp,176
   12a34:	00008067          	ret
   12a38:	0a813083          	ld	ra,168(sp)
   12a3c:	07758793          	addi	a5,a1,119
   12a40:	00f5b023          	sd	a5,0(a1)
   12a44:	00f5bc23          	sd	a5,24(a1)
   12a48:	00100793          	li	a5,1
   12a4c:	0a013403          	ld	s0,160(sp)
   12a50:	09813483          	ld	s1,152(sp)
   12a54:	09013903          	ld	s2,144(sp)
   12a58:	08813983          	ld	s3,136(sp)
   12a5c:	02f5a023          	sw	a5,32(a1)
   12a60:	0b010113          	addi	sp,sp,176
   12a64:	00008067          	ret
   12a68:	04843703          	ld	a4,72(s0)
   12a6c:	000137b7          	lui	a5,0x13
   12a70:	c9478793          	addi	a5,a5,-876 # 12c94 <__sseek>
   12a74:	f2f712e3          	bne	a4,a5,12998 <__smakebuf_r+0x68>
   12a78:	01045783          	lhu	a5,16(s0)
   12a7c:	40000713          	li	a4,1024
   12a80:	08e42423          	sw	a4,136(s0)
   12a84:	00e7e7b3          	or	a5,a5,a4
   12a88:	00f41823          	sh	a5,16(s0)
   12a8c:	40000493          	li	s1,1024
   12a90:	f55ff06f          	j	129e4 <__smakebuf_r+0xb4>
   12a94:	01241503          	lh	a0,18(s0)
   12a98:	5a4000ef          	jal	1303c <isatty>
   12a9c:	f80500e3          	beqz	a0,12a1c <__smakebuf_r+0xec>
   12aa0:	01045783          	lhu	a5,16(s0)
   12aa4:	0017e793          	ori	a5,a5,1
   12aa8:	00f41823          	sh	a5,16(s0)
   12aac:	f71ff06f          	j	12a1c <__smakebuf_r+0xec>
   12ab0:	01041783          	lh	a5,16(s0)
   12ab4:	2007f713          	andi	a4,a5,512
   12ab8:	f60712e3          	bnez	a4,12a1c <__smakebuf_r+0xec>
   12abc:	0027e793          	ori	a5,a5,2
   12ac0:	07740713          	addi	a4,s0,119
   12ac4:	00f41823          	sh	a5,16(s0)
   12ac8:	00100793          	li	a5,1
   12acc:	00e43023          	sd	a4,0(s0)
   12ad0:	00e43c23          	sd	a4,24(s0)
   12ad4:	02f42023          	sw	a5,32(s0)
   12ad8:	f45ff06f          	j	12a1c <__smakebuf_r+0xec>

0000000000012adc <memset>:
   12adc:	00f00813          	li	a6,15
   12ae0:	00050713          	mv	a4,a0
   12ae4:	02c87a63          	bleu	a2,a6,12b18 <memset+0x3c>
   12ae8:	00f77793          	andi	a5,a4,15
   12aec:	0a079063          	bnez	a5,12b8c <memset+0xb0>
   12af0:	06059e63          	bnez	a1,12b6c <memset+0x90>
   12af4:	ff067693          	andi	a3,a2,-16
   12af8:	00f67613          	andi	a2,a2,15
   12afc:	00e686b3          	add	a3,a3,a4
   12b00:	00b73023          	sd	a1,0(a4)
   12b04:	00b73423          	sd	a1,8(a4)
   12b08:	01070713          	addi	a4,a4,16
   12b0c:	fed76ae3          	bltu	a4,a3,12b00 <memset+0x24>
   12b10:	00061463          	bnez	a2,12b18 <memset+0x3c>
   12b14:	00008067          	ret
   12b18:	40c806b3          	sub	a3,a6,a2
   12b1c:	00269693          	slli	a3,a3,0x2
   12b20:	00000297          	auipc	t0,0x0
   12b24:	005686b3          	add	a3,a3,t0
   12b28:	00c68067          	jr	a3,12
   12b2c:	00b70723          	sb	a1,14(a4)
   12b30:	00b706a3          	sb	a1,13(a4)
   12b34:	00b70623          	sb	a1,12(a4)
   12b38:	00b705a3          	sb	a1,11(a4)
   12b3c:	00b70523          	sb	a1,10(a4)
   12b40:	00b704a3          	sb	a1,9(a4)
   12b44:	00b70423          	sb	a1,8(a4)
   12b48:	00b703a3          	sb	a1,7(a4)
   12b4c:	00b70323          	sb	a1,6(a4)
   12b50:	00b702a3          	sb	a1,5(a4)
   12b54:	00b70223          	sb	a1,4(a4)
   12b58:	00b701a3          	sb	a1,3(a4)
   12b5c:	00b70123          	sb	a1,2(a4)
   12b60:	00b700a3          	sb	a1,1(a4)
   12b64:	00b70023          	sb	a1,0(a4)
   12b68:	00008067          	ret
   12b6c:	0ff5f593          	andi	a1,a1,255
   12b70:	00859693          	slli	a3,a1,0x8
   12b74:	00d5e5b3          	or	a1,a1,a3
   12b78:	01059693          	slli	a3,a1,0x10
   12b7c:	00d5e5b3          	or	a1,a1,a3
   12b80:	02059693          	slli	a3,a1,0x20
   12b84:	00d5e5b3          	or	a1,a1,a3
   12b88:	f6dff06f          	j	12af4 <memset+0x18>
   12b8c:	00279693          	slli	a3,a5,0x2
   12b90:	00000297          	auipc	t0,0x0
   12b94:	005686b3          	add	a3,a3,t0
   12b98:	00008293          	mv	t0,ra
   12b9c:	f98680e7          	jalr	a3,-104
   12ba0:	00028093          	mv	ra,t0
   12ba4:	ff078793          	addi	a5,a5,-16
   12ba8:	40f70733          	sub	a4,a4,a5
   12bac:	00f60633          	add	a2,a2,a5
   12bb0:	f6c874e3          	bleu	a2,a6,12b18 <memset+0x3c>
   12bb4:	f3dff06f          	j	12af0 <memset+0x14>

0000000000012bb8 <__sread>:
   12bb8:	01259503          	lh	a0,18(a1)
   12bbc:	ff010113          	addi	sp,sp,-16
   12bc0:	00813023          	sd	s0,0(sp)
   12bc4:	00058413          	mv	s0,a1
   12bc8:	00060593          	mv	a1,a2
   12bcc:	00068613          	mv	a2,a3
   12bd0:	00113423          	sd	ra,8(sp)
   12bd4:	2b4000ef          	jal	12e88 <read>
   12bd8:	02054063          	bltz	a0,12bf8 <__sread+0x40>
   12bdc:	09043783          	ld	a5,144(s0)
   12be0:	00813083          	ld	ra,8(sp)
   12be4:	00a787b3          	add	a5,a5,a0
   12be8:	08f43823          	sd	a5,144(s0)
   12bec:	00013403          	ld	s0,0(sp)
   12bf0:	01010113          	addi	sp,sp,16
   12bf4:	00008067          	ret
   12bf8:	01045703          	lhu	a4,16(s0)
   12bfc:	fffff7b7          	lui	a5,0xfffff
   12c00:	00813083          	ld	ra,8(sp)
   12c04:	fff7879b          	addiw	a5,a5,-1
   12c08:	00f777b3          	and	a5,a4,a5
   12c0c:	00f41823          	sh	a5,16(s0)
   12c10:	00013403          	ld	s0,0(sp)
   12c14:	01010113          	addi	sp,sp,16
   12c18:	00008067          	ret

0000000000012c1c <__seofread>:
   12c1c:	00000513          	li	a0,0
   12c20:	00008067          	ret

0000000000012c24 <__swrite>:
   12c24:	01059703          	lh	a4,16(a1)
   12c28:	fd010113          	addi	sp,sp,-48
   12c2c:	02813023          	sd	s0,32(sp)
   12c30:	00913c23          	sd	s1,24(sp)
   12c34:	02113423          	sd	ra,40(sp)
   12c38:	10077793          	andi	a5,a4,256
   12c3c:	00058413          	mv	s0,a1
   12c40:	00060493          	mv	s1,a2
   12c44:	02078063          	beqz	a5,12c64 <__swrite+0x40>
   12c48:	01259503          	lh	a0,18(a1)
   12c4c:	00200613          	li	a2,2
   12c50:	00000593          	li	a1,0
   12c54:	00d13423          	sd	a3,8(sp)
   12c58:	21c000ef          	jal	12e74 <lseek>
   12c5c:	01041703          	lh	a4,16(s0)
   12c60:	00813683          	ld	a3,8(sp)
   12c64:	fffff7b7          	lui	a5,0xfffff
   12c68:	fff7879b          	addiw	a5,a5,-1
   12c6c:	00f777b3          	and	a5,a4,a5
   12c70:	01241503          	lh	a0,18(s0)
   12c74:	00f41823          	sh	a5,16(s0)
   12c78:	00048593          	mv	a1,s1
   12c7c:	02813083          	ld	ra,40(sp)
   12c80:	02013403          	ld	s0,32(sp)
   12c84:	01813483          	ld	s1,24(sp)
   12c88:	00068613          	mv	a2,a3
   12c8c:	03010113          	addi	sp,sp,48
   12c90:	20c0006f          	j	12e9c <write>

0000000000012c94 <__sseek>:
   12c94:	01259503          	lh	a0,18(a1)
   12c98:	ff010113          	addi	sp,sp,-16
   12c9c:	00813023          	sd	s0,0(sp)
   12ca0:	00058413          	mv	s0,a1
   12ca4:	00060593          	mv	a1,a2
   12ca8:	00068613          	mv	a2,a3
   12cac:	00113423          	sd	ra,8(sp)
   12cb0:	1c4000ef          	jal	12e74 <lseek>
   12cb4:	fff00793          	li	a5,-1
   12cb8:	01045703          	lhu	a4,16(s0)
   12cbc:	02f50263          	beq	a0,a5,12ce0 <__sseek+0x4c>
   12cc0:	00813083          	ld	ra,8(sp)
   12cc4:	000017b7          	lui	a5,0x1
   12cc8:	00f767b3          	or	a5,a4,a5
   12ccc:	08a43823          	sd	a0,144(s0)
   12cd0:	00f41823          	sh	a5,16(s0)
   12cd4:	00013403          	ld	s0,0(sp)
   12cd8:	01010113          	addi	sp,sp,16
   12cdc:	00008067          	ret
   12ce0:	fffff7b7          	lui	a5,0xfffff
   12ce4:	00813083          	ld	ra,8(sp)
   12ce8:	fff7879b          	addiw	a5,a5,-1
   12cec:	00f777b3          	and	a5,a4,a5
   12cf0:	00f41823          	sh	a5,16(s0)
   12cf4:	00013403          	ld	s0,0(sp)
   12cf8:	01010113          	addi	sp,sp,16
   12cfc:	00008067          	ret

0000000000012d00 <__sclose>:
   12d00:	01259503          	lh	a0,18(a1)
   12d04:	2440006f          	j	12f48 <close>

0000000000012d08 <_fclose_r>:
   12d08:	0e058e63          	beqz	a1,12e04 <_fclose_r+0xfc>
   12d0c:	fe010113          	addi	sp,sp,-32
   12d10:	00813823          	sd	s0,16(sp)
   12d14:	00913423          	sd	s1,8(sp)
   12d18:	00113c23          	sd	ra,24(sp)
   12d1c:	01213023          	sd	s2,0(sp)
   12d20:	00050493          	mv	s1,a0
   12d24:	00058413          	mv	s0,a1
   12d28:	00050663          	beqz	a0,12d34 <_fclose_r+0x2c>
   12d2c:	05052783          	lw	a5,80(a0)
   12d30:	0a078a63          	beqz	a5,12de4 <_fclose_r+0xdc>
   12d34:	01041783          	lh	a5,16(s0)
   12d38:	00000513          	li	a0,0
   12d3c:	00079e63          	bnez	a5,12d58 <_fclose_r+0x50>
   12d40:	01813083          	ld	ra,24(sp)
   12d44:	01013403          	ld	s0,16(sp)
   12d48:	00813483          	ld	s1,8(sp)
   12d4c:	00013903          	ld	s2,0(sp)
   12d50:	02010113          	addi	sp,sp,32
   12d54:	00008067          	ret
   12d58:	00040593          	mv	a1,s0
   12d5c:	00048513          	mv	a0,s1
   12d60:	fe1fe0ef          	jal	11d40 <__sflush_r>
   12d64:	05043783          	ld	a5,80(s0)
   12d68:	00050913          	mv	s2,a0
   12d6c:	00078a63          	beqz	a5,12d80 <_fclose_r+0x78>
   12d70:	03043583          	ld	a1,48(s0)
   12d74:	00048513          	mv	a0,s1
   12d78:	000780e7          	jalr	a5
   12d7c:	06054863          	bltz	a0,12dec <_fclose_r+0xe4>
   12d80:	01045783          	lhu	a5,16(s0)
   12d84:	0807f793          	andi	a5,a5,128
   12d88:	06079663          	bnez	a5,12df4 <_fclose_r+0xec>
   12d8c:	05843583          	ld	a1,88(s0)
   12d90:	00058c63          	beqz	a1,12da8 <_fclose_r+0xa0>
   12d94:	07440793          	addi	a5,s0,116
   12d98:	00f58663          	beq	a1,a5,12da4 <_fclose_r+0x9c>
   12d9c:	00048513          	mv	a0,s1
   12da0:	f10ff0ef          	jal	124b0 <_free_r>
   12da4:	04043c23          	sd	zero,88(s0)
   12da8:	07843583          	ld	a1,120(s0)
   12dac:	00058863          	beqz	a1,12dbc <_fclose_r+0xb4>
   12db0:	00048513          	mv	a0,s1
   12db4:	efcff0ef          	jal	124b0 <_free_r>
   12db8:	06043c23          	sd	zero,120(s0)
   12dbc:	dacff0ef          	jal	12368 <__sfp_lock_acquire>
   12dc0:	00041823          	sh	zero,16(s0)
   12dc4:	da8ff0ef          	jal	1236c <__sfp_lock_release>
   12dc8:	01813083          	ld	ra,24(sp)
   12dcc:	00090513          	mv	a0,s2
   12dd0:	01013403          	ld	s0,16(sp)
   12dd4:	00813483          	ld	s1,8(sp)
   12dd8:	00013903          	ld	s2,0(sp)
   12ddc:	02010113          	addi	sp,sp,32
   12de0:	00008067          	ret
   12de4:	d74ff0ef          	jal	12358 <__sinit>
   12de8:	f4dff06f          	j	12d34 <_fclose_r+0x2c>
   12dec:	fff00913          	li	s2,-1
   12df0:	f91ff06f          	j	12d80 <_fclose_r+0x78>
   12df4:	01843583          	ld	a1,24(s0)
   12df8:	00048513          	mv	a0,s1
   12dfc:	eb4ff0ef          	jal	124b0 <_free_r>
   12e00:	f8dff06f          	j	12d8c <_fclose_r+0x84>
   12e04:	00000513          	li	a0,0
   12e08:	00008067          	ret

0000000000012e0c <fclose>:
   12e0c:	00050593          	mv	a1,a0
   12e10:	8101b503          	ld	a0,-2032(gp) # 14b40 <_impure_ptr>
   12e14:	ef5ff06f          	j	12d08 <_fclose_r>

0000000000012e18 <__syscall_error>:
   12e18:	ff010113          	addi	sp,sp,-16
   12e1c:	00113423          	sd	ra,8(sp)
   12e20:	00813023          	sd	s0,0(sp)
   12e24:	00050413          	mv	s0,a0
   12e28:	3c0000ef          	jal	131e8 <__errno>
   12e2c:	00813083          	ld	ra,8(sp)
   12e30:	408007bb          	negw	a5,s0
   12e34:	00f52023          	sw	a5,0(a0)
   12e38:	00013403          	ld	s0,0(sp)
   12e3c:	fff00513          	li	a0,-1
   12e40:	01010113          	addi	sp,sp,16
   12e44:	00008067          	ret

0000000000012e48 <open>:
   12e48:	00000693          	li	a3,0
   12e4c:	40000893          	li	a7,1024
   12e50:	00000073          	ecall
   12e54:	fc0542e3          	bltz	a0,12e18 <__syscall_error>
   12e58:	0005051b          	sext.w	a0,a0
   12e5c:	00008067          	ret

0000000000012e60 <openat>:
   12e60:	03800893          	li	a7,56
   12e64:	00000073          	ecall
   12e68:	fa0548e3          	bltz	a0,12e18 <__syscall_error>
   12e6c:	0005051b          	sext.w	a0,a0
   12e70:	00008067          	ret

0000000000012e74 <lseek>:
   12e74:	00000693          	li	a3,0
   12e78:	03e00893          	li	a7,62
   12e7c:	00000073          	ecall
   12e80:	f8054ce3          	bltz	a0,12e18 <__syscall_error>
   12e84:	00008067          	ret

0000000000012e88 <read>:
   12e88:	00000693          	li	a3,0
   12e8c:	03f00893          	li	a7,63
   12e90:	00000073          	ecall
   12e94:	f80542e3          	bltz	a0,12e18 <__syscall_error>
   12e98:	00008067          	ret

0000000000012e9c <write>:
   12e9c:	00000693          	li	a3,0
   12ea0:	04000893          	li	a7,64
   12ea4:	00000073          	ecall
   12ea8:	f60548e3          	bltz	a0,12e18 <__syscall_error>
   12eac:	00008067          	ret

0000000000012eb0 <fstat>:
   12eb0:	00000613          	li	a2,0
   12eb4:	00000693          	li	a3,0
   12eb8:	05000893          	li	a7,80
   12ebc:	00000073          	ecall
   12ec0:	f4054ce3          	bltz	a0,12e18 <__syscall_error>
   12ec4:	0005051b          	sext.w	a0,a0
   12ec8:	00008067          	ret

0000000000012ecc <stat>:
   12ecc:	00000613          	li	a2,0
   12ed0:	00000693          	li	a3,0
   12ed4:	40e00893          	li	a7,1038
   12ed8:	00000073          	ecall
   12edc:	f2054ee3          	bltz	a0,12e18 <__syscall_error>
   12ee0:	0005051b          	sext.w	a0,a0
   12ee4:	00008067          	ret

0000000000012ee8 <lstat>:
   12ee8:	00000613          	li	a2,0
   12eec:	00000693          	li	a3,0
   12ef0:	40f00893          	li	a7,1039
   12ef4:	00000073          	ecall
   12ef8:	f20540e3          	bltz	a0,12e18 <__syscall_error>
   12efc:	0005051b          	sext.w	a0,a0
   12f00:	00008067          	ret

0000000000012f04 <fstatat>:
   12f04:	04f00893          	li	a7,79
   12f08:	00000073          	ecall
   12f0c:	f00546e3          	bltz	a0,12e18 <__syscall_error>
   12f10:	0005051b          	sext.w	a0,a0
   12f14:	00008067          	ret

0000000000012f18 <access>:
   12f18:	00000613          	li	a2,0
   12f1c:	00000693          	li	a3,0
   12f20:	40900893          	li	a7,1033
   12f24:	00000073          	ecall
   12f28:	ee0548e3          	bltz	a0,12e18 <__syscall_error>
   12f2c:	0005051b          	sext.w	a0,a0
   12f30:	00008067          	ret

0000000000012f34 <faccessat>:
   12f34:	03000893          	li	a7,48
   12f38:	00000073          	ecall
   12f3c:	ec054ee3          	bltz	a0,12e18 <__syscall_error>
   12f40:	0005051b          	sext.w	a0,a0
   12f44:	00008067          	ret

0000000000012f48 <close>:
   12f48:	00000593          	li	a1,0
   12f4c:	00000613          	li	a2,0
   12f50:	00000693          	li	a3,0
   12f54:	03900893          	li	a7,57
   12f58:	00000073          	ecall
   12f5c:	ea054ee3          	bltz	a0,12e18 <__syscall_error>
   12f60:	0005051b          	sext.w	a0,a0
   12f64:	00008067          	ret

0000000000012f68 <link>:
   12f68:	00000613          	li	a2,0
   12f6c:	00000693          	li	a3,0
   12f70:	40100893          	li	a7,1025
   12f74:	00000073          	ecall
   12f78:	ea0540e3          	bltz	a0,12e18 <__syscall_error>
   12f7c:	0005051b          	sext.w	a0,a0
   12f80:	00008067          	ret

0000000000012f84 <unlink>:
   12f84:	00000593          	li	a1,0
   12f88:	00000613          	li	a2,0
   12f8c:	00000693          	li	a3,0
   12f90:	40200893          	li	a7,1026
   12f94:	00000073          	ecall
   12f98:	e80540e3          	bltz	a0,12e18 <__syscall_error>
   12f9c:	0005051b          	sext.w	a0,a0
   12fa0:	00008067          	ret

0000000000012fa4 <execve>:
   12fa4:	ff010113          	addi	sp,sp,-16
   12fa8:	00113423          	sd	ra,8(sp)
   12fac:	23c000ef          	jal	131e8 <__errno>
   12fb0:	00813083          	ld	ra,8(sp)
   12fb4:	00c00793          	li	a5,12
   12fb8:	00f52023          	sw	a5,0(a0)
   12fbc:	01010113          	addi	sp,sp,16
   12fc0:	fff00513          	li	a0,-1
   12fc4:	00008067          	ret

0000000000012fc8 <fork>:
   12fc8:	ff010113          	addi	sp,sp,-16
   12fcc:	00113423          	sd	ra,8(sp)
   12fd0:	218000ef          	jal	131e8 <__errno>
   12fd4:	00813083          	ld	ra,8(sp)
   12fd8:	00b00793          	li	a5,11
   12fdc:	00f52023          	sw	a5,0(a0)
   12fe0:	01010113          	addi	sp,sp,16
   12fe4:	fff00513          	li	a0,-1
   12fe8:	00008067          	ret

0000000000012fec <getpid>:
   12fec:	00100513          	li	a0,1
   12ff0:	00008067          	ret

0000000000012ff4 <kill>:
   12ff4:	ff010113          	addi	sp,sp,-16
   12ff8:	00113423          	sd	ra,8(sp)
   12ffc:	1ec000ef          	jal	131e8 <__errno>
   13000:	00813083          	ld	ra,8(sp)
   13004:	01600793          	li	a5,22
   13008:	00f52023          	sw	a5,0(a0)
   1300c:	01010113          	addi	sp,sp,16
   13010:	fff00513          	li	a0,-1
   13014:	00008067          	ret

0000000000013018 <wait>:
   13018:	ff010113          	addi	sp,sp,-16
   1301c:	00113423          	sd	ra,8(sp)
   13020:	1c8000ef          	jal	131e8 <__errno>
   13024:	00813083          	ld	ra,8(sp)
   13028:	00a00793          	li	a5,10
   1302c:	00f52023          	sw	a5,0(a0)
   13030:	01010113          	addi	sp,sp,16
   13034:	fff00513          	li	a0,-1
   13038:	00008067          	ret

000000000001303c <isatty>:
   1303c:	f8010113          	addi	sp,sp,-128
   13040:	00010593          	mv	a1,sp
   13044:	00000613          	li	a2,0
   13048:	00000693          	li	a3,0
   1304c:	05000893          	li	a7,80
   13050:	00000073          	ecall
   13054:	dc0542e3          	bltz	a0,12e18 <__syscall_error>
   13058:	fff00793          	li	a5,-1
   1305c:	0005051b          	sext.w	a0,a0
   13060:	00f50863          	beq	a0,a5,13070 <isatty+0x34>
   13064:	01012503          	lw	a0,16(sp)
   13068:	40d5551b          	sraiw	a0,a0,0xd
   1306c:	00157513          	andi	a0,a0,1
   13070:	08010113          	addi	sp,sp,128
   13074:	00008067          	ret

0000000000013078 <times>:
   13078:	8c018313          	addi	t1,gp,-1856 # 14bf0 <t0.2343>
   1307c:	00033703          	ld	a4,0(t1)
   13080:	ff010113          	addi	sp,sp,-16
   13084:	00050813          	mv	a6,a0
   13088:	02071063          	bnez	a4,130a8 <times+0x30>
   1308c:	8c018513          	addi	a0,gp,-1856 # 14bf0 <t0.2343>
   13090:	00000593          	li	a1,0
   13094:	00000613          	li	a2,0
   13098:	00000693          	li	a3,0
   1309c:	0a900893          	li	a7,169
   130a0:	00000073          	ecall
   130a4:	d6054ae3          	bltz	a0,12e18 <__syscall_error>
   130a8:	00010513          	mv	a0,sp
   130ac:	00000593          	li	a1,0
   130b0:	00000613          	li	a2,0
   130b4:	00000693          	li	a3,0
   130b8:	0a900893          	li	a7,169
   130bc:	00000073          	ecall
   130c0:	d4054ce3          	bltz	a0,12e18 <__syscall_error>
   130c4:	00033703          	ld	a4,0(t1)
   130c8:	00013783          	ld	a5,0(sp)
   130cc:	fff00513          	li	a0,-1
   130d0:	00083823          	sd	zero,16(a6)
   130d4:	40e786b3          	sub	a3,a5,a4
   130d8:	000f47b7          	lui	a5,0xf4
   130dc:	24078793          	addi	a5,a5,576 # f4240 <_gp+0xdef10>
   130e0:	02f68733          	mul	a4,a3,a5
   130e4:	00833683          	ld	a3,8(t1)
   130e8:	00813783          	ld	a5,8(sp)
   130ec:	00083c23          	sd	zero,24(a6)
   130f0:	00083423          	sd	zero,8(a6)
   130f4:	40d787b3          	sub	a5,a5,a3
   130f8:	01010113          	addi	sp,sp,16
   130fc:	00f707b3          	add	a5,a4,a5
   13100:	00f83023          	sd	a5,0(a6)
   13104:	00008067          	ret

0000000000013108 <gettimeofday>:
   13108:	00000593          	li	a1,0
   1310c:	00000613          	li	a2,0
   13110:	00000693          	li	a3,0
   13114:	0a900893          	li	a7,169
   13118:	00000073          	ecall
   1311c:	ce054ee3          	bltz	a0,12e18 <__syscall_error>
   13120:	0005051b          	sext.w	a0,a0
   13124:	00008067          	ret

0000000000013128 <ftime>:
   13128:	00051423          	sh	zero,8(a0)
   1312c:	00053023          	sd	zero,0(a0)
   13130:	00000513          	li	a0,0
   13134:	00008067          	ret

0000000000013138 <utime>:
   13138:	fff00513          	li	a0,-1
   1313c:	00008067          	ret

0000000000013140 <chown>:
   13140:	fff00513          	li	a0,-1
   13144:	00008067          	ret

0000000000013148 <chmod>:
   13148:	fff00513          	li	a0,-1
   1314c:	00008067          	ret

0000000000013150 <chdir>:
   13150:	fff00513          	li	a0,-1
   13154:	00008067          	ret

0000000000013158 <getcwd>:
   13158:	00000513          	li	a0,0
   1315c:	00008067          	ret

0000000000013160 <sysconf>:
   13160:	00200793          	li	a5,2
   13164:	00f51863          	bne	a0,a5,13174 <sysconf+0x14>
   13168:	000f4537          	lui	a0,0xf4
   1316c:	24050513          	addi	a0,a0,576 # f4240 <_gp+0xdef10>
   13170:	00008067          	ret
   13174:	fff00513          	li	a0,-1
   13178:	00008067          	ret

000000000001317c <sbrk>:
   1317c:	8581b703          	ld	a4,-1960(gp) # 14b88 <heap_end.2381>
   13180:	00050793          	mv	a5,a0
   13184:	00071663          	bnez	a4,13190 <sbrk+0x14>
   13188:	8d018713          	addi	a4,gp,-1840 # 14c00 <_end>
   1318c:	84e1bc23          	sd	a4,-1960(gp) # 14b88 <heap_end.2381>
   13190:	00e78533          	add	a0,a5,a4
   13194:	00000593          	li	a1,0
   13198:	00000613          	li	a2,0
   1319c:	00000693          	li	a3,0
   131a0:	0d600893          	li	a7,214
   131a4:	00000073          	ecall
   131a8:	c60548e3          	bltz	a0,12e18 <__syscall_error>
   131ac:	8581b683          	ld	a3,-1960(gp) # 14b88 <heap_end.2381>
   131b0:	fff00713          	li	a4,-1
   131b4:	00d787b3          	add	a5,a5,a3
   131b8:	00f51663          	bne	a0,a5,131c4 <sbrk+0x48>
   131bc:	84a1bc23          	sd	a0,-1960(gp) # 14b88 <heap_end.2381>
   131c0:	00068713          	mv	a4,a3
   131c4:	00070513          	mv	a0,a4
   131c8:	00008067          	ret

00000000000131cc <_exit>:
   131cc:	00000593          	li	a1,0
   131d0:	00000613          	li	a2,0
   131d4:	00000693          	li	a3,0
   131d8:	05d00893          	li	a7,93
   131dc:	00000073          	ecall
   131e0:	c2054ce3          	bltz	a0,12e18 <__syscall_error>
   131e4:	0000006f          	j	131e4 <_exit+0x18>

00000000000131e8 <__errno>:
   131e8:	8101b503          	ld	a0,-2032(gp) # 14b40 <_impure_ptr>
   131ec:	00008067          	ret
