#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - Our printf function
 * @format: Specifying the format expected in standard output
 *
 * Return: Always 0
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i, written = 0;
	const char *c = format;
	va_start(ap, format);

	for (; *c != '\0'; c++)
	{
		if (*c == '%')
		{
			/* Move past the '%' */
			c++;

			if (*c == '\0')
			{
				/* Unexpected end of format string */
				break;
			}

			if (*c ==  '%')
			{
				/* Handle "%%" case */
				write(1, "%", 1);
				written++;
			}
			else if (*c == 's')
			{
				/* Handle string format specifier */
				char *str = va_arg(ap, char*);
				i = 0;
				while (str[i] != '\0')
					i++;
				written += write(1, str, i);
			}
			else if (*c == 'c')
			{
				/* Handle for character format specifier */
				char chc = va_arg(ap, int);
				written += write(1, &chc, 1);
			}
			else
			{
				/* Unsupported format specifier, ignore */
			}
		}
		else
		{
			/* Regular character, write it to stdout */
			write(1, c, 1);
			written++;
		}

	}
	va_end(ap);

	return (written);
}
