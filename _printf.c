#include "main.h"


/**
 * _printf - Our printf function
 * @format: Specifying the format expected in standard output
 * Return: Always 0
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int written = 0;
	const char *c = format;
	char chc;

	va_start(ap, format);
	for (; *c != '\0'; c++)
	{
		if (*c == '%')
		{
			c++; /* Move past the '%' */
			if (*c == '\0')
				break; /* Unexpected end of format string */
			if (*c == '%')
			{
				write(1, "%", 1); /* Handle "%%" case */
				written++;
			}
			else if (*c == 's')
				written = strings(written, ap); /* Handle string format */
			else if (*c == 'r')
				written = rev_strings(written, ap); /* Handles string reverse */
			else if (*c == 'c')
			{
				chc = va_arg(ap, int); /* Handle for character format*/
				written += write(1, &chc, 1);
			}
			else if (*c == 'b')
				written = bin_convert(written, ap);/* Handle binary format specifier */
			else if (*c == 'd' || *c == 'i')
				written = int_spec(written, ap); /* Handle integer format */
			else if (*c == 'u')
				written = uns_spec(written, ap); /* Handle unsigned format */
			else if (*c == 'o')
				written = oct_convert(written, ap); /* Handle octal format */
			else if (*c == 'x')
				written = low_hex_conv(written, ap); /* Handle lowercase hexadecimal */
			else if (*c == 'X')
				written = cap_hex_conv(written, ap); /* Handle for uppercase hexadecimal */
			else if (*c == 'p')
				written = address_print(written, ap); /*Handle printing of addresses */
			/* else : Unsupported format specifier, ignore */
		}
		else
		{
			write(1, c, 1); /* Regular character, write it to stdout */
			written++;
		}
	}
	va_end(ap);
	return (written);
}
