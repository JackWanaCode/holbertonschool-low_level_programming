#include "binary_trees.h"
#define CMP(x, y) ((x) == (y) ? 1 : 0)
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
* depth - Entry point
* Description - measures the depth of a binary tree
* @root: pointer point to root
* @node: pointer to node need to be get depth
* Return: depth
*/


size_t depth(binary_tree_t *root, binary_tree_t *node)
{
	size_t count = 0;

	for (; node != root; node = node->parent)
		count++;
	return (count);
}

/**
* complete_check - Entry point
* Description - check tree is complete?
* @temp_root: pointer point to root
* @node: current node pointer
* @leaf_depth: depth of leaf;
* @count_left: left counting
* Return: 1 if yes, else 0
*/

int complete_check(binary_tree_t *temp_root, binary_tree_t *node,
										size_t leaf_depth, int *count_left)
{
	if (!node)
		return (1);
	if (!node->left && node->right)
		return (0);
	if (depth(temp_root, node) > leaf_depth)
		return (0);
	if (depth(temp_root, node) == leaf_depth - 1)
	{
		if (node->left && !node->right)
		{
			if (*count_left == 0)
				*count_left = 1;
			else
				return (0);
		}
		if (!node->left && !node->right)
			*count_left = 1;
		if (node->left && node->right && *count_left == 1)
			return (0);
	}
	if (depth(temp_root, node) < leaf_depth - 1)
	{
		if (!node->left && !node->right)
			return (0);
	}
	return (MIN(complete_check(temp_root, node->left, leaf_depth, count_left),
							complete_check(temp_root, node->right, leaf_depth, count_left)));
}

/**
* binary_tree_is_complete - Entry point
* Description - check the binary tree is complete or not
* @tree: pointer point to root
* Return: height
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *temp;
	size_t leaf_depth = 0;
	int count_left = 0;

	if (!tree)
		return (0);
	temp = (binary_tree_t *)tree;
	while (temp->left)
	{
		leaf_depth++;
		temp = temp->left;
	}
	if (leaf_depth == 0)
		return (1);
	return (complete_check((binary_tree_t *)tree, (binary_tree_t *)tree,
													leaf_depth, &count_left));
}
