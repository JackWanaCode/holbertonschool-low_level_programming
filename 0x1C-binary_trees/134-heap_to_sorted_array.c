#include "binary_trees.h"

/**
* binary_tree_size - Entry point
* Description - measures the size of a binary tree
* @tree: pointer point to root
* Return: nothing
*/


size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
		count += binary_tree_size(tree->left) + 1;
	if (tree->right)
	{
		if (tree->left)
			count--;
		count += binary_tree_size(tree->right) + 1;
	}
	return (count);
}

/**
* heap_sort - Entry point
* Description - convert HEAP BINARY TREE to SORTED ARRAY
* @heap: root
* @ret_arr: address of array_to_heap
* @index: index of element in array
* Return: pointer to new sorted array
*/

void heap_sort(heap_t **heap, int *ret_arr, int *index)
{
	if (*heap)
	{
		ret_arr[(*index)++] = heap_extract(heap);
		heap_sort(&(*heap), ret_arr, index);
	}
}

/**
* heap_to_sorted_array - Entry point
* Description - insert a node follow max heap from array
* @heap: root
* @size: address of size
* Return: pointer to new sorted array
*/

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *ret_arr, index = 0;

	if (!heap)
		return (NULL);
	*size = binary_tree_size(heap);
	ret_arr = malloc(sizeof(int) * (*size));
	if (!ret_arr)
		return (NULL);
	heap_sort(&heap, ret_arr, &index);
	return (ret_arr);
}
