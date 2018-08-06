#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - Entry point
 * Description: print numbers of elements in the list
 * @h: pointer to struct
 * Return: number of node.
 */
size_t listint_len(const listint_t *h)
{
	size_t i = 0;
	const listint_t *p;

	for (p = h; p != NULL; p = p->next)
	{
		i++;
	}
	return (i);
}
