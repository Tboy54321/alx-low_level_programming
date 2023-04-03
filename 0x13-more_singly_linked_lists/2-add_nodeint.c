#include "lists.h"

/**
 * add_nodeint - function that sums a new node at the
 *              beginning of a list
 *
 * @header: pointer to the first node
 * @n: integer a to add in a new node
 *
 * Return: address of the new element or NULL if it fails
 */

listint_t *add_nodeint(listint_t **header, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/*link first node in header with the new_node*/
	if (*header == NULL)
		new_node->next = NULL;
	else
		new_node->next = *header;

	new_node->n = n;
	/*add new node at the beginning of the list*/
	*header = new_node;

	return (*header);
}
