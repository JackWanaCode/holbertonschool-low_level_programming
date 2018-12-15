#include "binary_trees.h"

/**
* self_balance_help_remove - Entry point
* Description - help to make self balance
* @father: parent level of current node
* @current: current node
* @child: current's child
* Return: nothing
*/

void self_balance_help_remove(avl_t *father, avl_t *current, avl_t *child)
{
	if (father && current && child)
	{
		if ((father->left && father->left->n == current->n) &&
				(current->left && current->left->n == child->n))
		{
			binary_tree_rotate_right(father);
		}
		if ((father->left && father->left->n == current->n) &&
				(current->right && current->right->n == child->n))
		{
			binary_tree_rotate_left(current);
			binary_tree_rotate_right(father);
		}
		if ((father->right && father->right->n == current->n) &&
				(current->right && current->right->n == child->n))
		{
			binary_tree_rotate_left(father);
		}
		if ((father->right && father->right->n == current->n) &&
				(current->left && current->left->n == child->n))
		{
			binary_tree_rotate_right(current);
			binary_tree_rotate_left(father);
		}
	}
}

/**
* make_it_balance - Entry point
* Description - make the tree balance
* @node: node need to check
* Return: nothing
*/

void make_it_balance(avl_t *node)
{
	avl_t *father;
	avl_t *child = NULL;
	avl_t *current = node;
	int factor = binary_tree_balance(current);

	while (current->parent && factor < 2 && factor > -2)
	{
		current = current->parent;
		factor = binary_tree_balance(current);
	}
	if (factor >= 2 || factor <= -2)
	{
		father = current;

		if (factor >= 2)
		{
			current = father->left;
			if (father->left->right)
				child = father->left->right;
			else if (father->left->left)
				child = father->left->left;
		}
		else
		{
			current = father->right;
			if (father->right->right)
				child = father->right->right;
			else if (father->right->left)
				child = father->right->left;
		}
		self_balance_help_remove(father, current, child);
	}
}

/**
* delete_help - Entry point
* Description - delete a node in AVL for basic cases
* @node: node need delete
* @parent: parent
* @i: signal. 2 for root, 1 for left, 0 for right
* Return: nothing
*/

avl_t *delete_help(avl_t *parent, avl_t *node, int i)
{
	if (parent && parent->left && parent->left->n == node->n)
	{
		if (i == 1)
			parent->left = node->left;
		else if (i == 0)
			parent->left = node->right;
		else if (i == 2)
			parent->left = NULL;
	}
	else if (parent)
	{
		if (i == 1)
			parent->right = node->left;
		else if (i == 0)
			parent->right = node->right;
		else if (i == 2)
			parent->right = NULL;
	}
	else if (!parent)
		parent = node->left ? node->left : node->right;
	free(node);
	return (parent);
}

/**
* delete_avl_node - Entry point
* Description - delete a node in SBT
* @node: node need delete
* Return: nothing
*/

avl_t *delete_avl_node(avl_t *node)
{
	bst_t *temp, *root;

	for (root = node; root->parent; root = root->parent)
		;
	if (!node->left && !node->right)
	{
		temp = node->parent;
		if (!temp)
		{
			free(node);
			return (NULL);
		}
		make_it_balance(delete_help(temp, node, 2));
	}
	else if (node->right && node->left)
	{
		for (temp = node->right; temp->left; temp = temp->left)
			;
		node->n = temp->n;
		delete_avl_node(temp);
	}
	else
	{
		temp = node->parent;
		if (!node->right)
		{
			node->left->parent = temp;
			root = node->left;
			make_it_balance(delete_help(temp, node, 1));
		}
		else if (node->right)
		{
			node->right->parent = temp;
			root = node->right;
			make_it_balance(delete_help(temp, node, 0));
		}
	}
	return (root);
}


/**
* avl_remove - Entry point
* Description - insert a node (take from elements in a given array) to AVL tree
* @root: pointer point to root
* @value: value of key
* Return: return a pointer to root
*/

avl_t *avl_remove(avl_t *root, int value)
{
	bst_t *node;

	if (!root)
		return (NULL);
	node = root;
	if (node->n == value)
		root = delete_avl_node(node);
	else if (value < node->n && node->left)
		return (avl_remove(root->left, value));
	else if (value > node->n && node->right)
		return (avl_remove(root->right, value));
	for (; root && root->parent; root = root->parent)
		;
	return (root);
}
