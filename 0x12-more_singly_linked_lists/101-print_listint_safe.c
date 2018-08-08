#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "lists.h"

/**
 * print_listint_safe - Entry point
 * Description: print a listint_l linked list
 * @head: pointer to struct. something
 * Return: number of node(s).
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *c = head;
	int i = 0;

	while (c != NULL)
	{
		printf("[%p] %i\n", (void *)c, c->n);
		i++;
		if (c < c->next || c->next == c)
		{
			c = c->next;
			printf("-> [%p] %i\n", (void *)c, c->n);
			break;
		}
		c = c->next;
	}
	return (i);
}
