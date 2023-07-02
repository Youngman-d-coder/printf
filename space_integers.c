#include "main.h"


/**
 * space_integer_counter - checks length of integer
 *
 * @num: integer to be counted
 *
 * Return: length as integer
 */
int space_integer_counter(int num)
{
	int l = 0;

	if (num < 0)
	{
		l++; /* Account for the negative sign */
		num = -num; /* Convert negative number to positive */
	}
	if (num > 0)
	{
		l++; /* Account for the positive sign */
		num = num; /* No conversion required */
	}
	if (num == 0)
	{
		l += 2;
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
 * space_int_to_str - converts int to str
 *
 * @num: number to be converted
 *
 * Return: nothing
 */
char *space_int_to_str(int num)
{
	int i, l, dig, start, end;
	char temp;
	char *buffer;
	int *x;

	l = space_integer_counter(num);
	buffer = (char *)malloc((l + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL); /* Failed to allocate memory */
	if (num == 0)
	{
		buffer[0] = ' ';
		buffer[1] = '0';
		buffer[2] = '\0';
		return (buffer);
	}
	i = 0;
	buffer[0] = (num < 0) ? '-' : ' ';
	x = space_num_size_gen(num, i);
	num = x[0];
	i = x[1];
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
 * space_num_size_gen - to check for the size of a number
 * @num: the number whose size is searched for
 * @i: counter
 *
 * Return: Integer pointer
 */

int *space_num_size_gen(int num, int i)
{
	int *res;

	res = (int *)malloc(sizeof(int) * 2);
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		i++;
		num = -num;
	}
	else if (num > 0)
	{
		i++;
		num = num;
	}
	res[0] = num;
	res[1] = i;
	return (res);
}
/**
 * space_int_spec - handles integer format
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int space_int_spec(int written, va_list ap)
{
	int len, num = va_arg(ap, int);
	char *buffer = space_int_to_str(num);

	if (buffer == NULL)
		return (written);
	len = space_integer_counter(num);
	written += write(1, buffer, len);
	free(buffer);
	return (written);
}
