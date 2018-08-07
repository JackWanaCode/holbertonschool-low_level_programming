#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Entry point
 * Description: get the node at the nth (index) of node
 * @head: pointer to pointer to a struct
 * @index: index of node, starting at 0
 * Return: node at nth.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *curr = head;

	while (i < index && curr->next)
	{
		curr = curr->next;
		i++;
	}
	if (index > i)
		return (NULL);
	return (curr);
}
