/*
** types.h for types in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Fri Nov 27 16:28:11 2015 Alexandre SCIPION
** Last update Sat Jan 16 00:53:29 2016 Alexandre SCIPION
*/

#ifndef TYPES_H_
# define TYPES_H_

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;

typedef struct multiboot_info
{
	uint32_t mmap_length;
	uint32_t mmap_addr;
} multiboot_info_t;

#endif /* !TYPES_H_ */
