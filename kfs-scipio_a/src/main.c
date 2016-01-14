/*
** main.c for main in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Fri Oct 30 16:16:21 2015 Alexandre SCIPION
** Last update Thu Jan 14 10:51:42 2016 Alexandre SCIPION
*/

#include "segmentation.h"
#include "text.h"

void main()
{
	init_serial();
	clean();
	printk("Scipio_a & Ngotru_t - Kernel Programming III\n\n");
	
	init_flat_gdt();

	while (1);
	return ;
}
