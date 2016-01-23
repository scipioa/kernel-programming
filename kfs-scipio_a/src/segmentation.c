/*
** segmentation.c for segmentation in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Tue Nov 24 14:28:17 2015 Alexandre SCIPION
** Last update Tue Jan 19 10:57:38 2016 Alexandre SCIPION
*/

#include "segmentation.h"
#include "text.h"

int set_gdt_entry(int n, uint32_t base,
		  uint32_t limit,
		  uint8_t access,
		  uint8_t granularity)
{
	gdt_entries[n].base_low    = (base & 0xFFFF);
	gdt_entries[n].base_middle = (base >> 16) & 0xFF;
	gdt_entries[n].base_high   = (base >> 24) & 0xFF;
	gdt_entries[n].limit_low   = (limit & 0xFFFF);
	gdt_entries[n].limit_high_and_flags = (limit >> 16) & 0x0F;
	gdt_entries[n].limit_high_and_flags |= granularity & 0xF0;
	gdt_entries[n].access      = access;

	return 0;
}

void init_flat_gdt(void)
{
	printk("Flat GDT init ...     ");

	gdt_ptr.limit = (sizeof(gdt_entry_t) * 3) - 1;
	gdt_ptr.base = (uint32_t)&gdt_entries;
	
	set_gdt_entry(0, 0, 0, 0, 0);
	set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	
	_set_gdt((uint32_t) &gdt_ptr);
	
	printk("Ok !\n");

	return ;
}
