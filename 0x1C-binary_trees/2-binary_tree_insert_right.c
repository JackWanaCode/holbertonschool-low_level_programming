#include "binary_trees.h"

/**
* binary_tree_insert_right - Entry point
* Description - insert to right
* @parent: pointer to the parent node
* @value: value to put to the new node
* Return: pointer point to new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *right_node;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	right_node = parent->right;
	parent->right = new_node;
	new_node->parent = parent;
	if (right_node)
	{
		new_node->right = right_node;
		right_node->parent = new_node;
	}
	return (new_node);
}
