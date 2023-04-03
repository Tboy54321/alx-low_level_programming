#include "lists.h"

/**
 * get_nodeint_at_index - Retrieve the node located at the
 *  *nth index position within a linked list
 *
 * @header: pointer to the first node of the list
 * @index: number of node to access
 *
 * Return: node at nth index OR NULL if node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *header, unsigned int index)
{
	unsigned int i;

	/*iterate thorugh nodes in list till the index nth node*/
	for (i = 0; i < index && header != NULL; i++)
		header = header->next;

	/*return header*/
	return (header);
}
