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
	int ans, i = 0, j, temp;
	int bin = va_arg(ap, int); 
	char *buffer;


	while (bin > 0)
	{
		ans = bin % 2;
		bin = bin / 2;

	/**	if (buffer == NULL)
	 *	return (written);
	 */
		buffer = int_to_str(ans);
		i += write(1, buffer, 1);
	}

	j = i;

	while (j > i)
	{
		temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
		i++;
		j--;
	}
	written += j;
        free(buffer);
        return (written);
}
