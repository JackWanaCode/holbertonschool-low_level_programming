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
void free_list(list_t *head)
{
	list_t *p;

	for (p = head; p->next != NULL; p = p->next)
	{
		free(p->str);
		free(p);
	}
}
