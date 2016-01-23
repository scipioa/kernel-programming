##
## Makefile for kfs in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a
## 
## Made by Alexandre SCIPION
## Login scipio_a <scipio_a@epitech.eu>
## 
## Started on  Tue Oct 20 16:56:16 2015 Alexandre SCIPION
## Last update Sat Jan 23 02:07:19 2016 Alexandre SCIPION
##

NAME	=	kernel

SRC	=	src/main.c \
		src/text.c \
		src/segmentation.c \
		src/interrupts.c

OBJ	=	$(SRC:.c=.o);

CFLAGS +=	-nostdinc -fno-builtin -m32
CFLAGS +=	-fno-stack-protector
CFLAGS +=	-I./inc/
CFLAGS +=	-g3

LDFLAGS +=	-nostdlib -m32 -Wl,--build-id=none

all	:	$(NAME)

$(NAME)	:	src/crt0.o src/routine.o $(OBJ)
	        gcc $(LDFLAGS) -T kfs.ld -o $(NAME).elf src/crt0.o src/routine.o $(OBJ) 
		@echo "kernel.elf done"

.S.o    :
		nasm -f elf32  $<

clean	:
		rm -f src/main.o src/crt0.o src/routine.o src/segmentation.o src/interrupts.o src/text.o

fclean	:	clean
		rm -f kernel.elf

re	:	fclean all

boot	:
		qemu-system-i386 -kernel $(NAME).elf -serial stdio

debug	:
		qemu-system-i386 -kernel $(NAME).elf -s -S &
		gdb $(NAME).elf -ex "target remote localhost:1234"
