#include "binary_trees.h"

/**
* self_balance_help - Entry point
* Description - help to make self balance
* @father: parent level of current node
* @current: current node
* @child: current's child
* Return: nothing
*/

void self_balance_help(avl_t *father, avl_t *current, avl_t *child)
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

/**
* set_self_balance - Entry point
* Description - set up before doing balance tree
* @node: added node
* Return: nothing
*/

void set_self_balance(avl_t *node)
{
	avl_t *father;
	avl_t *child;
	avl_t *current = node;
	avl_t *temp = node;
	int factor = binary_tree_balance(current);

	while (current->parent && factor < 2 && factor > -2)
	{
		current = current->parent;
		factor = binary_tree_balance(current);
	}
	if (factor >= 2 || factor <= -2)
	{
		father = current;
		for (temp = node; temp->parent != father; temp = temp->parent)
			;
		current = temp;
		for (temp = node; temp->parent != current; temp = temp->parent)
			;
		child = temp;
		self_balance_help(father, current, child);
	}
}

/**
* avl_insert_f - Entry point
* Description - help to donw level of double pointer
* @tree: pointer point to root
* @value: value of node
* Return: added node pointer
*/

avl_t *avl_insert_f(avl_t *tree, int value)
{
	avl_t *temp;

	if (value > tree->n)
	{
		if (!tree->right)
		{
			tree->right = binary_tree_node(tree, value);
			temp = tree->right;
			set_self_balance(tree->right);
			return (temp);
		}
		return (avl_insert_f(tree->right, value));
	}
	else if (value < tree->n)
	{
		if (!tree->left)
		{
			tree->left = binary_tree_node(tree, value);
			temp = tree->left;
			set_self_balance(tree->left);
			return (temp);
		}
		return (avl_insert_f(tree->left, value));
	}
	return (NULL);
}

/**
* avl_insert - Entry point
* Description - insert a node follow AVL tree
* @tree: pointer point to root
* @value: value of node
* Return: added node pointer
*/

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *root, *node;

	if (!(*tree))
	{
		root =  (binary_tree_node(NULL, value));
		*tree = root;
		return (root);
	}
	root = *tree;
	node = avl_insert_f(root, value);
	for (; (*tree)->parent; (*tree) = (*tree)->parent)
		;
	return (node);
}
