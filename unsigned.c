#include "main.h"

/**
 * uns_spec - specifies for unsigned integer
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int uns_spec(int written, va_list ap)
{
	int l, i = 0;
	unsigned int num = va_arg(ap, unsigned int);
	char *buffer;

	buffer = uns_int_to_str(num);
	if (buffer == NULL)
		return (written);

	l = uns_integer_counter(num);
	i += write(1, buffer, l);
		free(buffer);

	written += i;
	return (written);
}

/**
 * dec_to_oct - converts decimal to octal
 *
 * @bin: the decimal to be converted to octal
 *
 * Return: written as integer
 */
char *dec_to_oct(unsigned int bin)
{
	int i = 0;
	int j;
	unsigned int temp;
	char *ptr;

	if (bin == 0)
	{
		ptr = malloc(2 * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	temp = bin;
	while (temp > 0)
	{
		i++;
		temp /= 8;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (bin > 0)
	{
		ptr[j] = (bin % 8) + '0';
		bin = bin / 8;
		j++;
	}
	ptr[j] = '\0';

	reverse_string(ptr, i); /* Reverse the binary string */
	return (ptr);
}
