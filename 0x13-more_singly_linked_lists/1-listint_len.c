#include "lists.h"

/**
 * listint_len - a function that outputs the number of elements.
 *
 * @a: a reference to the initial node
 *
 * Return: number of all elements
 */
size_t listint_len(const listint_t *a)
{
	size_t elements = 1;

	/*return 0 as no of elements when a is NULL*/
	if (a == NULL)
		return (0);

	while (a->next != NULL)
	{
		/*count number of elements*/
		if (a->n != '\0')
			elements++;

		/*go to next node*/
		a = a->next;
	}

	return (elements);
}
