#include "binary_trees.h"
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
* height - Entry point
* Description - measures the height of a binary tree
* @tree: pointer point to root
* Return: height
*/

size_t height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (MAX(height(tree->left), height(tree->right)) + 1);
}

/**
* check_bst - Entry point
* Description - check the tree is binary search tree?
* @tree: pointer point to root
* @key: key for comparison
* @first: check for first time using
* @check: will be return
* Return: 1 if yes, else 0;
*/

int check_bst(const binary_tree_t *tree, int *key, int *first, int *check)
{
	if (tree->left)
		*check = check_bst(tree->left, key, first, check);
	if (*first == 0)
	{
		*key = tree->n;
		*first = 1;
	}
	else
		if (*key >= tree->n)
			return (0);
		*key = tree->n;
	if (tree->right && *check == 1)
		*check = check_bst(tree->right, key, first, check);
	return (*check);
}

/**
* binary_tree_is_bst - Entry point
* Description - check the tree is binary search tree?
* @tree: pointer point to root
* Return: 1 if yes, else 0;
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int key = 0;
	int first = 0, check = 1;

	if (!tree)
		return (0);
	return (check_bst(tree, &key, &first, &check));
}

/**
* binary_tree_is_avl - Entry point
* Description - check the tree is AVL tree?
* @tree: pointer point to root
* Return: 1 if yes, else 0;
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	if (binary_tree_is_bst(tree) == 0)
		return (0);
	if (abs(height(tree->left) - height(tree->right)) > 1)
		return (0);
	if (tree->left && tree->right)
		return (MIN(binary_tree_is_avl(tree->left),
								binary_tree_is_avl(tree->right)));
	return (1);
}
