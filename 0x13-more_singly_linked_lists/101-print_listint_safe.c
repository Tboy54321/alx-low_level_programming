#include "lists.h"

/**
 * free_listp - frees a linked list
 * @header: head of a list.
 *
 * Return: 0
 */
void free_listp(listp_t **header)
{
	listp_t *temp;
	listp_t *curr;

	if (header != NULL)
	{
		curr = *header;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*header = NULL;
	}
}

/**
 * print_listint_safe - prints a linked list.
 * @header: head of a list.
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *header)
{
	size_t nnodes = 0;
	listp_t *hptr, *new, *add;

	hptr = NULL;
	while (header != NULL)
	{
		new = malloc(sizeof(listp_t));

		if (new == NULL)
			exit(98);

		new->p = (void *)header;
		new->next = hptr;
		hptr = new;

		add = hptr;

		while (add->next != NULL)
		{
			add = add->next;
			if (header == add->p)
			{
				printf("-> [%p] %d\n", (void *)header, header->n);
				free_listp(&hptr);
				return (nnodes);
			}
		}

		printf("[%p] %d\n", (void *)header, header->n);
		header = header->next;
		nnodes++;
	}

	free_listp(&hptr);
	return (nnodes);
}
