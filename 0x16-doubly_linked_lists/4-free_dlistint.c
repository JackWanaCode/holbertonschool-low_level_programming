#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Entry point
 * Description: free the list
 * @head: head of list
 * Return: number of node.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *curr = head;

	while (head)
	{
		head = curr->next;
		free(curr);
		curr = head;
	}
}
