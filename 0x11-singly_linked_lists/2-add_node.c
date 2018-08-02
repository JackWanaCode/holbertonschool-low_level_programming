#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node - Entry point
 * Description: print number of element in the linked list
 * @head: first node
 * @str: content of string
 * Return: node.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	char *_strdup;
	int i;

	if (!str)
		return (NULL);
	_strdup = strdup(str);
	for (i = 0; _strdup[i] != '\0'; i++)
		;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup;
	new->len = i;
	new->next = *head;
	*head = new;
	return (new);
}
