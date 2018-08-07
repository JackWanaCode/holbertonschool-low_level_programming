#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Entry point
 * Description: reverse the list
 * @head: pointer to pointer to a struct
 * Return: the first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *curr = NULL;
	listint_t *prev = NULL;

	if (*head == NULL)
		return (NULL);
	while ((*head)->next != NULL)
	{
		curr = *head;
		*head = curr->next;
		curr->next = prev;
		prev = curr;
	}
	(*head)->next = curr;
	return (*head);
}
