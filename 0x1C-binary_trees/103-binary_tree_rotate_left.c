#include "binary_trees.h"

/**
* binary_tree_rotate_left - Entry point
* Description - return a pointer to the new root node of the tree once rotated
* @tree: pointer point to root
* Return: pointer
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	if (!tree->right)
		return (tree);
	temp = tree->parent;
	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;
	tree->parent = new_root;
	new_root->left = tree;
	new_root->parent = temp;
	if (temp && temp->left && temp->left->n == tree->n)
		temp->left = new_root;
	else if (temp)
		temp->right = new_root;
	return (new_root);

}
