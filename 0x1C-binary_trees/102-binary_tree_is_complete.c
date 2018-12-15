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

/**
 * free_list - Entry point
 * Description: free list
 * @head: pointer to struct
 * Return: nothing
 */

void free_list(blist_t *head)
{
	blist_t *jump;

	for (jump = head; jump;)
	{
		head = head->next;
		free(jump);
		jump = head;
	}
}

/**
* complete_check - Entry point
* Description - print the node as level order
* @tree: pointer point to root
* @leaf_depth: deapt of very left leaf
* Return: height
*/

int complete_check(binary_tree_t *tree, size_t leaf_depth)
{
	blist_t *jump;
	blist_t *last;
	blist_t *head;
	size_t check = 0, node_depth = 0;

	last = malloc(sizeof(blist_t));
	if (!last)
		return (0);
	last->node = tree;
	last->next = NULL;
	jump = last;
	head = last;
	while (jump)
	{
		node_depth = binary_tree_depth(jump->node);
		if (check == 0 && (node_depth < leaf_depth) && !jump->node->right)
			check = 1;
		else if ((node_depth < leaf_depth) && check == 1 &&
							(jump->node->right || jump->node->left))
		{
			free_list(head);
			return (0);
		}
		else if (!jump->node->left && jump->node->right)
		{
			free_list(head);
			return (0);
		}
		if (jump->node->left)
		{
			last->next = malloc(sizeof(blist_t));
			if (!last->next)
			{
				free_list(head);
				return (1);
			}
			last = last->next;
			last->node = jump->node->left;
			last->next = NULL;
		}
		if (jump->node->right)
		{
			last->next = malloc(sizeof(blist_t));
			last = last->next;
			last->node = jump->node->right;
			last->next = NULL;
		}
		jump = jump->next;
	}
	free_list(head);
	return (1);
}

/**
* binary_tree_is_complete - Entry point
* Description - check tree complete
* @tree: pointer point to root
* Return: nothing
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t leaf_depth = 0;
	binary_tree_t *temp;

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
	if (!tree)
		return (0);
	return (complete_check((binary_tree_t *)tree, leaf_depth));
}
