#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * alloc_grid - Entry point
 * Description: making a 2 dimension array
 * @width: number of column.
 * @height: number of row.
 * Return: a pointer to pointer to  new 2d array.
 */
int **alloc_grid(int width, int height)
{
	int **twoD_arr = NULL;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);
	twoD_arr = malloc(sizeof(int *) * height);
	if (twoD_arr == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		twoD_arr[i] = malloc(sizeof(int) * width);
		if (twoD_arr[i] == NULL)
		return (NULL);
	}
	if (twoD_arr == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			twoD_arr[i][j] = 0;
		}
	}
	return (twoD_arr);
}
