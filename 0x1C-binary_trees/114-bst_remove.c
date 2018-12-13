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
	else if (node->right && node->left)
	{
		temp = node->right;
		while (temp->left)
			temp = temp->left;
		node->n = temp->n;
		return (delete_bst_node(temp));
	}
	else if (!node->right)
	{

		temp = node->parent;
		node->left->parent = temp;
		if (temp && temp->left && temp->left->n == node->n)
			temp->left = node->left;
		else if (temp)
			temp->right = node->left;
		if (!temp)
			root = node->left;
		free(node);
	}
	else if (node->right)
	{
		temp = node->parent;
		node->right->parent = temp;
		if (temp && temp->left && temp->left->n == node->n)
			temp->left = node->right;
		else if (temp)
			temp->right = node->right;
		if (!temp)
			root = node->right;
		free(node);
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
	bst_t *root;

	if (!tree)
		return (NULL);
	root = tree;
	if (root->n == value)
		return (delete_bst_node(root));
	else if (value < root->n && root->left)
		return (bst_remove(root->left, value));
	else if (value > root->n && root->right)
		return (bst_remove(root->right, value));
	for (root = tree; root->parent; root = root->parent)
		;
	return (root);
}
