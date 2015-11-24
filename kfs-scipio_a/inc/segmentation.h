/*
** segmentation.h for segmentation in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Tue Nov 24 14:28:17 2015 Alexandre SCIPION
** Last update Tue Nov 24 18:06:51 2015 Alexandre SCIPION
*/

#ifndef SEGMENTATION_H_
# define SEGMENTATION_H_

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;

typedef struct gdt_entry_s
{
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t granularity;
	uint8_t base_high;
} __attribute__ ((packed)) gdt_entry_t;

typedef struct gdt_ptr_s
{
	uint32_t base;
	uint16_t limit;
} __attribute__ ((packed)) gdt_ptr_t;

int set_gdt_entry(int n, uint32_t base,
			  uint32_t limit,
			  uint8_t access,
			  uint8_t granularity);
void init_flat_gdt(void);

gdt_entry_t gdt_entries[3];
gdt_ptr_t gdt_ptr;

#endif /* !SEGMENTATION_H_ */
