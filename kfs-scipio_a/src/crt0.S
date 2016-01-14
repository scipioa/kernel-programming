[BITS 32]
	
global _start
	
_start:
	;; mov esp, _sys_stack
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

[GLOBAL _set_gdt]
_set_gdt:	
	mov eax, [esp+4]
	lgdt [eax]
	mov eax, cr0
	or al, 1
	mov cr0, eax

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush
.flush:
	ret

SECTION .bss
	align 32
_sys_stack:	
	resb STACKSIZE	;/* 64KBytes */
