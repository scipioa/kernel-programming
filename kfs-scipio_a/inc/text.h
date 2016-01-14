/*
** text.h for text in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Thu Jan 14 09:40:30 2016 Alexandre SCIPION
** Last update Thu Jan 14 09:46:18 2016 Alexandre SCIPION
*/

#ifndef TEXT_H_
# define TEXT_H_

void printk(const char *msg);
void clean();
void outb(const unsigned short port, const unsigned char val);
unsigned char inb (const unsigned short port);

#endif /* !TEXT_H_ */
