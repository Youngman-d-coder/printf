#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * dec_to_bin - converts decimal to binary
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int dec_to_bin(int written, va_list ap)
{
	int ans, len;
	int bin = va_arg(ap, int); 
	char *buffer;
	int *ptr;


	buffer = int_to_str(ans);
	while (bin > 0)
	{
		ans = bin % 2;
		bin = bin / 2;

	/**	if (buffer == NULL)
	 *	return (written);
	 */
		len = integer_counter(bin);
		written += write(1, buffer, len);
	}
        free(buffer);
        return (written);
}
