#include "main.h"

/**
 * cap_hex_conv - hex conversion implementer
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int cap_hex_conv(int written, va_list ap)
{
	unsigned int num;
	char *hex;
	int len, i = 0;

	num = va_arg(ap, unsigned int);
	hex = dec_to_up_hex(num);
	if (hex != NULL)
	{
		len = 0;
		while (hex[len] != '\0')
		{
			len++;
		}
		i += write(1, hex, len);
		free(hex);
	}
	written += i;
	return (written);
}
