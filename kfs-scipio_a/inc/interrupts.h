/*
** interrupts.h for interrupts in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Fri Nov 27 16:24:06 2015 Alexandre SCIPION
** Last update Sat Nov 28 12:18:18 2015 Alexandre SCIPION
*/

#ifndef INTERRUPTS_H_
# define INTERRUPTS_H_

# include "types.h"

typedef struct regs
{
	uint32_t ss;
} __attribute__((packed)) regs_t;

typedef struct idt_ptr
{
	uint32_t base;
	uint16_t limit;
} __attribute__((packed)) idt_ptr_t;

typedef int (*irq_handler)(struct regs* regs);

void interrupts_init(void);
/* void interrupts_set_isr(int n, isr_handler handler, int flags); */

regs_t idt_entries[256];
idt_ptr_t idt_ptr;

#endif /* !INTERRUPTS_H_ */
