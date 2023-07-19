	.file	"books.c"
	.text
	.globl	comparatorTitleAscending
	.type	comparatorTitleAscending, @function
comparatorTitleAscending:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edx
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	comparatorTitleAscending, .-comparatorTitleAscending
	.globl	comparatorTitleDescending
	.type	comparatorTitleDescending, @function
comparatorTitleDescending:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edx
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	comparatorTitleDescending, .-comparatorTitleDescending
	.globl	comparatorPagesAscending
	.type	comparatorPagesAscending, @function
comparatorPagesAscending:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %edx
	movq	-8(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	comparatorPagesAscending, .-comparatorPagesAscending
	.globl	comparatorPagesDescending
	.type	comparatorPagesDescending, @function
comparatorPagesDescending:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %edx
	movq	-16(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	comparatorPagesDescending, .-comparatorPagesDescending
	.globl	comparatorPriceAscending
	.type	comparatorPriceAscending, @function
comparatorPriceAscending:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC0(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L17
	movl	$0, %eax
	jmp	.L12
.L17:
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm1
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L18
	movl	$1, %eax
	jmp	.L12
.L18:
	movl	$-1, %eax
.L12:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	comparatorPriceAscending, .-comparatorPriceAscending
	.globl	comparatorPriceDescending
	.type	comparatorPriceDescending, @function
comparatorPriceDescending:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC0(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L27
	movl	$0, %eax
	jmp	.L22
.L27:
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm1
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L28
	movl	$1, %eax
	jmp	.L22
.L28:
	movl	$-1, %eax
.L22:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	comparatorPriceDescending, .-comparatorPriceDescending
	.globl	getComparator
	.type	getComparator, @function
getComparator:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -84(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	comparatorTitleAscending(%rip), %rax
	movq	%rax, -64(%rbp)
	leaq	comparatorTitleDescending(%rip), %rax
	movq	%rax, -56(%rbp)
	leaq	comparatorPagesAscending(%rip), %rax
	movq	%rax, -48(%rbp)
	leaq	comparatorPagesDescending(%rip), %rax
	movq	%rax, -40(%rbp)
	leaq	comparatorPriceAscending(%rip), %rax
	movq	%rax, -32(%rbp)
	leaq	comparatorPriceDescending(%rip), %rax
	movq	%rax, -24(%rbp)
	cmpl	$0, -84(%rbp)
	jle	.L30
	cmpl	$6, -84(%rbp)
	jg	.L30
	movl	-84(%rbp), %eax
	subl	$1, %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	jmp	.L31
.L30:
	movl	$0, %eax
.L31:
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L33
	call	__stack_chk_fail@PLT
.L33:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	getComparator, .-getComparator
	.globl	randomRange
	.type	randomRange, @function
randomRange:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, %edx
	movl	%esi, %eax
	movw	%dx, -20(%rbp)
	movw	%ax, -24(%rbp)
	call	rand@PLT
	movzwl	-24(%rbp), %edx
	addl	$1, %edx
	movzwl	-20(%rbp), %esi
	movl	%edx, %ecx
	subl	%esi, %ecx
	cltd
	idivl	%ecx
	movl	%edx, %eax
	movw	%ax, -4(%rbp)
	movzwl	-4(%rbp), %edx
	movzwl	-20(%rbp), %eax
	addl	%edx, %eax
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	randomRange, .-randomRange
	.globl	randRange
	.type	randRange, @function
randRange:
.LFB14:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movsd	%xmm0, -40(%rbp)
	movsd	%xmm1, -48(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movsd	-48(%rbp), %xmm0
	subsd	-40(%rbp), %xmm0
	movsd	-24(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	addsd	-40(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC3(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	%xmm1, -56(%rbp)
	fldl	-56(%rbp)
	leaq	-16(%rsp), %rsp
	fstpt	(%rsp)
	call	roundl@PLT
	addq	$16, %rsp
	fldt	.LC4(%rip)
	fdivrp	%st, %st(1)
	fstpl	-56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	randRange, .-randRange
	.globl	randLetter
	.type	randLetter, @function
randLetter:
.LFB15:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, %eax
	movb	%al, -20(%rbp)
	cmpb	$0, -20(%rbp)
	je	.L39
	movl	$65, %ebx
	jmp	.L40
.L39:
	movl	$97, %ebx
.L40:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1321528399, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$3, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$26, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%ebx, %eax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	randLetter, .-randLetter
	.globl	randString
	.type	randString, @function
randString:
.LFB16:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	%esi, %ecx
	movl	%edx, %eax
	movl	%ecx, %edx
	movw	%dx, -44(%rbp)
	movw	%ax, -48(%rbp)
	movzwl	-48(%rbp), %edx
	movzwl	-44(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	randomRange
	movw	%ax, -22(%rbp)
	movl	$1, %edi
	call	randLetter
	movq	-40(%rbp), %rdx
	movb	%al, (%rdx)
	movl	$1, -20(%rbp)
	jmp	.L43
.L44:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	$0, %edi
	call	randLetter
	movb	%al, (%rbx)
	addl	$1, -20(%rbp)
.L43:
	movzwl	-22(%rbp), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L44
	movzwl	-22(%rbp), %edx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	randString, .-randString
	.section	.rodata
.LC6:
	.string	"Title: %-22s  "
.LC7:
	.string	"Author: %-24s  "
.LC8:
	.string	"Pages: %-7d  "
.LC9:
	.string	"Price: %-7.2f  "
	.text
	.globl	printArr
	.type	printArr, @function
printArr:
.LFB17:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L46
.L47:
	movq	-8(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	addq	$101, %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %eax
	movl	%eax, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	208(%rax), %rax
	movq	%rax, %xmm0
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	addq	$1, -8(%rbp)
.L46:
	cmpq	$14, -8(%rbp)
	jbe	.L47
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	printArr, .-printArr
	.section	.rodata
	.align 16
.LC0:
	.long	-1
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC1:
	.long	-755914244
	.long	1062232653
	.align 8
.LC2:
	.long	-4194304
	.long	1105199103
	.align 8
.LC3:
	.long	0
	.long	1079574528
	.align 16
.LC4:
	.long	0
	.long	-939524096
	.long	16389
	.long	0
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
