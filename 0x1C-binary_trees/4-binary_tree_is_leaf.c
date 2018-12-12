#include "binary_trees.h"

/**
* binary_tree_is_leaf - Entry point
* Description - check node is a leaf or not.
* @node: pointer point to the node need check
* Return: 1 if node, else 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);
	return (1);
}
