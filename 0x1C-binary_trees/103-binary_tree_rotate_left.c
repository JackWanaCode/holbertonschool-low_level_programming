#include "binary_trees.h"

/**
* binary_tree_rotate_left - Entry point
* Description - return a pointer to the new root node of the tree once rotated
* @tree: pointer point to root
* Return: pointer
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree->right;

	if (!tree)
		return (NULL);
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;
	tree->parent = new_root;
	new_root->left = tree;
	new_root->parent = NULL;
	return (new_root);
}
