#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * free_grid - Entry point
 * Description: free memory outside the allocate function.
 * @grid: the pointer to pointer to array
 * @height: row of array
 *
 * Return: nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
