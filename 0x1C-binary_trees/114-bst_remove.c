#include "binary_trees.h"


void delete_bst_node(bst_t *node)
{
	if (!node->left && !node->right)
	{
		if (node->parent && node->parent->left->n == node->n)
			node->parent->left = NULL;
		else if (node->parent)
			node->parent->right = NULL;
		free(node);
	}
	else if (!node->right)
	{
		node->n = node->left->n;
		delete_bst_node(node->left);
	}
	else if (!node->left)
	{
		node->n = node->right->n;
		delete_bst_node(node->right);
	}
	else
	{
		if (node->right->left)
		{
			node->n = node->right->left->n;
			delete_bst_node(node->right->left);
		}
		else if (node->right->right)
		{
			node->n = node->right->right->n;
			delete_bst_node(node->right->right);
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
