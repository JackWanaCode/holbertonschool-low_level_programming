#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Entry point
 * Description: print number of element in the linked list
 * @h: pointer to struct
 * Return: number of node.
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;
	const list_t *p = h;

	for (p = h; p != NULL; p = p->next)
	{
		i++;
	}
	return (i);
}
