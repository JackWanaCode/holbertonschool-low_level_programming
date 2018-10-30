#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sort data by bubble
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return:
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t n = 1;
	int temp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - n; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}

		}
		n++;
	}
}
