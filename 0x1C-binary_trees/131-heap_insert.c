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
* heap_insert - Entry point
* Description - insert a node follow max heap
* @root: pointer to the root
* @value: value of key will be added
* @ret_node: node is added
* @leaf_depth: depth of leaf
* Return: ret_node
*/

heap_t *insert_heap(heap_t *root, heap_t *ret_node,
		    int value, size_t leaf_depth)
{
	int temp;

	if (value < root->n)
	{
		if (!root->left)
		{
			root->left = binary_tree_node(root, value);
			return ((heap_t *)root->left);
		}
		else if (!root->right)
		{
			root->right = binary_tree_node(root, value);
			return ((heap_t *)root->right);
		}
		else if (check_perfect(root->left, leaf_depth) &&
			 !check_perfect(root->right, leaf_depth))
			return (insert_heap(root->right, ret_node,
					    value, leaf_depth));
		return (insert_heap(root->left, ret_node, value, leaf_depth));
	}
	temp = root->n;
	root->n = value;
	if (!ret_node)
		ret_node = root;
	if (!root->left)
	{
		root->left = binary_tree_node(root, temp);
		return (ret_node);
	}
	else if (!root->right)
	{
		root->right = binary_tree_node(root, temp);
		return (ret_node);
	}
	else if (check_perfect(root->left, leaf_depth) &&
		 !check_perfect(root->right, leaf_depth))
		return (insert_heap(root->right, ret_node, temp, leaf_depth));
	return (insert_heap(root->left, ret_node, temp, leaf_depth));
}

/**
* heap_insert - Entry point
* Description - insert a node follow max heap
* @root: pointer to the root
* @value: value of key will be added
* Return: root
*/

heap_t *heap_insert(heap_t **root, int value)
{
	size_t leaf_depth = 0;
	heap_t *temp;

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	temp = *root;
	while (temp->left)
	{
		leaf_depth++;
		temp = temp->left;
	}
	return (insert_heap(*root, NULL, value, leaf_depth));
}
