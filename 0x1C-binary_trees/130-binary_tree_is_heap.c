#include "binary_trees.h"
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
* depth - Entry point
* Description - measures the depth of a binary tree
* @temp_root: pointer point to root
* @node: pointer to node need to be get depth
* Return: depth
*/


size_t depth(binary_tree_t *temp_root, binary_tree_t *node)
{
	size_t count = 0;

	for (; node != temp_root; node = node->parent)
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
	int x = 0, y = 0;

	if (!node)
		return (1);
	if (((node->left) && node->n < node->left->n) ||
	    ((node->right) && node->n < node->right->n))
		return (0);
	if (!node->left && node->right)
		return (0);
	if (depth(temp_root, node) == leaf_depth)
	{
		if (node->left || node->right)
			return (0);
		return (1);
	}
	if (depth(temp_root, node) == leaf_depth - 1)
	{
		if (node->left && !node->right)
		{
			if ((*count_left)++ < 1)
				return (1);
			return (0);
		}
		if (!node->left && !node->right && (*count_left)++ == 0)
			return (1);
		if (node->left && node->right && *count_left > 0)
			return (0);
	}
	if (depth(temp_root, node) < leaf_depth - 1 &&
	    (!node->left || !node->right))
		return (0);
	x = complete_check(temp_root, node->left, leaf_depth, count_left);
	y = complete_check(temp_root, node->right, leaf_depth, count_left);
	return (MIN(x, y));
}

/**
* check_heap - Entry point
* Description - check the binary tree is MAX HEAP or not
* @tree: pointer point to root
* @temp_root: root to be checked
* Return: height
*/

int check_heap(binary_tree_t *temp_root, binary_tree_t *tree)
{
	binary_tree_t *temp;
	size_t leaf_depth = 0;
	int count_left = 0;

	temp = (binary_tree_t *)tree;
	while (temp->left)
	{
		leaf_depth++;
		temp = temp->left;
	}
	if (leaf_depth == 0)
		return (1);
	return (complete_check(temp_root, tree, leaf_depth, &count_left));
}


/**
* binary_tree_is_heap - Entry point
* Description - insert a node follow max heap
* @tree: pointer to the first element in sorted array
* Return: root
*/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_heap((binary_tree_t *)tree, (binary_tree_t *)tree));
}
