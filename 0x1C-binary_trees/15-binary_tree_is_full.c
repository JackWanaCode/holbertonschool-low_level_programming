#include "binary_trees.h"
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
* binary_tree_is_full - Entry point
* Description - measures the size of a binary tree
* @tree: pointer point to root
* Return: nothing
*/


int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left && tree->right)
	{
		return (MIN(binary_tree_is_full(tree->left),
			    binary_tree_is_full(tree->right)));
	}
	if (!tree->left && !tree->right)
		return (1);
	return (0);
}
