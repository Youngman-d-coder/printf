#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * integer_counter - checks length of integer
 *
 * @num: integer to be counted
 *
 * Return: length as integer
 */
int integer_counter(int num)
{
	int l = 0;

	if (num < 0)
	{
		l++; /* Account for the negative sign */
		num = -num; /* Convert negative number to positive */
	}

	while (num != 0)
	{
		l++;
		num /= 10;
	}
	return (l);
}

/**
 * int_to_str - converts int to str
 *
 * @buffer: pointer to string
 * @num: number to be converted
 *
 * Return: nothing
 */
char* int_to_str(char *buffer, int num)
{
	int i, l, dig, start, end;
	char temp;
	char* buffer;

	l = integer_counter(num);
	buffer = (char*)malloc((l + 1) * sizeof(char));

	if (buffer == NULL)
	{
		return (NULL); /* Failed to allocate memory */
	}

	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\n';
		return;
	}

	i = 0;
	if (num < 0)
	{
		buffer[0] = '-';
		i++;
		num = -num;
	}

	while (num != 0)
	{
		dig = num % 10;
		buffer[i] = '0' + dig;
		num /= 10;
		i++;
	}

	buffer[l] = '\0';

	start = (buffer[0] == '-') ? 1 : 0;
	end = l - 1;
	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
	return (buffer);
}

/**
 * int_spec - handles integer format
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int int_spec(int written, va_list ap)
{
	int len, num = va_args(ap, int);
	char* buffer = int_to_str(num);

	if (buffer == NULL)
	{
		return (written);
	}

	len = integer_counter(num);
	written += write(1, buffer, len);

	free(buffer);

	return (written);
}
