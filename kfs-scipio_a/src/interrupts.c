/*
** interrupts.c for interrupts in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Fri Nov 27 16:24:06 2015 Alexandre SCIPION
** Last update Sun Nov 29 23:11:07 2015 Alexandre SCIPION
*/

#include "interrupts.h"

void *memset(void *s, int c, uint32_t n)
{
	uint8_t* p = s;

	while (n--)
		*p++ = (uint8_t)c;

	return s;
}

void interrupts_init(void)
{
	idt_ptr.limit = sizeof(regs_t) * 256 - 1;
	idt_ptr.base = (uint32_t)&idt_entries;
	memset(&idt_entries, 0, sizeof(regs_t) * 256);

	__asm__ volatile("lidt %0\n": : "m" (idt_ptr): "memory");

	return ;
}
