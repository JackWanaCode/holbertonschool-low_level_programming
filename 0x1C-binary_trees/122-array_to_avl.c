#include "binary_trees.h"

/**
* array_to_avl - Entry point
* Description - insert a node follow AVL tree
* @array: pointer to the first element in array
* @size: size of array
* Return: root
*/

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array)
		while (size > 0)
		{
			avl_insert(&root, *array++);
			size--;
		}
	return (root);
}
