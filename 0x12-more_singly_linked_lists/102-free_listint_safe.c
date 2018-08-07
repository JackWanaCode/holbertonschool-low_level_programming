#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Entry point
 * Description: free all nodes
 * @h: pointer to pointer to a struct
 * Return: size of the list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *c;
	size_t i = 0;


	while (*h)
	{
		c = *h;
		free(*h);
		if (c - c->next < 0 && i++)
			break;
		*h = c->next;
		i++;
	}
	h = NULL;
	return (sizeof(listint_t) * i);
}
