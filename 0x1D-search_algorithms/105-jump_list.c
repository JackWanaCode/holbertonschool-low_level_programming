#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_s - Entry point
 * Description: searches for a value in an array of integers
 * using the Linear search algo
 * @head: head of list
 * @size: size of array
 * @step: step
 * @value: value for searching
 * @position: position of index
 * Return: postion of value or -1 if not found
 */

listint_t *linear_s(listint_t *head, size_t size, size_t step,
		    int value, int position)
{
	size_t i, j;
	listint_t *run;

	for (i = position, j = 0, run = head; i < size && j < step;
	     i++, run = run->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       i, run->n);
		if (run->n == value)
			return (run);
	}
	return (NULL);
}

/**
 * jump_list - search node by jump algo
 * @list: linked list
 * @size: number of nodes in list
 * @value: value for searching
 *
 * Return: pointer to first node where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size), i = 0, k = 0;
	listint_t *run, *prev;

	if (!list || size == 0)
		return (NULL);
	for (run = list, prev = list; i < (size + step - 1); i += step)
	{
		if (i >= size || run->n >= value)
		{
			i -= step;
			printf("Value found between indexes [%lu] and [%lu]\n",
			       i, i + step);
			return (linear_s(prev, size, step + 1, value, i));
		}
		prev = run;
		for (k = 0; k < step && run->next; k++)
			run = run->next;
		printf("Value checked at index [%lu] = [%d]\n", i + step, run->n);
	}
	return (NULL);
}
