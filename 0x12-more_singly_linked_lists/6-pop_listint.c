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
	int n = (*head)->n;
	listint_t *curr = *head;

	*head = (*head)->next;
	free(curr);
	return (n);
}
