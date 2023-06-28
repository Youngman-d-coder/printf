#include "main.h"

/**
 * dec_to_bin - converts decimal to binary
 *
 * @bin: the decimal to be converted to binary
 *
 * Return: written as integer
 */

char *dec_to_bin(unsigned int bin)
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
		temp /= 2;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (bin > 0)
	{
		ptr[j] = (bin % 2) + '0';
		bin = bin / 2;
		j++;
	}
	ptr[j] = '\0';

	reverse_string(ptr, i); /* Reverse the binary string */
	return (ptr);
}
/**
 * reverse_string - Function to reverse an input string
 *
 * @str: The string to be reversed
 * @length: length of the string
 *
 * Return: Nothing
 */

void reverse_string(char *str, int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}
