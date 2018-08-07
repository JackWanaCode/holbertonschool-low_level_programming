#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - Entry point
 * Description: find the loop in linked list
 * @head: pointer to struct
 * Return: address of node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	const listint_t *c = head;
	long d = head - head->next;

	while (c != NULL)
	{
		if ((c - c->next < 0 && d > 0) || (c - c->next > 0 && d < 0))
		{
			return (c->next);
		}
		c = c->next;
	}
	return (NULL);
}
