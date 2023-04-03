#include "lists.h"

/**
 * reverse_listint - will reversea given linked list.
 * @header: head of a list.
 *
 * Return: pointer to the initial node.
 */
listint_t *reverse_listint(listint_t **header)
{
	listint_t *p;
	listint_t *n;

	p = NULL;
	n = NULL;

	while (*header != NULL)
	{
		n = (*header)->next;
		(*header)->next = p;
		p = *header;
		*header = n;
	}

	*header = p;
	return (*header);
}
