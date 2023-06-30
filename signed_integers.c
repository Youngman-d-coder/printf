#include "main.h"


/**
 * signed_integer_counter - checks length of integer
 *
 * @num: integer to be counted
 *
 * Return: length as integer
 */
int signed_integer_counter(int num)
{
	int l = 0;

	if (num < 0)
	{
		l++; /* Account for the negative sign */
		num = -num; /* Convert negative number to positive */
	}
	if (num == 0)
	{
		l++;
		return (l);
	}
	while (num != 0)
	{
		l++;
		num /= 10;
	}
	return (l);
}

/**
 * signed_int_to_str - converts int to str
 *
 * @num: number to be converted
 *
 * Return: nothing
 */
char *signed_int_to_str(int num)
{
	int i, l, dig, start, end;
	char temp;
	char *buffer;

	l = signed_integer_counter(num);
	buffer = (char *)malloc((l + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL); /* Failed to allocate memory */
	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	i = 0;
	if (num < 0)
	{
		buffer[0] = '-';
		i++;
		num = -num;
	}
	else if (num > 0)
	{
		buffer[0] = '+';
		i++;
	}
	while (num != 0)
	{
		dig = num % 10;
		buffer[i] = '0' + dig;
		num /= 10;
		i++;
	}
	buffer[l] = '\0';
	start = 1;
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
 * signed_int_spec - handles integer format
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int signed_int_spec(int written, va_list ap)
{
	int len, num = va_arg(ap, int);
	char *buffer = signed_int_to_str(num);

	if (buffer == NULL)
		return (written);
	len = signed_integer_counter(num);
	written += write(1, buffer, len);
	free(buffer);
	return (written);
}