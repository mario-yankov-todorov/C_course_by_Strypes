	.file	"main.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"\nHow do you want the array to be sorted:"
	.align 8
.LC1:
	.string	"1 - Title Ascending  2 - Title Descending"
	.align 8
.LC2:
	.string	"3 - Pages Ascending  4 - Pages Descending"
	.align 8
.LC3:
	.string	"5 - Price Ascending  6 - Price Descending"
.LC4:
	.string	"Your choice: "
.LC5:
	.string	"%d"
.LC8:
	.string	"-------BEFORE SORTING-------"
	.align 8
.LC9:
	.string	"Sorry, you entered the wrong input!"
.LC10:
	.string	"Sorting could not be done!\n"
.LC11:
	.string	"-------AFTER SORTING-------"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$3288, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-3284(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$10, %edi
	call	putchar@PLT
	movq	$0, -3280(%rbp)
	jmp	.L2
.L3:
	leaq	-3264(%rbp), %rcx
	movq	-3280(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rcx, %rax
	movl	$21, %edx
	movl	$11, %esi
	movq	%rax, %rdi
	call	randString@PLT
	leaq	-3264(%rbp), %rcx
	movq	-3280(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	addq	$5, %rax
	movl	$11, %edx
	movl	$4, %esi
	movq	%rax, %rdi
	call	randString@PLT
	leaq	-3264(%rbp), %rcx
	movq	-3280(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	leaq	5(%rax), %rbx
	movq	%rbx, %rdi
	call	strlen@PLT
	addq	%rbx, %rax
	movw	$32, (%rax)
	leaq	-3264(%rbp), %rcx
	movq	-3280(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	leaq	5(%rax), %rbx
	leaq	-3264(%rbp), %rcx
	movq	-3280(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	addq	$5, %rax
	movq	%rax, %rdi
	call	strlen@PLT
	addq	%rbx, %rax
	movl	$11, %edx
	movl	$4, %esi
	movq	%rax, %rdi
	call	randString@PLT
	movl	$1000, %esi
	movl	$10, %edi
	call	randomRange@PLT
	movl	%eax, %edx
	movq	-3280(%rbp), %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,8), %rcx
	addq	%rcx, %rax
	salq	$3, %rax
	leaq	-16(%rax), %rax
	addq	%rbp, %rax
	subq	$3046, %rax
	movw	%dx, (%rax)
	movsd	.LC6(%rip), %xmm0
	movq	.LC7(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	randRange@PLT
	movq	%xmm0, %rdx
	movq	-3280(%rbp), %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,8), %rcx
	addq	%rcx, %rax
	salq	$3, %rax
	leaq	-16(%rax), %rax
	addq	%rbp, %rax
	subq	$3040, %rax
	movq	%rdx, (%rax)
	addq	$1, -3280(%rbp)
.L2:
	cmpq	$14, -3280(%rbp)
	jbe	.L3
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-3264(%rbp), %rax
	movq	%rax, %rdi
	call	printArr@PLT
	movl	$10, %edi
	call	putchar@PLT
	movl	-3284(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movq	%rax, -3272(%rbp)
	cmpq	$0, -3272(%rbp)
	je	.L4
	movl	-3284(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movq	%rax, %rdx
	leaq	-3264(%rbp), %rax
	movq	%rdx, %rcx
	movl	$216, %edx
	movl	$15, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-3264(%rbp), %rax
	movq	%rax, %rdi
	call	printArr@PLT
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	jmp	.L7
.L4:
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$27, %edx
	movl	$1, %esi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$10, %edi
	call	putchar@PLT
	movl	$1, %eax
.L7:
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC6:
	.long	0
	.long	1079574528
	.align 8
.LC7:
	.long	0
	.long	1073741824
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
