#include "lists.h"

/**
 * print_listint - A function that displays or outputs every item in a given list.
 *
 * @h: a reference to the initial node
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *a)
{
	size_t node_count = 1;

	/* return 0 as no of nodes when h is null*/
	if (a == NULL)
		return (0);

	while (a->next != NULL)
	{
		printf("%d\n", a->n);

		/*go to the next node*/
		a = a->next;
		/*count number of nodes*/
		node_count++;
	}

	/*prints the last node*/
	printf("%d\n", a->n);

	return (node_count);
}
