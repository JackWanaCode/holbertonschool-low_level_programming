#include "binary_trees.h"

/**
* binary_tree_is_root - Entry point
* Description - check node is a leaf or not.
* @node: pointer point to the node need check
* Return: 1 if node, else 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && !node->parent)
		return (1);
	return (0);
}
