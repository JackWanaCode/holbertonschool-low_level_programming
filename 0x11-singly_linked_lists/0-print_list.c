#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - Entry point
 * Description: print all element in the list
 * @h: pointer to struct
 * Return: number of node.
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;
	const list_t *p;

	for (p = h; p != NULL; p = p->next)
	{
		if (p->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", p->len, p->str);
		i++;
	}
	return (i);
}
