#include "binary_trees.h"



/**
* binary_tree_rotate_right - Entry point
* Description - return a pointer to the new root node of the tree once rotated
* @tree: pointer point to root
* Return: pointer
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree->left;

	tree->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tree;
	tree->parent = new_root;
	new_root->right = tree;
	new_root->parent = NULL;
	return (new_root);
}
