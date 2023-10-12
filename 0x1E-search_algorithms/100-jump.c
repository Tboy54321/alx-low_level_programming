#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using jump search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t jump, prev, current, i;

	if (array == NULL)
		return (-1);

	jump = sqrt(size);
	prev = 0;
	current = 0;

	while (current < size && array[current] < value)
	{
		printf("Value compared: %d\n", array[current]);
		prev = current;
		current += jump;
	}
	printf("Value compared: %d\n", array[current]);

	for (i = prev; i <= current && i < size; i++)
	{
		printf("Value compared: %d\n", array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
