#include "lists.h"

/**
 * add_nodeint_end - function that sums a new node
 *            at the end of the node
 *
 * @header: pointer to the initial node of the list
 * @n: element int to add to new node
 *
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **header, const int n)
{
	listint_t *new_node, *temp;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	temp = *header;

	/*place new_node first if header is NULL*/
	if (temp == NULL)
		*header = new_node;
	else
	{
		/*if header is not null, and next is not NULL*/
		while (temp->next != NULL)
			temp = temp->next;	/*go to the last node*/

		/*place our new node at the end*/
		temp->next = new_node;
	}

	return (*header);
}
