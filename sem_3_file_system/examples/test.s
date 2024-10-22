
a.out:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 d9 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fd9]        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 6a 2f 00 00    	push   QWORD PTR [rip+0x2f6a]        # 3f90 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 6b 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f6b]        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nop    DWORD PTR [rax]
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	push   0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	push   0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmp 1020 <_init+0x20>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	push   0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmp 1020 <_init+0x20>
    109f:	90                   	nop

Disassembly of section .plt.got:

00000000000010a0 <__cxa_finalize@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 4d 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f4d]        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    10ab:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .plt.sec:

00000000000010b0 <__errno_location@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 e5 2e 00 00 	bnd jmp QWORD PTR [rip+0x2ee5]        # 3fa0 <__errno_location@GLIBC_2.2.5>
    10bb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010c0 <puts@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 dd 2e 00 00 	bnd jmp QWORD PTR [rip+0x2edd]        # 3fa8 <puts@GLIBC_2.2.5>
    10cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010d0 <printf@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 d5 2e 00 00 	bnd jmp QWORD PTR [rip+0x2ed5]        # 3fb0 <printf@GLIBC_2.2.5>
    10db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010e0 <close@plt>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	f2 ff 25 cd 2e 00 00 	bnd jmp QWORD PTR [rip+0x2ecd]        # 3fb8 <close@GLIBC_2.2.5>
    10eb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010f0 <open@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 c5 2e 00 00 	bnd jmp QWORD PTR [rip+0x2ec5]        # 3fc0 <open@GLIBC_2.2.5>
    10fb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001100 <perror@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 bd 2e 00 00 	bnd jmp QWORD PTR [rip+0x2ebd]        # 3fc8 <perror@GLIBC_2.2.5>
    110b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001110 <exit@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 b5 2e 00 00 	bnd jmp QWORD PTR [rip+0x2eb5]        # 3fd0 <exit@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .text:

0000000000001120 <_start>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	31 ed                	xor    ebp,ebp
    1126:	49 89 d1             	mov    r9,rdx
    1129:	5e                   	pop    rsi
    112a:	48 89 e2             	mov    rdx,rsp
    112d:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
    1131:	50                   	push   rax
    1132:	54                   	push   rsp
    1133:	45 31 c0             	xor    r8d,r8d
    1136:	31 c9                	xor    ecx,ecx
    1138:	48 8d 3d ca 00 00 00 	lea    rdi,[rip+0xca]        # 1209 <main>
    113f:	ff 15 93 2e 00 00    	call   QWORD PTR [rip+0x2e93]        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1145:	f4                   	hlt    
    1146:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    114d:	00 00 00 

0000000000001150 <deregister_tm_clones>:
    1150:	48 8d 3d b9 2e 00 00 	lea    rdi,[rip+0x2eb9]        # 4010 <__TMC_END__>
    1157:	48 8d 05 b2 2e 00 00 	lea    rax,[rip+0x2eb2]        # 4010 <__TMC_END__>
    115e:	48 39 f8             	cmp    rax,rdi
    1161:	74 15                	je     1178 <deregister_tm_clones+0x28>
    1163:	48 8b 05 76 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e76]        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    116a:	48 85 c0             	test   rax,rax
    116d:	74 09                	je     1178 <deregister_tm_clones+0x28>
    116f:	ff e0                	jmp    rax
    1171:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1178:	c3                   	ret    
    1179:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001180 <register_tm_clones>:
    1180:	48 8d 3d 89 2e 00 00 	lea    rdi,[rip+0x2e89]        # 4010 <__TMC_END__>
    1187:	48 8d 35 82 2e 00 00 	lea    rsi,[rip+0x2e82]        # 4010 <__TMC_END__>
    118e:	48 29 fe             	sub    rsi,rdi
    1191:	48 89 f0             	mov    rax,rsi
    1194:	48 c1 ee 3f          	shr    rsi,0x3f
    1198:	48 c1 f8 03          	sar    rax,0x3
    119c:	48 01 c6             	add    rsi,rax
    119f:	48 d1 fe             	sar    rsi,1
    11a2:	74 14                	je     11b8 <register_tm_clones+0x38>
    11a4:	48 8b 05 45 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e45]        # 3ff0 <_ITM_registerTMCloneTable@Base>
    11ab:	48 85 c0             	test   rax,rax
    11ae:	74 08                	je     11b8 <register_tm_clones+0x38>
    11b0:	ff e0                	jmp    rax
    11b2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    11b8:	c3                   	ret    
    11b9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000011c0 <__do_global_dtors_aux>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	80 3d 45 2e 00 00 00 	cmp    BYTE PTR [rip+0x2e45],0x0        # 4010 <__TMC_END__>
    11cb:	75 2b                	jne    11f8 <__do_global_dtors_aux+0x38>
    11cd:	55                   	push   rbp
    11ce:	48 83 3d 22 2e 00 00 	cmp    QWORD PTR [rip+0x2e22],0x0        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    11d5:	00 
    11d6:	48 89 e5             	mov    rbp,rsp
    11d9:	74 0c                	je     11e7 <__do_global_dtors_aux+0x27>
    11db:	48 8b 3d 26 2e 00 00 	mov    rdi,QWORD PTR [rip+0x2e26]        # 4008 <__dso_handle>
    11e2:	e8 b9 fe ff ff       	call   10a0 <__cxa_finalize@plt>
    11e7:	e8 64 ff ff ff       	call   1150 <deregister_tm_clones>
    11ec:	c6 05 1d 2e 00 00 01 	mov    BYTE PTR [rip+0x2e1d],0x1        # 4010 <__TMC_END__>
    11f3:	5d                   	pop    rbp
    11f4:	c3                   	ret    
    11f5:	0f 1f 00             	nop    DWORD PTR [rax]
    11f8:	c3                   	ret    
    11f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001200 <frame_dummy>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	e9 77 ff ff ff       	jmp    1180 <register_tm_clones>

0000000000001209 <main>:
    1209:	f3 0f 1e fa          	endbr64 
    120d:	55                   	push   rbp
    120e:	48 89 e5             	mov    rbp,rsp
    1211:	48 83 ec 10          	sub    rsp,0x10
    1215:	be 40 00 00 00       	mov    esi,0x40
    121a:	48 8d 05 e3 0d 00 00 	lea    rax,[rip+0xde3]        # 2004 <_IO_stdin_used+0x4>
    1221:	48 89 c7             	mov    rdi,rax
    1224:	b8 00 00 00 00       	mov    eax,0x0
    1229:	e8 c2 fe ff ff       	call   10f0 <open@plt>
    122e:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
    1231:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
    1234:	89 c6                	mov    esi,eax
    1236:	48 8d 05 d0 0d 00 00 	lea    rax,[rip+0xdd0]        # 200d <_IO_stdin_used+0xd>
    123d:	48 89 c7             	mov    rdi,rax
    1240:	b8 00 00 00 00       	mov    eax,0x0
    1245:	e8 86 fe ff ff       	call   10d0 <printf@plt>
    124a:	83 7d fc ff          	cmp    DWORD PTR [rbp-0x4],0xffffffff
    124e:	75 36                	jne    1286 <main+0x7d>
    1250:	e8 5b fe ff ff       	call   10b0 <__errno_location@plt>
    1255:	8b 00                	mov    eax,DWORD PTR [rax]
    1257:	89 c6                	mov    esi,eax
    1259:	48 8d 05 b6 0d 00 00 	lea    rax,[rip+0xdb6]        # 2016 <_IO_stdin_used+0x16>
    1260:	48 89 c7             	mov    rdi,rax
    1263:	b8 00 00 00 00       	mov    eax,0x0
    1268:	e8 63 fe ff ff       	call   10d0 <printf@plt>
    126d:	48 8d 05 b4 0d 00 00 	lea    rax,[rip+0xdb4]        # 2028 <_IO_stdin_used+0x28>
    1274:	48 89 c7             	mov    rdi,rax
    1277:	e8 84 fe ff ff       	call   1100 <perror@plt>
    127c:	bf 01 00 00 00       	mov    edi,0x1
    1281:	e8 8a fe ff ff       	call   1110 <exit@plt>
    1286:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
    1289:	89 c7                	mov    edi,eax
    128b:	e8 50 fe ff ff       	call   10e0 <close@plt>
    1290:	c1 e8 1f             	shr    eax,0x1f
    1293:	84 c0                	test   al,al
    1295:	74 19                	je     12b0 <main+0xa7>
    1297:	48 8d 05 92 0d 00 00 	lea    rax,[rip+0xd92]        # 2030 <_IO_stdin_used+0x30>
    129e:	48 89 c7             	mov    rdi,rax
    12a1:	e8 5a fe ff ff       	call   1100 <perror@plt>
    12a6:	bf 01 00 00 00       	mov    edi,0x1
    12ab:	e8 60 fe ff ff       	call   1110 <exit@plt>
    12b0:	48 8d 05 80 0d 00 00 	lea    rax,[rip+0xd80]        # 2037 <_IO_stdin_used+0x37>
    12b7:	48 89 c7             	mov    rdi,rax
    12ba:	e8 01 fe ff ff       	call   10c0 <puts@plt>
    12bf:	b8 00 00 00 00       	mov    eax,0x0
    12c4:	c9                   	leave  
    12c5:	c3                   	ret    

Disassembly of section .fini:

00000000000012c8 <_fini>:
    12c8:	f3 0f 1e fa          	endbr64 
    12cc:	48 83 ec 08          	sub    rsp,0x8
    12d0:	48 83 c4 08          	add    rsp,0x8
    12d4:	c3                   	ret    
