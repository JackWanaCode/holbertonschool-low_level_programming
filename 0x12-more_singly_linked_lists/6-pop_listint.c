#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Entry point
 * Description: delete the head nodes
 * @head: pointer to pointer to a struct
 * Return: head node’s data (n)
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *curr = *head;

	if (*head == NULL)
		return (0);
	n = (*head)->n;
	*head = (*head)->next;
	free(curr);
	return (n);
}
