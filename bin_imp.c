#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * bin_convert - Binary conversion implementer
 * @written: argument counter
 * @ap: argument parameters
 *
 * Return: written as integer
 */
int bin_convert(int written, va_list ap)
{
	unsigned int num;
	char *binary;
	int len, i = 0;

	num = va_arg(ap, unsigned int);
	binary = dec_to_bin(num);
	if (binary != NULL)
	{
		len = 0;
		while (binary[len] != '\0')
		{
			len++;
		}
		i += write(1, binary, len);
		free(binary);
	}
	written += i;
	return (written);
}
