#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1
 *
 * @n: A pointer to the number to modify
 * @index: The index of the bit to set to 1
 *
 * Return: 1 if successful, or -1 if an error occurs
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int num = 1;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	num <<= index;

	*n |= num;

	return (1);
}

