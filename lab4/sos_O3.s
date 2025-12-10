	.file	"sos.c"
	.text
	.p2align 4
	.globl	sq
	.type	sq, @function
sq:
.LFB39:
	.cfi_startproc
	movl	4(%esp), %eax
	imull	%eax, %eax
	ret
	.cfi_endproc
.LFE39:
	.size	sq, .-sq
	.p2align 4
	.globl	sos
	.type	sos, @function
sos:
.LFB40:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	8(%esp), %edx
	imull	%eax, %eax
	imull	%edx, %edx
	addl	%edx, %eax
	ret
	.cfi_endproc
.LFE40:
	.size	sos, .-sos
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"sos(%i,%i)=%i\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB41:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	subl	$12, %esp
	movl	4(%ecx), %edi
	pushl	$10
	pushl	$0
	pushl	4(%edi)
	call	strtol@PLT
	addl	$12, %esp
	pushl	$10
	movl	%eax, %esi
	pushl	$0
	pushl	8(%edi)
	call	strtol@PLT
	movl	%esi, %edx
	movl	%eax, %ecx
	imull	%esi, %edx
	imull	%eax, %ecx
	addl	%ecx, %edx
	movl	%edx, (%esp)
	pushl	%eax
	leal	.LC0@GOTOFF(%ebx), %eax
	pushl	%esi
	pushl	%eax
	pushl	$1
	call	__printf_chk@PLT
	addl	$32, %esp
	leal	-16(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE41:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB42:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE42:
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
