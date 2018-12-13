#include "binary_trees.h"
#define CMP(x, y) ((x) == (y) ? 1 : 0)
#define MIN(x, y) ((x) < (y) ? (x) : (y))

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
 * check_perfect - Entry point
 * Description - measures the height of a binary tree
 * @tree: pointer point to root
 * @leaf_depth: depth of leaves
 * Return: 1 if perfect, else 0
 */

int check_perfect(const binary_tree_t *tree, size_t leaf_depth)
{
	if (!tree->left && !tree->right)
		return (CMP(binary_tree_depth(tree), leaf_depth));
	else if (!tree->left || !tree->right)
		return (0);
	return (MIN(check_perfect(tree->left, leaf_depth),
							check_perfect(tree->right, leaf_depth)));
}

/**
 * binary_tree_is_perfect - Entry point
 * Description - measures the height of a binary tree
 * @tree: pointer point to root
 * Return: 1 if perfect, else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaf_depth;
	const binary_tree_t *jump;

	if (!tree)
		return (0);
	for (jump = tree; jump->left; jump = jump->left)
		;
	leaf_depth = binary_tree_depth(jump);
	return (check_perfect(tree, leaf_depth));
}
