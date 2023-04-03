#include "lists.h"

/**
 * insert_nodeint_at_index - inputs a new node
 * at a given position.
 * @header: head of a list.
 * @indx: index of the list where the new node is
 * added.
 * @n: integer element.
 *
 * Return: the address of the new node, or NULL if it
 * failed.
 */

listint_t *insert_nodeint_at_index(listint_t **header,
		unsigned int indx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *h;

	h = *header;

	if (indx != 0)
	{
		for (i = 0; i < indx - 1 && h != NULL; i++)
		{
			h = h->next;
		}
	}

	if (h == NULL && indx != 0)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (indx == 0)
	{
		new->next = *header;
		*header = new;
	}
	else
	{
		new->next = h->next;
		h->next = new;
	}

	return (new);
}
