/*
** segmentation.c for segmentation in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Tue Nov 24 14:28:17 2015 Alexandre SCIPION
** Last update Tue Nov 24 18:08:15 2015 Alexandre SCIPION
*/

#include "segmentation.h"

int set_gdt_entry(int n, uint32_t base,
		  uint32_t limit,
		  uint8_t access,
		  uint8_t granularity)
{
	gdt_entries[n].base_low    = (base & 0xFFFF);
	gdt_entries[n].base_middle = (base >> 16) & 0xFF;
	gdt_entries[n].base_high   = (base >> 24) & 0xFF;
	gdt_entries[n].limit_low   = (limit & 0xFFFF);
	gdt_entries[n].granularity = (limit >> 16) & 0x0F;
	gdt_entries[n].granularity |= granularity & 0xF0;
	gdt_entries[n].access      = access;

	return 0;
}

void init_flat_gdt(void)
{
	gdt_ptr.base = (uint32_t)&gdt_entries;
	gdt_ptr.limit = (sizeof(gdt_entry_t) * 3) - 1;
	set_gdt_entry(0, 0, 0, 0, 0);
	set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	__asm__ volatile("lgdt %0\n": : "m" (gdt_ptr): "memory");

	return ;
}
