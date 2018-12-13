#include "binary_trees.h"

/**
* binary_tree_delete - Entry point
* Description - delete an entire binary tree
* @tree: pointer point to the root
* Return: nothing
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree->right)
		binary_tree_delete(tree->right);
	free(tree);
}
