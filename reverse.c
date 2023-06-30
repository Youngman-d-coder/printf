#include "main.h"

/**
 * _strlen - Calculates the length of a string
 * @str: The string to calculate the length of
 *
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * rev_str - Reverses a string
 * @str: The string to reverse
 *
 * Return: The reversed string
 */
char *rev_str(char *str)
{
	int i, j;
	char temp;

	if (str == NULL)
		return (NULL);

	for (i = 0, j = _strlen(str) - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	return (str);
}
