#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - Entry point
 * Description: sum of value of nodes in the list
 * @head: head of list
 * Return: node at index.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *curr = head;

	while (curr)
	{
		sum += curr->n;
		curr = curr->next;
	}
	return (sum);
}
