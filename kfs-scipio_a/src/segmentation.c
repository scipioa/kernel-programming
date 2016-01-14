/*
** segmentation.c for segmentation in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Tue Nov 24 14:28:17 2015 Alexandre SCIPION
** Last update Thu Jan 14 11:00:37 2016 Alexandre SCIPION
*/

#include "segmentation.h"
#include "text.h"

extern void _set_gdt(uint32_t);

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

/* static void gdt_flush(void) */
/* { */
/* 	__asm__ volatile("lgdt [gdt_ptr] */
/* 			mov ax, 0x42 */
/* 			mov ds, ax */
/* 			mov es, ax */
/* 			mov fs, ax */
/* 			mov gs, ax */
/* 			mov ss, ax */

/* 			push 0x08 */
/* 			mov eax, offset flush */
/* 			push eax */

/* 			_emit 0xCB */
/* 		flush:"); */

/* 	return; */
/* } */

void init_flat_gdt(void)
{
	printk("Flat GDT init ...\n");

	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
	gdt_ptr.base = (uint32_t)&gdt_entries;
	
	set_gdt_entry(0, 0, 0, 0, 0);
	set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	set_gdt_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
	set_gdt_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
	
	_set_gdt((uint32_t) &gdt_ptr);
	
	printk("GDT Ok !\n");

	return ;
}
