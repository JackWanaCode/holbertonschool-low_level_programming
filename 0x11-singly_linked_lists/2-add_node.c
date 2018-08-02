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
	int i = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	if (!str)
	{
		new->str = NULL;
		new->len = i;
		new->next = *head;
		*head = new;
	}
	else
	{
		_strdup = strdup(str);
		for (i = 0; _strdup[i] != '\0'; i++)
			;
		new->str = _strdup;
		new->len = i;
		new->next = *head;
		*head = new;
	}
	return (new);
}
