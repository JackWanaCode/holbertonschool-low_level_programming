#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - Entry point
 * Description: add node at the beginning of list
 * @head: pointer to struct
 * @n: value of new node
 * Return: new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	new_node->prev = NULL;
	*head = new_node;
	return (new_node);
}
