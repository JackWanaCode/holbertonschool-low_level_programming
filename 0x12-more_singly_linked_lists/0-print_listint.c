#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - Entry point
 * Description: print all element in the list
 * @h: pointer to struct
 * Return: number of node.
 */
size_t print_listint(const listint_t *h)
{
	size_t i = 0;
	const listint_t *p;

	for (p = h; p != NULL; p = p->next)
	{
		printf("%d\n", p->n);
		i++;
	}
	return (i);
}
