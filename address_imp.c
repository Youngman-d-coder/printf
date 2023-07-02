#include "main.h"

/**
 * address_print - printing address in hex
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int address_print(int written, va_list ap)
{
	void *ptr;
	int len = 0;

	ptr = va_arg(ap, void*);
	if (ptr == NULL)
	{
		len += write(1, "(nil)", 5);
	}
	else
	{
		len += write(1, "0x", 2);
	}
	len += pointer_writer(ptr);
	written += len;
	return (written);
}
