[BITS 32]
	
global _start
	
_start:
	jmp next	

ALIGN	4
multiboot:	
	MAGIC	equ	0x1BADB002
	FLAGS	equ	0x7

	dd MAGIC
	dd FLAGS
	dd -(MAGIC + FLAGS)
	dd next

STACKSIZE equ 65636

next:
	mov esp, _sys_stack + STACKSIZE
	EXTERN main
	call main		;/* kernel entry point */
	hlt

SECTION .bss
	align 32
_sys_stack:	
	resb STACKSIZE	;/* 64KBytes */
