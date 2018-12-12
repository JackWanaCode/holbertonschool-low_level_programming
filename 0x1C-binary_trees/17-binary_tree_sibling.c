#include "binary_trees.h"

/**
* binary_tree_sibling - Entry point
* Description - find to sibbling of a node
* @node: pointer point to root
* Return: pointer to sibling
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left && node->parent->right)
		return (node->n == node->parent->left->n ?
			node->parent->right : node->parent->left);
	return (NULL);
}
