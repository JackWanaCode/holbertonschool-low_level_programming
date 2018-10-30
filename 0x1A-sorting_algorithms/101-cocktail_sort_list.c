#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * swap - sort the list by coctail shake algo
 *
 * @list: double pointer to list
 * @prev_node: previous node
 * @curr_node: current node
 * @tail: tail of list
 * Return: nothing
 */

void swap(listint_t **list, listint_t **tail, listint_t *prev_node, listint_t *curr_node)
{
	prev_node->next = curr_node->next;
	curr_node->prev = prev_node->prev;
	if (curr_node->next)
		curr_node->next->prev = prev_node;
	curr_node->next = prev_node;
	if (prev_node->prev)
		prev_node->prev->next = curr_node;
	prev_node->prev = curr_node;
	/* reset head and tail of list */
	if (!curr_node->prev)
		*list = curr_node;
	if (!prev_node->next)
		*tail = prev_node;
	print_list(*list);
}

/**
 * cocktail_sort_list - sort data by bubble
 *
 * @list: head of double linked list
 *
 * Return:
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *m_head = *list;
	listint_t *tail = *list, *m_tail;
	listint_t *curr_node = NULL;
	listint_t *prev_node = NULL;
	int check = 1, m_head_count = 0, m_tail_count = 0, count = 0, jump = 0, m_head_tail = 0;

	for (; tail->next; tail = tail->next)
		count++;
	m_head = *list;
	m_tail = tail;

	for (;jump < count; jump++, count--)
	{
		if (check)
		{
			/* for forward and set m_tail back 1 step */
			for (m_tail = tail, m_head_tail = 0; m_head_tail < m_head_count;
					m_tail = m_tail->prev, m_head_tail++)
					;
			for (prev_node = m_head, curr_node = m_head->next; prev_node != m_tail;
					prev_node = curr_node, curr_node = curr_node->next)
			{
				if (prev_node->n > curr_node->n)
					swap(list, &tail, prev_node, curr_node);
			}
			check = 0;
			m_head_count++;
		}
		else
		{
			/* go backward and set m_head 1 step ahead */
			for (m_head = *list, m_head_tail = 0; m_head_tail < m_tail_count;
					m_head = m_head->next, m_head_tail++)
					;
			for (prev_node = m_tail->prev, curr_node = m_tail; curr_node != m_head;
					curr_node = prev_node, prev_node = prev_node->prev)
			{
				if (prev_node->n > curr_node->n)
				{
					swap(list, &tail, prev_node, curr_node);
				}
			}
			check = 1;
			m_tail_count++;
		}
	}
}