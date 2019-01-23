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
 * @value: value for searching
 * @position: position of index
 * Return: postion of value or -1 if not found
 */

listint_t *linear_s(listint_t *head, size_t size, int value, int position)
{
	size_t i;
	listint_t *run;

	for (i = 0, run = head; i < size; i++, run = run->next)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       i + position, run->n);
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
	int check = 1;

	if (!list)
		return (NULL);
	for (run = list, prev = list; i < (size + step - 1) && check; i += step)
	{
		if (i >= size)
		{
			step = step - (i - size + 1);
			i = size - 1;
			check = 0;
		}
		if (run->n >= value)
		{
			i -= step;
			printf("Value found between indexes [%lu] and [%lu]\n",
			       i, i + step);
			return (linear_s(prev, step + 1, value, i));
		}
		prev = run;
		for (k = 0; k < step && run->next; k++)
			run = run->next;
		printf("Value checked array[%lu] = [%d]\n", i + step, run->n);
	}
	return (NULL);
}
