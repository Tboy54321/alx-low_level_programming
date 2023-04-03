#include "lists.h"

/**
 * sum_listint - function that outputs the sum of all the data (n)
 *              of a list.
 *
 * @header: pointer to the first node of the list
 *
 * Return: the sum of all (n)
 */
int sum_listint(listint_t *header)
{
	int sum = 0;

	while (header != NULL)
	{
		/* add n to sum*/
		sum += header->n;
		/*go to the next node*/
		header = header->next;
	}

	/*if list will be empty it will return sum = 0*/
	return (sum);
}
