[BITS 32]
	
global _start
_start:
	mov esp, _sys_stack
	jmp next	

ALIGN	4
multiboot:	
	MAGIC	equ	0x1BADB002
	FLAGS	equ	0x7

	dd MAGIC
	dd FLAGS
	dd -(MAGIC + FLAGS)
	
next:
	EXTERN main
	call main		;/* kernel entry point */
	jmp $

SECTION .bss
	resb 65536	;/* 64KBytes */

_sys_stack:	
