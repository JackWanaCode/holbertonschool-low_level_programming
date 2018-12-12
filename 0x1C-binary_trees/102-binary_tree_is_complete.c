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
* depth - Entry point
* Description - measures the depth of a binary tree
* @tree: pointer point to root
* Return: nothing
*/


size_t depth(const binary_tree_t *tree)
{
	const binary_tree_t *jump;
	size_t count = 1;

	for (jump = tree; jump && jump->parent; jump = jump->parent)
		count++;
	return (count);
}

/**
* free_list - Entry point
* Description - free the linked list
* @head: pointer point to root
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
* binary_tree_is_complete - Entry point
* Description - print the node as level order
* @tree: pointer point to root
* Return: height
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	blist_t *jump;
	blist_t *last;
	blist_t *head;
	size_t h;
	int check = 1;

	if (!tree)
		return (0);
	h = height(tree);
	last = malloc(sizeof(blist_t));
	if (!last)
		return (0);
	last->node = tree;
	last->next = NULL;
	jump = last;
	head = last;
	while (depth(jump->node) < h)
	{
		if (jump->node->left)
		{
			if (check == 0)
			{
				free(head);
				return (0);
			}
			last->next = malloc(sizeof(blist_t));
			if (!last->next)
			{
				free_list(head);
				return (0);
			}
			last = last->next;
			last->node = jump->node->left;
			last->next = NULL;
		}
		else if (check == 1)
		/* if not the second last one */
		{
			free_list(head);
			return (0);
		}
		if (jump->node->right)
		{
			if (check == 0)
			{
				free(head);
				return (0);
			}
			last->next = malloc(sizeof(blist_t));
			if (!last->next)
			{
				free_list(head);
				return (0);
			}
			last = last->next;
			last->node = jump->node->right;
			last->next = NULL;
		}
		else
		/* start to watch the jumping */
			check = 0;
		jump = jump->next;
	}
	free_list(head);
	return (1);
}
