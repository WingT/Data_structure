
a.out:     file format elf64-x86-64


Disassembly of section .init:

0000000000400428 <_init>:
  400428:	48 83 ec 08          	sub    $0x8,%rsp
  40042c:	48 8b 05 c5 0b 20 00 	mov    0x200bc5(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d8>
  400433:	48 85 c0             	test   %rax,%rax
  400436:	74 02                	je     40043a <_init+0x12>
  400438:	ff d0                	callq  *%rax
  40043a:	48 83 c4 08          	add    $0x8,%rsp
  40043e:	c3                   	retq   

Disassembly of section .plt:

0000000000400440 <printf@plt-0x10>:
  400440:	ff 35 c2 0b 20 00    	pushq  0x200bc2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400446:	ff 25 c4 0b 20 00    	jmpq   *0x200bc4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40044c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400450 <printf@plt>:
  400450:	ff 25 c2 0b 20 00    	jmpq   *0x200bc2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400456:	68 00 00 00 00       	pushq  $0x0
  40045b:	e9 e0 ff ff ff       	jmpq   400440 <_init+0x18>

0000000000400460 <__isoc99_scanf@plt>:
  400460:	ff 25 ba 0b 20 00    	jmpq   *0x200bba(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400466:	68 01 00 00 00       	pushq  $0x1
  40046b:	e9 d0 ff ff ff       	jmpq   400440 <_init+0x18>

Disassembly of section .text:

0000000000400470 <_start>:
  400470:	31 ed                	xor    %ebp,%ebp
  400472:	49 89 d1             	mov    %rdx,%r9
  400475:	5e                   	pop    %rsi
  400476:	48 89 e2             	mov    %rsp,%rdx
  400479:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40047d:	50                   	push   %rax
  40047e:	54                   	push   %rsp
  40047f:	49 c7 c0 20 06 40 00 	mov    $0x400620,%r8
  400486:	48 c7 c1 b0 05 40 00 	mov    $0x4005b0,%rcx
  40048d:	48 c7 c7 66 05 40 00 	mov    $0x400566,%rdi
  400494:	ff 15 56 0b 20 00    	callq  *0x200b56(%rip)        # 600ff0 <_DYNAMIC+0x1d0>
  40049a:	f4                   	hlt    
  40049b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000004004a0 <deregister_tm_clones>:
  4004a0:	b8 3f 10 60 00       	mov    $0x60103f,%eax
  4004a5:	55                   	push   %rbp
  4004a6:	48 2d 38 10 60 00    	sub    $0x601038,%rax
  4004ac:	48 83 f8 0e          	cmp    $0xe,%rax
  4004b0:	48 89 e5             	mov    %rsp,%rbp
  4004b3:	76 1b                	jbe    4004d0 <deregister_tm_clones+0x30>
  4004b5:	b8 00 00 00 00       	mov    $0x0,%eax
  4004ba:	48 85 c0             	test   %rax,%rax
  4004bd:	74 11                	je     4004d0 <deregister_tm_clones+0x30>
  4004bf:	5d                   	pop    %rbp
  4004c0:	bf 38 10 60 00       	mov    $0x601038,%edi
  4004c5:	ff e0                	jmpq   *%rax
  4004c7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4004ce:	00 00 
  4004d0:	5d                   	pop    %rbp
  4004d1:	c3                   	retq   
  4004d2:	0f 1f 40 00          	nopl   0x0(%rax)
  4004d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4004dd:	00 00 00 

00000000004004e0 <register_tm_clones>:
  4004e0:	be 38 10 60 00       	mov    $0x601038,%esi
  4004e5:	55                   	push   %rbp
  4004e6:	48 81 ee 38 10 60 00 	sub    $0x601038,%rsi
  4004ed:	48 c1 fe 03          	sar    $0x3,%rsi
  4004f1:	48 89 e5             	mov    %rsp,%rbp
  4004f4:	48 89 f0             	mov    %rsi,%rax
  4004f7:	48 c1 e8 3f          	shr    $0x3f,%rax
  4004fb:	48 01 c6             	add    %rax,%rsi
  4004fe:	48 d1 fe             	sar    %rsi
  400501:	74 15                	je     400518 <register_tm_clones+0x38>
  400503:	b8 00 00 00 00       	mov    $0x0,%eax
  400508:	48 85 c0             	test   %rax,%rax
  40050b:	74 0b                	je     400518 <register_tm_clones+0x38>
  40050d:	5d                   	pop    %rbp
  40050e:	bf 38 10 60 00       	mov    $0x601038,%edi
  400513:	ff e0                	jmpq   *%rax
  400515:	0f 1f 00             	nopl   (%rax)
  400518:	5d                   	pop    %rbp
  400519:	c3                   	retq   
  40051a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400520 <__do_global_dtors_aux>:
  400520:	80 3d 11 0b 20 00 00 	cmpb   $0x0,0x200b11(%rip)        # 601038 <__TMC_END__>
  400527:	75 11                	jne    40053a <__do_global_dtors_aux+0x1a>
  400529:	55                   	push   %rbp
  40052a:	48 89 e5             	mov    %rsp,%rbp
  40052d:	e8 6e ff ff ff       	callq  4004a0 <deregister_tm_clones>
  400532:	5d                   	pop    %rbp
  400533:	c6 05 fe 0a 20 00 01 	movb   $0x1,0x200afe(%rip)        # 601038 <__TMC_END__>
  40053a:	f3 c3                	repz retq 
  40053c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400540 <frame_dummy>:
  400540:	bf 18 0e 60 00       	mov    $0x600e18,%edi
  400545:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400549:	75 05                	jne    400550 <frame_dummy+0x10>
  40054b:	eb 93                	jmp    4004e0 <register_tm_clones>
  40054d:	0f 1f 00             	nopl   (%rax)
  400550:	b8 00 00 00 00       	mov    $0x0,%eax
  400555:	48 85 c0             	test   %rax,%rax
  400558:	74 f1                	je     40054b <frame_dummy+0xb>
  40055a:	55                   	push   %rbp
  40055b:	48 89 e5             	mov    %rsp,%rbp
  40055e:	ff d0                	callq  *%rax
  400560:	5d                   	pop    %rbp
  400561:	e9 7a ff ff ff       	jmpq   4004e0 <register_tm_clones>

0000000000400566 <main>:
  400566:	55                   	push   %rbp
  400567:	48 89 e5             	mov    %rsp,%rbp
  40056a:	48 83 ec 10          	sub    $0x10,%rsp
  40056e:	eb 14                	jmp    400584 <main+0x1e>
  400570:	8b 45 f8             	mov    -0x8(%rbp),%eax
  400573:	89 c6                	mov    %eax,%esi
  400575:	bf 34 06 40 00       	mov    $0x400634,%edi
  40057a:	b8 00 00 00 00       	mov    $0x0,%eax
  40057f:	e8 cc fe ff ff       	callq  400450 <printf@plt>
  400584:	48 8d 45 f8          	lea    -0x8(%rbp),%rax
  400588:	48 89 c6             	mov    %rax,%rsi
  40058b:	bf 3d 06 40 00       	mov    $0x40063d,%edi
  400590:	b8 00 00 00 00       	mov    $0x0,%eax
  400595:	e8 c6 fe ff ff       	callq  400460 <__isoc99_scanf@plt>
  40059a:	89 45 fc             	mov    %eax,-0x4(%rbp)
  40059d:	83 7d fc ff          	cmpl   $0xffffffff,-0x4(%rbp)
  4005a1:	75 cd                	jne    400570 <main+0xa>
  4005a3:	b8 00 00 00 00       	mov    $0x0,%eax
  4005a8:	c9                   	leaveq 
  4005a9:	c3                   	retq   
  4005aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004005b0 <__libc_csu_init>:
  4005b0:	41 57                	push   %r15
  4005b2:	41 56                	push   %r14
  4005b4:	41 89 ff             	mov    %edi,%r15d
  4005b7:	41 55                	push   %r13
  4005b9:	41 54                	push   %r12
  4005bb:	4c 8d 25 46 08 20 00 	lea    0x200846(%rip),%r12        # 600e08 <__frame_dummy_init_array_entry>
  4005c2:	55                   	push   %rbp
  4005c3:	48 8d 2d 46 08 20 00 	lea    0x200846(%rip),%rbp        # 600e10 <__init_array_end>
  4005ca:	53                   	push   %rbx
  4005cb:	49 89 f6             	mov    %rsi,%r14
  4005ce:	49 89 d5             	mov    %rdx,%r13
  4005d1:	4c 29 e5             	sub    %r12,%rbp
  4005d4:	48 83 ec 08          	sub    $0x8,%rsp
  4005d8:	48 c1 fd 03          	sar    $0x3,%rbp
  4005dc:	e8 47 fe ff ff       	callq  400428 <_init>
  4005e1:	48 85 ed             	test   %rbp,%rbp
  4005e4:	74 20                	je     400606 <__libc_csu_init+0x56>
  4005e6:	31 db                	xor    %ebx,%ebx
  4005e8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4005ef:	00 
  4005f0:	4c 89 ea             	mov    %r13,%rdx
  4005f3:	4c 89 f6             	mov    %r14,%rsi
  4005f6:	44 89 ff             	mov    %r15d,%edi
  4005f9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4005fd:	48 83 c3 01          	add    $0x1,%rbx
  400601:	48 39 dd             	cmp    %rbx,%rbp
  400604:	75 ea                	jne    4005f0 <__libc_csu_init+0x40>
  400606:	48 83 c4 08          	add    $0x8,%rsp
  40060a:	5b                   	pop    %rbx
  40060b:	5d                   	pop    %rbp
  40060c:	41 5c                	pop    %r12
  40060e:	41 5d                	pop    %r13
  400610:	41 5e                	pop    %r14
  400612:	41 5f                	pop    %r15
  400614:	c3                   	retq   
  400615:	90                   	nop
  400616:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40061d:	00 00 00 

0000000000400620 <__libc_csu_fini>:
  400620:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400624 <_fini>:
  400624:	48 83 ec 08          	sub    $0x8,%rsp
  400628:	48 83 c4 08          	add    $0x8,%rsp
  40062c:	c3                   	retq   
