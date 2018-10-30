#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sort data by insertion algorithms
 *
 * @list: double pointer to double linked list
 * Return:
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node = NULL;
	listint_t *jump_node = NULL;
	listint_t *prev_node = NULL;
	listint_t *temp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	for (prev_node = *list, curr_node = (*list)->next; curr_node;
				prev_node = curr_node, curr_node = curr_node->next)
	{
		temp = curr_node;
		jump_node = curr_node;
		while (jump_node != (*list))
		{
			if (prev_node->n > temp->n)
			{
				/* swapping node */
				prev_node->next = jump_node->next;
				if (jump_node->next)
					jump_node->next->prev = prev_node;
				jump_node->next = prev_node;
				jump_node->prev = prev_node->prev;
				if (prev_node->prev)
					prev_node->prev->next = jump_node;
				prev_node->prev = jump_node;
			/* move prev_node pointer to before jump_node pointer */
				prev_node = jump_node->prev;
				if (prev_node == NULL)
					/*set list when the first position is changed*/
					*list = jump_node;
				print_list(*list);
			}
			else
				break;
		}
	}
}
