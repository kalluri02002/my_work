	.file	"pip.c"
	.text
	.section	.rodata
.LC0:
	.string	"filed fialed"
.LC1:
	.string	"writing was done long agao"
.LC2:
	.string	"reading was doen parent %s "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	pipe@PLT
	testl	%eax, %eax
	jns	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L2:
	call	fork@PLT
	movl	%eax, -124(%rbp)
	cmpl	$0, -124(%rbp)
	jle	.L3
	movl	-120(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movabsq	$2335523730424095083, %rax
	movq	%rax, -112(%rbp)
	movl	$1702257006, -104(%rbp)
	movw	$28261, -100(%rbp)
	movb	$0, -98(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	1(%rax), %rdx
	movl	-116(%rbp), %eax
	leaq	-112(%rbp), %rcx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	-116(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	jmp	.L4
.L3:
	movl	-116(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	-120(%rbp), %eax
	leaq	-112(%rbp), %rcx
	movl	$50, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-120(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
.L4:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
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
