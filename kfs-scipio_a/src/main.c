/*
** main.c for main in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Fri Oct 30 16:16:21 2015 Alexandre SCIPION
** Last update Sat Jan 23 02:55:31 2016 Alexandre SCIPION
*/

#include "segmentation.h"
#include "interrupts.h"
#include "text.h"
#include "types.h"

void main()
{
	init_serial();
	clean();
	printk("Scipio_a & Ngotru_t - Kernel Programming II\n\n");
	
	init_flat_gdt();
	interrupts_init();

	printk("\nTest send interrupts 9 ...   ");
	__asm__ volatile ("int $0x9");
	printk("\n");

	while (1);
	return ;
}
