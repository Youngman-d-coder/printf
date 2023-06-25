#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * strings- Our printf function
 * @format: Specifying the format expected in standard output
 * Return: Always 0
 */

int strings(int written, va_list ap)
{
	int i;
	char *str = va_arg(ap, char*);

	i = 0;
	while (str[i] != '\0')
		i++;

	written += write(1, str, i);

	return (written);
}
