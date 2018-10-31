#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * counting_sort_help - sort data by counting method
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 * @sorted_arr: array will be stored sorted number from Array
 * @count_arr: array to store element occurence
 * @max: max of counting
 * Return:
 */

void counting_sort_help(int *array, size_t size,
		int *sorted_arr, int *count_arr, int max)
{
	int count, k;
	size_t i, j;

	/* creating counting array*/
	for (i = 0; i < size; i++)
	{
		count = 1;
		for (j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
				count++;
		}
		if (count_arr[array[i]] == 0)
			count_arr[array[i]] = count;
	}
	/* adjusting count array to reflects counts of previous elements */
	for (k = 1; k < max + 1; k++)
		count_arr[k] += count_arr[k - 1];
	printf("%i", count_arr[k]);
	for (k = 1; k < max + 1; k++)
		printf(", %i", count_arr[k]);
	printf("\n");
	/* sorting the array */
	for (i = size - 1, j = 0; j < size; i--, j++)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
	{
		array[j] = sorted_arr[j];
	}
}

/**
 * counting_sort - sort data by counting method
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return:
 */

void counting_sort(int *array, size_t size)
{
	int *sorted_arr = NULL;
	int *count_arr = NULL;
	int max = 0;
	size_t i = 0;

	/* allocate memory for return sorted array */
	sorted_arr = malloc(sizeof(int) * size);
	if (!sorted_arr)
		return;
	/* find max and min */
	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	/* allocate memory for counting array */
	count_arr = malloc(sizeof(int) * (max + 1));
	if (!count_arr)
	{
		free(sorted_arr);
		return;
	}
	for (i = 0; i < (size_t)(max + 1); i++)
		count_arr[i] = 0;
	counting_sort_help(array, size, sorted_arr, count_arr, max);
	free(count_arr);
	free(sorted_arr);
}
