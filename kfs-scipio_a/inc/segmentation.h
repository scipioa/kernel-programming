/*
** segmentation.h for segmentation in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Tue Nov 24 14:28:17 2015 Alexandre SCIPION
** Last update Tue Jan 19 10:58:08 2016 Alexandre SCIPION
*/

#ifndef SEGMENTATION_H_
# define SEGMENTATION_H_

# include "types.h"

typedef struct gdt_entry_s
{
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t limit_high_and_flags;
	uint8_t base_high;
} __attribute__ ((packed)) gdt_entry_t;

typedef struct gdt_ptr_s
{
	uint16_t limit;
	uint32_t base;
} __attribute__ ((packed)) gdt_ptr_t;

int set_gdt_entry(int n, uint32_t base,
			  uint32_t limit,
			  uint8_t access,
			  uint8_t granularity);
void init_flat_gdt(void);

gdt_entry_t gdt_entries[3];
gdt_ptr_t gdt_ptr;

extern void _set_gdt(uint32_t);

#endif /* !SEGMENTATION_H_ */
