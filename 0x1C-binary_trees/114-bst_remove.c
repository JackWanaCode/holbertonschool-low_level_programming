#include "binary_trees.h"

/**
* delete_bst_node - Entry point
* Description - delete a node in SBT
* @node: node need delete
* Return: nothing
*/

void delete_bst_node(bst_t *node)
{
	bst_t *temp;

	if (!node->left && !node->right)
	{
		temp = node->parent;
		if (temp && temp->left && temp->left->n == node->n)
			temp->left = NULL;
		else if (temp)
			temp->right = NULL;
		free(node);
	}
	else if (node->right)
	{
		if (node->right->left)
		{
			node->n = node->right->left->n;
			delete_bst_node(node->right->left);
		}
		else
		{
			node->n = node->right->n;
			delete_bst_node(node->right);
		}
	}
	else if (!node->right)
	{
		if (node->left->right)
		{
			node->n = node->left->right->n;
			delete_bst_node(node->left->right);
		}
		else
		{
			node->n = node->left->n;
			delete_bst_node(node->left);
		}
	}
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

	if (tree->n == value)
	{
		for (root = tree; root->parent; root = root->parent)
			;
		delete_bst_node(tree);
	}
	else if (value < tree->n)
		return (bst_remove(tree->left, value));
	else
		return (bst_remove(tree->right, value));
	return (root);
}
