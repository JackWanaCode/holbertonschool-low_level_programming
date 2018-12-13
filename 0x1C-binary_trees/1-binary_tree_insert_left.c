#include "binary_trees.h"

/**
* binary_tree_insert_left - Entry point
* Description - insert to the left
* @parent: pointer to the parent node
* @value: value to put to the new node
* Return: pointer point to new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *left_node;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	left_node = parent->left;
	parent->left = new_node;
	new_node->parent = parent;
	if (left_node)
	{
		new_node->left = left_node;
		left_node->parent = new_node;
	}
	return (new_node);
}
