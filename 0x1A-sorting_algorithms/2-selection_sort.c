#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sort data by selection algorithm
 *
 * @array: Array
 * @size: Size
 *
 * Return:
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t n = 0;
	int temp = 0;

	for (i = 0; i < size; i++)
	{
		n = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[n])
			{
				n = j;
			}
		}
		if (n != i)
		{
			temp = array[i];
			array[i] = array[n];
			array[n] = temp;
			print_array(array, size);
		}
	}
}
