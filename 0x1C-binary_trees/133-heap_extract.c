#include "binary_trees.h"
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/**
* height - Entry point
* Description - measures the height of a binary tree
* @tree: pointer point to root
* Return: nothing
*/

size_t height(binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (MAX(height(tree->left), height(tree->right)) + 1);
}

/**
* replace_heap - Entry point
* Description - insert a node follow max heap
* @root: pointer to the root
* @value: value of key will be added
* Return: nothing
*/

void replace_heap(heap_t *root, int value)
{
	if (root->left && root->right)
	{
		if (value >= root->left->n && value >= root->right->n)
		{
			root->n = value;
			return;
		}
		else if (root->left->n > root->right->n)
		{
			root->n = root->left->n;
			replace_heap(root->left, value);
		}
		else
		{
			root->n = root->right->n;
			replace_heap(root->right, value);
		}
	}
	else if (root->left)
	{
		if (value >= root->left->n)
		{
			root->n = value;
			return;
		}
		root->n = root->left->n;
		replace_heap(root->left, value);
	}
	else
		root->n = value;
}

/**
* help_extract - Entry point
* Description - insert a node follow max heap from array
* @root: root
* Return: new root after extract
*/

int help_extract(heap_t **root)
{
	heap_t *temp;

	if (!(*root)->left && !(*root)->right)
	{
		temp = *root;
		free(temp);
		*root = NULL;
		return (1);
	}
	else
	{
		if ((*root)->left && (*root)->right)
			(*root)->n = MAX((*root)->left->n, (*root)->right->n);
		else
			(*root)->n = (*root)->left->n;
		if (height((*root)->left) > height((*root)->right))
		{
			if ((*root)->left && (*root)->right &&
					(*root)->left->n < (*root)->right->n)
				replace_heap((*root)->right, (*root)->left->n);
			return (help_extract(&(*root)->left));
		}
		else
		{
			if ((*root)->left && (*root)->right &&
					(*root)->left->n > (*root)->right->n)
				replace_heap((*root)->left, (*root)->right->n);
			return (help_extract(&(*root)->right));
		}
	}
	return (0);
}

/**
* heap_extract - Entry point
* Description - insert a node follow max heap from array
* @root: root
* Return: new root after extract
*/

int heap_extract(heap_t **root)
{
	int num;

	if (!(*root))
		return (0);
	num = (*root)->n;
	if (help_extract(root))
		return (num);
	return (0);
}
