#include "binary_trees.h"

/**
* making_avl_tree - Entry point
* Description - insert a node follow AVL tree based sored array
* @array: pointer to the first element in sorted array
* @height: height of binary_trees
* @root: root
* @remain: number of leaf at max height
* Return: root
*/

void making_avl_tree(avl_t *root, int height, int **array, size_t *remain)
{
	if (height >= 0)
	{
		if (height > 1)
		{
			root->left = binary_tree_node(root, 0);
			root->right = binary_tree_node(root, 0);
		}
		if (height == 1)
		{
			if (*remain > 0)
			{
				root->left = binary_tree_node(root, 0);
				(*remain)--;
			}
			if (*remain > 0)
			{
				root->right = binary_tree_node(root, 0);
				(*remain)--;
			}
		}
		height--;
		if (root->left)
			making_avl_tree(root->left, height, array, remain);
		root->n = *((*array)++);
		if (root->right)
			making_avl_tree(root->right, height, array, remain);
	}
}


/**
* sorted_array_to_avl - Entry point
* Description - insert a node follow AVL tree
* @array: pointer to the first element in sorted array
* @size: size of array
* Return: root
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t num = 2, remain = 0;
	int height = 0;
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);
	root = binary_tree_node(NULL, *array);
	if (size < 2)
		return (root);
	while (num - 1 < size)
	{
		height++;
		num *= 2;
	}
	remain = size - (num / 2 - 1);
	making_avl_tree(root, height, &array, &remain);
	return (root);
}
