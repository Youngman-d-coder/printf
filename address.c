#include "main.h"
#include <stdint.h>
/**
 * pointer_writer - convert address stored in a pointer to hex
 * @ptr: The address stored in a pointer
 *
 * Return: Pointer to char
 */

int pointer_writer(void *ptr)
{
	char *buffer = malloc(sizeof(char) * 20);
	uintptr_t value = (uintptr_t) ptr;
	int i, index = 0, digit;

	if (buffer == NULL)
		return (-1); /* Error while allocating memory */
	while (value != 0)
	{
		digit = value % 16;
		buffer[index] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
		value /= 16;
		index++;
	}

	for (i = index - 1; i >= 0; i--)
	{
		if (write(1, &buffer[i], 1) < 0)
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);

	return (index);
}
