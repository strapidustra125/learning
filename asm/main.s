	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.globl	_Z6squarei
	.type	_Z6squarei, @function
_Z6squarei:
	push	rbp
	mov	rbp, rsp
	mov	DWORD PTR -4[rbp], edi
	mov	eax, DWORD PTR -4[rbp]
	imul	eax, eax
	pop	rbp
	ret
	.size	_Z6squarei, .-_Z6squarei
	.globl	main
	.type	main, @function
main:
	push	rbp
	mov	rbp, rsp
	mov	edi, 5
	call	_Z6squarei
	cmp	eax, 25
	sete	al
	movzx	eax, al
	pop	rbp
	ret
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
