#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - Entry point
 * Description: add node at the end
 * @head: pointer to pointer to a struct
 * @n: member number in that node
 * Return: new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	for (current = *head; current->next != NULL; current = current->next)
		;
	current->next = new;
	return (new);
}
