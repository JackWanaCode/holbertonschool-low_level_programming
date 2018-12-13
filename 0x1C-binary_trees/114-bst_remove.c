#include "binary_trees.h"

/**
* delete_bst_node - Entry point
* Description - delete a node in SBT
* @node: node need delete
* Return: nothing
*/

bst_t *delete_bst_node(bst_t *node)
{
	bst_t *temp;
	bst_t *root;

	for (root = node; root->parent; root = root->parent)
		;
	if (!node->left && !node->right)
	{
		temp = node->parent;
		if (temp && temp->left && temp->left->n == node->n)
			temp->left = NULL;
		else if (temp)
			temp->right = NULL;
		free(node);
		if (!temp)
			root = NULL;
	}
	else if (node->right)
	{
		if (node->right->left)
		{
			node->n = node->right->left->n;
			return (delete_bst_node(node->right->left));
		}
		node->n = node->right->n;
		return (delete_bst_node(node->right));
	}
	else if (!node->right)
	{
		if (node->left->right)
		{
			node->n = node->left->right->n;
			return (delete_bst_node(node->left->right));
		}
		node->n = node->left->n;
		return (delete_bst_node(node->left));
	}
	return (root);
}


/**
* bst_remove - Entry point
* Description - insert a node (take from elements in a given array) to bst tree
* @tree: pointer point to root
* @value: value of key
* Return: return a pointer to the node containing a value equals to value
*/

bst_t *bst_remove(bst_t *tree, int value)
{
	if (tree->n == value)
		return (delete_bst_node(tree));
	else if (value < tree->n)
		return (bst_remove(tree->left, value));
	return (bst_remove(tree->right, value));
}
