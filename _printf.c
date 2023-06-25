#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Our printf function
 * @format: Specifying the format expected in standard output
 *
 * Return: Always 0
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int written = 0;
	va_start(ap, format);
	int i;

	for (const char *c = format; *c != '\0'; c++)
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
				for (i = 0; str[i] != '\0'; i++)
				written += write(1, str, i);
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
