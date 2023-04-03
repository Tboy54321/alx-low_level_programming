#include "lists.h"

/**
 * free_listint - frees list
 *
 * @header: pointer to the first node of the list
 *
 * Return: 0
 */
void free_listint(listint_t *header)
{
	listint_t *current;

	/*iterate through each node in list*/
	while ((current = header) != NULL)
	{
		/*set header as the next node*/
		header = header->next;
		free(current);
	}
}
