#include "binary_trees.h"

/**
* binary_tree_leaves - Entry point
* Description - measures the leaves of a binary tree
* @tree: pointer point to root
* Return: nothing
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
		count += binary_tree_leaves(tree->left);
	if (tree->right)
	{
		count += binary_tree_leaves(tree->right);
	}
	return (count);
}
