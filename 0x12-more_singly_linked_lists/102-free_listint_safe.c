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
	listint_t *curr = NULL;
	size_t struct_size = sizeof(listint_t);
	size_t i = 0;

	while (sizeof(*h) == struct_size)
	{
		curr = *h;
		free(curr);
		*h = (**h).next;
		i++;
	}
	*h = NULL;
	return (struct_size * i);
}
