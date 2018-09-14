#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Entry point
 * Description: add node in the end of list
 * @head: head of list
 * @n: value of new node
 * Return: number of node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *curr = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	while (*head && curr->next)
	{
		curr = curr->next;
	}
	if (!(*head))
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		curr->next = new_node;
		new_node->prev = curr;
	}
	return (new_node);
}
