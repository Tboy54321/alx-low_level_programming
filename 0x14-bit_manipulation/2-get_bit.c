#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 *
 * @n: The number to retrieve the bit from
 * @index: The index of the bit to retrieve
 *
 * Return: The value of the bit (0 or 1), or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	bit = (n >> index) & 1;

	return (bit);
}

