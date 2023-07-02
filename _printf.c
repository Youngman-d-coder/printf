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
			else
				written = _printf_formats1(c, written, ap);/* Handle format spec */
		}
		else
		{
			if (*c == 'd' || *c == 'i' || *c == 'f')
			{
				c--;
				if (*c == '+' || *c == ' ')
				{
					c--;
					c += (*c == '%') ? 3 : 2;
				}
				else
					c++;
			}
			write(1, c, 1); /* Regular character, write it to stdout */
			written++;
		}
	}
	va_end(ap);
	return (written);
}
/**
 * _printf_formats1 - Continuation of the main function
 * @cc: format expected
 * @written: argument counter
 * @ap: argument parameter
 * Return: Always 0
 */
int _printf_formats1(const char *cc, int written, va_list ap)
{
	const char *c = cc;
	char chc;

	if (*c == 'u')
		written = uns_spec(written, ap);
	else if (*c == 'c')
	{
		chc = va_arg(ap, int); /* Handle for character format*/
		written += write(1, &chc, 1);
	}
	else if (*c == 'p')
		written = address_print(written, ap); /*Handle printing of addresses */
	else if (*c == '+')
	{
		c++;
		if (*c == 'd' || *c == 'i' || *c == 'f')
			written = signed_int_spec(written, ap); /* Handle signs in stdout */
		else
		{
			c--;
			write(1, c, 1);
		}
	}
	else if (*c == ' ')
	{
		c++;
		if (*c == 'd' || *c == 'i' || *c == 'f')
			written = space_int_spec(written, ap); /* Handle space in stdout */
		else
		{
			c--;
			write(1, c, 1);
		}
	}
	else
	{
		written = _printf_formats2(c, written, ap);/* Handle other format specs */
	}
	return (written);
}
/**
 * _printf_formats2 - Continuation of the main function
 * @ccc: format expected
 * @written: argument counter
 * @ap: argument parameter
 * Return: Always 0
 */
int _printf_formats2(const char *ccc, int written, va_list ap)
{
	const char *c = ccc;

	if (*c == 'b')
		written = bin_convert(written, ap);/* Handle binary format specifier */
	else if (*c == 's')
		written = strings(written, ap); /* Handle string format */
	else if (*c == 'r')
		written = rev_strings(written, ap); /* Handles string reverse */
	else if (*c == 'd' || *c == 'i')
		written = int_spec(written, ap); /* Handle integer format */
	else if (*c == 'o')
		written = oct_convert(written, ap); /* Handle octal format */
	else if (*c == 'x')
		written = low_hex_conv(written, ap); /* Handle lowercase hexadecimal */
	else if (*c == 'X')
		written = cap_hex_conv(written, ap); /* Handle for uppercase hexadecimal */
	return (written);
}
