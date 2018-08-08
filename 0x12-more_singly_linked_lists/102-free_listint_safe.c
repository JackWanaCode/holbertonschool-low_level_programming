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

	if (h == NULL)
		return (0);
	while (*h)
	{
		c = *h;
		free(c);
		i++;
		if (*h - (*h)->next < 0 || (*h)->next == (*h))
			break;
		*h = (*h)->next;
	}
	h = NULL;
	return (sizeof(listint_t) * i);
}
