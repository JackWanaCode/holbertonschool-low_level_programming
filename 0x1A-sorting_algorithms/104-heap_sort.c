#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - help to swap
 *
 * @n1: number 1
 * @n2: number 2
 *
 * Return: None
 */

void swap(int *n1, int *n2)
{
	*n1 = *n1 + *n2;
	*n2 = *n1 - *n2;
	*n1 = *n1 - *n2;
}

/**
 * heap_sort - sort data by heap method
 *
 * @array: Array to convert to a doubly linked list
 * @size: size of array
 *
 * Return: None
 */

void heap_sort(int *array, size_t size)
{
	size_t j, k, l;
	size_t re_size = size;
	int count = 0;

	for (j = re_size - 1; ;)
	{
		k = (j % 2) == 0 ? (j - 2) / 2 : (j - 1) / 2;
		l = j;
		count = 0;
		while (array[k] < array[l] && count < 1)
		{
			swap(&array[k], &array[l]);
			print_array(array, size);
			if (k == 0)
				break;
			count++;
			l = k;
			k = (k % 2) == 0 ? (k - 2) / 2 : (k - 1) / 2;
		}
		if (j == 1)
		{
			swap(&array[j - 1], &array[re_size - 1]);
			print_array(array, size);
			re_size--;
			j = re_size;
		}
		j--;
		if (j == 0 || ((re_size == 2) && array[0] <= array[1]))
			break;
	}
}
