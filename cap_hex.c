#include "main.h"

/**
 * dec_to_hex - converts decimal to hexadecimal
 *
 * @hex: the decimal to be converted to hexadecimal
 *
 * Return: hexadecimal string representation
 */
char *dec_to_up_hex(unsigned int hex)
{
	int i = 0;
	int j;
	unsigned int temp;
	char *ptr;

	if (hex == 0)
	{
		ptr = malloc(2 * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}

	temp = hex;
	while (temp > 0)
	{
		i++;
		temp /= 16;
	}

	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (hex > 0)
	{
		int remainder = hex % 16;
		if (remainder < 10)
		{
			ptr[j] = remainder + '0';
		}
		else
		{
			ptr[j] = remainder - 10 + 'A';
		}

		hex /= 16;
		j++;
	}
	ptr[j] = '\0';

	reverse_string(ptr, i); /* Reverse the hexadecimal string */
	return (ptr);
}
