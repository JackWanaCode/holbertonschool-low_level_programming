#include "binary_trees.h"

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
* binary_tree_levelorder - Entry point
* Description - print the node as level order
* @tree: pointer point to root
* @func: pointer to function
* Return: height
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	blist_t *jump;
	blist_t *last;
	blist_t *head;

	if (!tree || !func)
		return;
	last = malloc(sizeof(blist_t));
	if (!last)
		return;
	last->node = tree;
	last->next = NULL;
	jump = last;
	head = last;
	while (jump)
	{
		func(jump->node->n);
		if (jump->node->left)
		{
			last->next = malloc(sizeof(blist_t));
			if (!last->next)
			{
				free_list(head);
				return;
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
}
