#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - Entry point
 * Description: get_dnodeint_at_index
 * @head: head of list
 * @index: indext of node in the list
 * Return: node at index.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *curr = head;
	unsigned int i = 0;

	while (curr)
	{
		if (i == index)
			return (curr);
		curr = curr->next;
		i++;
	}
	return (NULL);
}
