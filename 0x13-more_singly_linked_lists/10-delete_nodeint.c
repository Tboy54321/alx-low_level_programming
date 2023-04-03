#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * of a linked list.
 * @header: head of a list.
 * @indx: index of the list where the node is
 * deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **header, unsigned int indx)
{
	unsigned int i;
	listint_t *prev;
	listint_t *next;

	prev = *header;

	if (indx != 0)
	{
		for (i = 0; i < indx - 1 && prev != NULL; i++)
		{
			prev = prev->next;
		}
	}

	if (prev == NULL || (prev->next == NULL && indx != 0))
	{
		return (-1);
	}

	next = prev->next;

	if (indx != 0)
	{
		prev->next = next->next;
		free(next);
	}
	else
	{
		free(prev);
		*header = next;
	}

	return (1);
}
