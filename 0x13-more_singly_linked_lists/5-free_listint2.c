#include "lists.h"

/**
 * free_listint2 - function that frees the list and sets header to NULL
 *
 * @header: pointer to the initial node
 *
 * Return: 0
 */
void free_listint2(listint_t **header)
{
	listint_t *current, *temp;

	if (header != NULL)
	{
		/*set header addr to current*/
		current = *header;

		/*iterate through the whole list*/
		/*while setting the current node to temp*/
		while ((temp = current) != NULL)
		{
			/*set next node to curretnt*/
			current = current->next;
			/*free temp, that is the current node*/
			free(temp);
		}

		*header = NULL;
	}
}
