#include "lists.h"

/**
 * pop_listint - Removes the top part of the node
 *
 * @header: pointer to the initial node in the list
 *
 * Return: the header's node's data (n)
 */
int pop_listint(listint_t **header)
{
	int first_node;
	listint_t *temp, *next;

	/*if list is empty return 0*/
	if (*header == NULL)
		return (0);

	/*set header addr to temp*/
	temp = *header;
	/*get addr of next node*/
	next = temp->next;
	/*get element of first node*/
	first_node = temp->n;

	/*free first node*/
	free(temp);

	/*set head to second node*/
	*header = next;

	/*return element of first node*/
	return (first_node);
}
