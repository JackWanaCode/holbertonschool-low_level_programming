#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_dlistint - Entry point
 * Description: calculate length of list
 * @h: pointer to struct
 * Return: number of node
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;
	const dlistint_t *p;

	for (p = h; p != NULL; p = p->next)
	{
		i++;
	}
	return (i);
}
