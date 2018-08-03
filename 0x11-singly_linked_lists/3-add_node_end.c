#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node_end - Entry point
 * Description: print number of element in the linked list
 * @head: first node
 * @str: content of string
 * Return: node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *p;
	int i = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		new->str = strdup(str);
	new->len = i;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	for (p = *head; p->next != NULL; p = p->next)
		;
	p->next = new;
	return (new);
}
