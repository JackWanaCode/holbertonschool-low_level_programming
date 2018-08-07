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
	listint_t *chk = NULL;
	long d;
	int i = 0;

	if (head->next)
		d = head - head->next;
	while (c != NULL)
	{
		if (chk == NULL)
		{
			printf("[%p] %i\n", (void *)c, c->n);
			i++;
		}
		if ((c < c->next && d > 0) || ((c > c->next) && d < 0))
		{
			if (chk == c->next)
			{
				c = c->next;
				printf("-> [%p] %i\n", (void *)c, c->n);
				break;
			}
			else
				chk = c->next;
		}
		c = c->next;
	}
	return (i);
}
