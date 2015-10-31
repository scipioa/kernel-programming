OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH("i386")
ENTRY(_start)

begin = 0x00100000 + SIZEOF_HEADERS;
SECTIONS
{
	.text begin : AT(begin)
	{
		code = .;
		*(.text)
		. = ALIGN(4096);
	}

	.data : AT(begin + (data - code))
	{
		data = .;
		*(.data)
		. = ALIGN(4096);
	}

	.bss : AT(begin + (bss - code))
	{
		bss = .;
		*(.bss)
		. = ALIGN(4096);
	}

	end = .;
}
