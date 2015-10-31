/*
** main.c for main in /home/scipio_a/kernel-programming/kernel-programming-1/kfs-scipio_a/src
** 
** Made by alexandre scipion
** Login scipio_a <scipio_a@epitech.eu>
** 
** Started on  Fri Oct 30 16:16:21 2015 Alexandre SCIPION
** Last update Sat Oct 31 02:35:29 2015 Alexandre SCIPION
*/

#define	LCR		0b11000001
#define	DLL		0x03
#define DLM		0x00
#define BASE		0x3F8

#define	FRAMEBUFFER	0xB8000
#define	ROW		25
#define	COL		80
#define	POS(x, y)	((x) * COL + (y)) * 2

static char		*video_mem = (void *) FRAMEBUFFER;
static char		pos_x = 0;
static char		pos_y = 0;

void outb(const unsigned short port, const unsigned char val)
{
	__asm__ volatile("outb %0, %1\n\t" : : "a" (val), "d" (port));
}

/* unused */
unsigned char inb (const unsigned short port)
{
	unsigned char	res;

	__asm__ volatile("inb %1, %0\n\t": "=a" (res): "d" (port));

	return res;
}

void init_serial(void)
{
	outb(BASE + 3, LCR);
	outb(BASE, DLL);
	outb(BASE + 1, DLM);
}

void move_cursor(void)
{
	unsigned short	pos = pos_y * COL + pos_x;

	outb(0x3D4, 0X0F);
	outb(0x3D5, (unsigned char) (pos & 0xFF));
	outb(0x3D4, 0X0E);
	outb(0x3D5, (unsigned char) ((pos >> 8) & 0xFF));
}

void clean()
{
	int	i = 0;
	int	j = 0;

	while (i < ROW) {
		j = 0;
		while (j < COL){
			video_mem[POS(i, j)] = ' ';
			j = j + 1;
		}
		i = i + 1;
	}
	move_cursor();
}

void printc(const char c)
{
	if (c == '\r')
		pos_x = 0;
	else if (c == '\n') {
		pos_x = 0;
		pos_y += 1;
	} else if (c >= ' ') {
		video_mem[POS(pos_y, pos_x)] = c;
		pos_x += 1;
		if (pos_x >= COL) {
			pos_y += 1;
			pos_x = 0;
		}
		if (pos_y >= ROW) {
			pos_y = 0;
			clean();
		}
	}
	move_cursor();
}

void printk(const char *msg)
{
	int	i = 0;

	if (msg) {
		while (msg[i]) {
			printc(msg[i]);
			i += 1;
		}
	}

	return ;
}

unsigned char getCode()
{
	unsigned char	c = 0;

	while (1) {
		if (inb(0x60)!=c) {
			c = inb(0x60);
			if (c > 0)
				return c;
		}
	};
}

void main()
{
	unsigned char	c = 0;

	init_serial();
	clean();
	printk("Hello World !\n");
	while (1) {
		c = getCode();
		if (c == 0x12)
			printc('e');
		while (getCode() == c) ;
	}

	return ;
}
