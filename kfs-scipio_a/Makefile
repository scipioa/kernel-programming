##
## Makefile for kfs in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a
## 
## Made by Alexandre SCIPION
## Login scipio_a <scipio_a@epitech.eu>
## 
## Started on  Tue Oct 20 16:56:16 2015 Alexandre SCIPION
## Last update Tue Nov 24 18:15:51 2015 Alexandre SCIPION
##

NAME	=	kernel

CFLAGS +=	-nostdinc -fno-builtin -m32
CFLAGS +=	-fno-stack-protector
CFLAGS +=	-g3
CFLAGS +=	-I./inc/

LDFLAGS +=	-nostdlib -m32 -Wl,--build-id=none

all	:	$(NAME)

$(NAME)	:	src/crt0.o src/main.o src/segmentation.o
	        gcc $(LDFLAGS) -T kfs.ld -o $(NAME).elf src/main.o src/crt0.o src/segmentation.o
		@echo "kernel.elf done"

.S.o    :
		nasm -f elf32  $<

clean	:
		rm -f src/main.o src/crt0.o

fclean	:	clean
		rm -f kernel.elf

re	:	fclean all

boot	:
		qemu-system-i386 -kernel $(NAME).elf -serial stdio

debug	:
		qemu-system-i386 -kernel $(NAME).elf -s -S &
		gdb $(NAME).elf -ex "target remote localhost:1234"
