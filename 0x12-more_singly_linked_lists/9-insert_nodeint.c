#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Entry point
 * Description: add node at a given position
 * @head: pointer to pointer to a struct
 * @idx: index of the list where the new node will be in.
 * @n: address of new node.
 * Return: new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *c = *head;
	listint_t *p = NULL;
	listint_t *new;
	unsigned int i = 0;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	else
	{
		while (i <= idx)
		{
			p = c;
			if (c->next == NULL && i == idx)
			{
				new->next = NULL;
				c->next = new;
				return (new);
			}
			if (c->next == NULL && i < idx)
				return (NULL);
			c = c->next;
			i++;
		}
		p->next = new;
		new->next = c;
	}
	return (new);
}
