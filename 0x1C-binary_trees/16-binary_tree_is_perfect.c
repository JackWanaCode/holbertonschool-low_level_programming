#include "binary_trees.h"

#define CMP(x, y) ((x) == (y) ? (1) : (0))
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
 * binary_tree_is_perfect - Entry point
 * Description - measures the height of a binary tree
 * @tree: pointer point to root
 * Return: 1 if perfect, else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (CMP(height(tree->left), height(tree->right)) == 0)
		return (0);
	return (1);
}
