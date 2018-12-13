#include "binary_trees.h"

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
