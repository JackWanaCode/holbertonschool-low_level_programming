#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Entry point
 * Description: delete a node at given index.
 * @head: pointer to pointer to a struct
 * @idex: index of the list where the new node will be in.
 * Return: 1 if success, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *c = *head;
	listint_t *p = NULL;
	unsigned int i = 0;

	if (index == 0 && *head != NULL)
	{
		*head = (*head)->next;
		free(c);
		return (1);
	}
	while (c != NULL)
	{
		p = c;
		c = c->next;
		i++;
		if (i == index)
		{
			p->next = c->next;
			free(c);
			return (1);
		}
	}
	return (-1);
}
