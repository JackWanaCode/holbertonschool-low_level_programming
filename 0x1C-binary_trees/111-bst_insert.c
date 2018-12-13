#include "binary_trees.h"

/**
* bst_insert - Entry point
* Description - insert a node to bst tree
* @tree: pointer point to root
* @value: value of key
* Return: return a pointer to the created node, or NULL on failure
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t **temp_node;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	else
	{
		if (value < (*tree)->n)
		{
			if ((*tree)->left)
				temp_node = &(*tree)->left;
			else
			{
				(*tree)->left = binary_tree_node(*tree, value);
				return ((*tree)->left);
			}
		}
		else if (value > (*tree)->n)
		{
			if ((*tree)->right)
				temp_node = &(*tree)->right;
			else
			{
				(*tree)->right = binary_tree_node(*tree, value);
				return ((*tree)->right);
			}
		}
		else
			return (NULL);
	}
	return (bst_insert(temp_node, value));
}
