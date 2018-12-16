#include "binary_trees.h"


/**
* array_to_heap - Entry point
* Description - insert a node follow max heap from array
* @array: pointer point to first element
* @size: size of array
* Return: root
*/

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root;

	if (size == 0)
		return (NULL);
	root = NULL;
	while (size-- > 0)
		heap_insert(&root, *array++);
	return (root);
}
