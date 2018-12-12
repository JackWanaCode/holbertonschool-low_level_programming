#include "binary_trees.h"

/**
* binary_tree_nodes - Entry point
* Description - measures the nodes of a binary tree
* @tree: pointer point to root
* Return: nothing
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	if (tree->left)
		count += binary_tree_nodes(tree->left) + 1;
	if (tree->right)
	{
		if (tree->left)
			count--;
		count += binary_tree_nodes(tree->right) + 1;
	}
	return (count);
}
