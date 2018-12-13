#include "binary_trees.h"

/**
* binary_tree_is_full - Entry point
* Description - measures the size of a binary tree
* @tree: pointer point to root
* Return: nothing
*/


int binary_tree_is_full(const binary_tree_t *tree)
{
	int check = 1;

	if (!tree)
		return (0);
	if (tree->left && tree->right && check == 1)
	{
		check = binary_tree_is_full(tree->left);
		check = binary_tree_is_full(tree->right);
	}
	else if (tree->left || tree->right)
		return (0);
	return (check);
}
