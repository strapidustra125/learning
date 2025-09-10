_Z6squarei:
	push	rbp
	mov	rbp, rsp
	mov	DWORD PTR -4[rbp], edi
	mov	eax, DWORD PTR -4[rbp]
	imul	eax, eax
	pop	rbp
	ret
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
