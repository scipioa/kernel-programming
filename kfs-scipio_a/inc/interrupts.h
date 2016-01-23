/*
** interrupts.h for interrupts in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Fri Nov 27 16:24:06 2015 Alexandre SCIPION
** Last update Sat Jan 23 13:25:49 2016 Alexandre SCIPION
*/

#ifndef INTERRUPTS_H_
# define INTERRUPTS_H_

# include "types.h"

typedef struct regs
{
	uint16_t base_lo;
	uint16_t sel;
	uint8_t	always0;
	uint8_t flags;
	uint16_t base_hi;
} __attribute__((packed)) regs_t;

typedef struct idt_ptr
{
	uint16_t limit;
	uint32_t base;
} __attribute__((packed)) idt_ptr_t;

typedef struct register_s
{
  uint32_t ds;
  uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint32_t int_no, err_code;
  uint32_t eip, cs, eflags, useresp, ss;
} __attribute__((packed)) register_t; 

/* typedef int (*irq_handler)(struct regs* regs); */
typedef uint32_t isr_handler;

void interrupts_init(void);
void interrupts_set_isr(int n, isr_handler handler, int flags); /* isr_handler ? */
void irq_handler(register_t regs);

regs_t idt_entries[256];
idt_ptr_t idt_ptr;

extern void isr0 ();
extern void isr1 ();
extern void isr2 ();
extern void isr3 ();
extern void isr4 ();
extern void isr5 ();
extern void isr6 ();
extern void isr7 ();
extern void isr8 ();
extern void isr9 ();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

#endif /* !INTERRUPTS_H_ */
