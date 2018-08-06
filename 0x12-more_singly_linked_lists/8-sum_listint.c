#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - Entry point
 * Description: calculate sum of all data in node(s)
 * @head: pointer to a struct
 * Return: integer.
 */
int sum_listint(listint_t *head)
{
	listint_t *curr;
	int sum = 0;

	curr = head;
	while (curr != NULL)
	{
		sum += curr->n;
		curr = curr->next;
	}
	return (sum);
}
