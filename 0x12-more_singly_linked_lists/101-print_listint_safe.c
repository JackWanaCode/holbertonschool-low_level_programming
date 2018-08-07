#include <stdio.h>
#include <stdlib.h>
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
	int check = 0;
	int i = 0;
	if (!c)
		exit (98);
	while (c != NULL)
	{
		if (check == 0)
			printf("[%p] %i\n", (void *)c, c->n);
		if (c - c->next < 0)
		{
			if (check == 1)
			{
				c = c->next;
				printf("-> [%p] %i\n", (void *)c, c->n);
				break;
			}
			else
				check = 1;
		}
		c = c->next;
		i++;
	}
	return (i);
}
