#include "binary_trees.h"


/**
* delete_help - Entry point
* Description - delete a node in SBT for basic cases
* @node: node need delete
* @parent: parent
* @i: signal. 2 for root, 1 for left, 0 for right
* Return: nothing
*/

void delete_help(bst_t *parent, bst_t *node, int i)
{
	if (parent && parent->left && parent->left->n == node->n)
	{
		if (i == 1)
			parent->left = node->left;
		else if (i == 0)
			parent->left = node->right;
		else if (i == 2)
			parent->left = NULL;
	}
	else if (parent)
	{
		if (i == 1)
			parent->right = node->left;
		else if (i == 0)
			parent->right = node->right;
		else if (i == 2)
			parent->right = node->left;
	}
	free(node);
}

/**
* delete_bst_node - Entry point
* Description - delete a node in SBT
* @node: node need delete
* Return: nothing
*/

bst_t *delete_bst_node(bst_t *node)
{
	bst_t *temp, *root;

	for (root = node; root->parent; root = root->parent)
		;
	if (!node->left && !node->right)
	{
		temp = node->parent;
		delete_help(temp, node, 2);
		if (!temp)
			root = NULL;
	}
	else if (node->right && node->left)
	{
		for (temp = node->right; temp->left; temp = temp->left)
			;
		node->n = temp->n;
		return (delete_bst_node(temp));
	}
	else
	{
		temp = node->parent;
		if (!temp)
			root = node->right;
		if (!node->right)
		{
			node->left->parent = temp;
			delete_help(temp, node, 1);
		}
		else if (node->right)
		{
			node->right->parent = temp;
			delete_help(temp, node, 0);
		}
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
