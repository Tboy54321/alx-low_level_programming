#include "main.h"

/**
 * clear_bit - Sets the value of a bit at a given index to 0
 *
 * @n: A pointer to the number to modify
 * @index: The index of the bit to set to 0
 *
 * Return: 1 if successful, or -1 if an error occurs
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int num = 1;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	num = ~(num << index);

	*n &= num;

	return (1);
}

