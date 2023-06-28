#include "main.h"

/**
 * oct_convert -  conversion implementer
 * @written: argument counter
 * @ap: argument parameters
 *
 * Return: written as integer
 */
int oct_convert(int written, va_list ap)
{
	unsigned int num;
	char *octal;
	int len, i = 0;

	num = va_arg(ap, unsigned int);
	octal = dec_to_oct(num);
	if (octal != NULL)
	{
		len = 0;
		while (octal[len] != '\0')
		{
			len++;
		}
		i += write(1, octal, len);
		free(octal);
	}
	written += i;
	return (written);
}
