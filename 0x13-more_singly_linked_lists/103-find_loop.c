#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @header: head of a list.
 *
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *header)
{
	listint_t *p2;
	listint_t *prev;

	p2 = header;
	prev = header;
	while (header && p2 && p2->next)
	{
		header = header->next;
		p2 = p2->next->next;

		if (header == p2)
		{
			header = prev;
			prev =  p2;
			while (1)
			{

				p2 = prev;
				while (p2->next != header && p2->next != prev)
				{
					p2 = p2->next;
				}
				if (p2->next == header)
					break;

				header = header->next;
			}
			return (p2->next);
		}
	}
	return (NULL);
}
