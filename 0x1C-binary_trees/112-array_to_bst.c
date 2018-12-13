#include "binary_trees.h"

/**
* array_to_bst - Entry point
* Description - insert a node (take from elements in a given array) to bst tree
* @array: array of keys
* @size: size of array
* Return: return a pointer to the root, or NULL on failure
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	while (size > 0)
	{
		bst_insert(&root, *array++);
		size--;
	}
	return (root);
}
