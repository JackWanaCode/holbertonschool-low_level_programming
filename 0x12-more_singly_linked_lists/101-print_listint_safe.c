#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Entry point
 * Description: print a listint_l linked list
 * @head: pointer to struct
 * Return: number of node.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *c = head;
	long d = head - head->next;
	int i = 0;

	while (c != NULL)
	{
		printf("[%p] %i\n", (void *)c, c->n);
		if ((c - c->next < 0 && d > 0) || (c - c->next > 0 && d < 0))
		{
			c = c->next;
			printf("-> [%p] %i\n", (void *)c, c->n);
			break;
		}
		c = c->next;
		i++;
	}
	return (i);
}
