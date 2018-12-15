#include "binary_trees.h"

/**
* binary_tree_inorder - Entry point
* Description - goes through a binary tree using in-order traversal
* @tree: pointer point to root
* @func: is a pointer to a function to call for each node.
* Return: nothing
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left)
		binary_tree_inorder(tree->left, func);
	func(tree->n);
	if (tree->right)
		binary_tree_inorder(tree->right, func);
}
