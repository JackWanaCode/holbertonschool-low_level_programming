#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Entry point
 * Description: free all nodes
 * @head: pointer to pointer to a struct
 * Return: new node
 */
void free_listint(listint_t *head)
{
	listint_t *curr = NULL;

	while (head != NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}
