#include "binary_trees.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))

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
 * binary_tree_height - Entry point
 * Description - measures the height of a binary tree
 * @tree: pointer point to root
 * Return: height
 */


size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree) - 1);
}
