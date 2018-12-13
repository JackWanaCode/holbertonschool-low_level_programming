#include "binary_trees.h"

/**
* binary_tree_depth - Entry point
* Description - measures the depth of a binary tree
* @tree: pointer point to root
* Return: nothing
*/


size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *jump;
	size_t count = 0;

	if (!tree)
		return (0);
	for (jump = tree; jump && jump->parent; jump = jump->parent)
		count++;
	return (count);
}
