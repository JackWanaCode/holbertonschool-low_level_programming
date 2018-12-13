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

	for (jump = tree; jump && jump->parent; jump = jump->parent)
		count++;
	return (count);
}

/**
* binary_trees_ancestor - Entry point
* Description - find the lowest ancestor
* @first: pointer point to first node
* @second: pointer point to second node
* Return: pointer point to ancester
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d1;
	size_t d2;

	if (!first || !second)
		return (NULL);
	d1 = binary_tree_depth(first);
	d2 = binary_tree_depth(second);
	if (d1 > d2)
		return (binary_trees_ancestor(first->parent, second));
	else if (d1 < d2)
		return (binary_trees_ancestor(first, second->parent));
	if (first == second)
		return ((binary_tree_t *)first);
	return (binary_trees_ancestor(first->parent, second->parent));
}
