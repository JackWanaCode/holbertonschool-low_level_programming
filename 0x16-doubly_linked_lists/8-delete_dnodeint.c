#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Entry point
 * Description: insert node at index
 * @head: head of list
 * @index: location where node will be inserted
 * Return: 1 if success, -1 if not.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *p = NULL;
	dlistint_t *c = NULL;
	dlistint_t *n = *head;
	unsigned int i = 0;

	while (n)
	{
		p = c;
		c = n;
		n = n->next;
		if (i == index)
		{
			if (index != 0)
				p->next = n;
			if (n)
				n->prev = p;
			if (index == 0)
				*head = n;
			free(c);
			return (1);
		}
		i++;
	}
	return (-1);
}
