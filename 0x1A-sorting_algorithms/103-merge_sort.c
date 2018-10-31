#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort_help - sort data by merge method
 *
 * @array: Array to convert to a doubly linked list
 * @f_point: first point of array
 * @l_point: last point of array
 * @ret_arr: new_array for sorting
 *
 * Return:
 */

void merge_sort_help(int *array, size_t f_point, size_t l_point, int *ret_arr)
{
	size_t m_point = 0, i = 0, j = 0, move = 0;

	if (l_point - f_point < 1)
		return;
	else if (l_point - f_point >= 1)
	{
		m_point = (l_point + f_point + 1) / 2;
		merge_sort_help(array, f_point, m_point - 1, ret_arr);
		merge_sort_help(array, m_point, l_point, ret_arr);
	}
	printf("Merging...\n");
	/* print left */
	printf("[left]: %i", array[f_point]);
	for (move = f_point + 1; move < m_point; move++)
		printf(", %i", array[move]);
	printf("\n");
	/* print right */
	printf("[right]: %i", array[m_point]);
	for (move = m_point + 1; move <= l_point; move++)
		printf(", %i", array[move]);
	printf("\n");
	for (move = f_point, i = f_point, j = m_point; move <= l_point; move++)
	{
		/* sorting from 2 sub_array */
		if (j <= l_point && (i >= m_point || array[i] > array[j]))
		{
			ret_arr[move] = array[j];
			j++;
		}
		else if (i < m_point && (j > l_point  || array[i] <= array[j]))
		{
			ret_arr[move] = array[i];
			i++;
		}

	}
	printf("[Done]: ");
	for (move = f_point; move <= l_point; move++)
	{
		printf("%i", ret_arr[move]);
		if (move != l_point)
			printf(", ");
		array[move] = ret_arr[move];
	}
	printf("\n");
}

/**
 * merge_sort - sort data by merge method
 *
 * @array: Array to convert to a doubly linked list
 * @size: size of array
 *
 * Return:
 */

void merge_sort(int *array, size_t size)
{
	size_t f_point = 0;
	size_t s_point = size - 1;
	int *ret_arr;

	if (!array || size < 2)
		return;
	ret_arr = malloc(sizeof(int) * size);
	if (!ret_arr)
		return;
	merge_sort_help(array, f_point, s_point, ret_arr);
	free(ret_arr);
}
