#include "hash_tables.h"

/**
 * shash_table_create - Entry point
 * Description: Create a new hash table
 * @size: size of the array
 * Return: pointer newly created hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;
	unsigned long int i = 0;

	if (size == 0)
		return (NULL);
	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!(ht->array))
	{
		free(ht);
		return (NULL);
	}
	for (; i < size; i++)
		ht->array[i] = NULL;
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_get - Entry point
 * Description: retrieves a value associated with a key
 * @key: key
 * @ht: shash table
 * Return: value
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *curr;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);
	idx = key_index((unsigned char *)key, ht->size);
	if (ht->array[idx])
	{
		for (curr = ht->array[idx]; curr; curr = curr->next)
		{
			if (strcmp(curr->key, key) == 0)
				return (curr->value);
		}
	}
	return (NULL);
}

/**
 * shash_table_set - Entry point
 * Description: adds an element to the shash table
 * @key: key
 * @ht: shass table
 * @value: value
 * Return: index of the key
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *hnode;

	if (!ht || !key || !*key || !value)
		return (0);
	if (value == NULL)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	if (ht->array[idx])
	{
		for (hnode = ht->array[idx]; hnode; hnode = hnode->next)
		{
			if (strcmp(hnode->key, key) == 0)
			{
				free(hnode->value);
				hnode->value = strdup(value);
				return (1);
			}
		}
	}
	hnode = malloc(sizeof(shash_node_t));
	if (!hnode)
		return (0);
	hnode->key = strdup(key);
	hnode->value = strdup(value);
	hnode->snext = NULL;
	hnode->sprev = NULL;
	insert_list(ht, hnode, idx);
	insert_dlist(ht, hnode);
	return (1);
}

/**
 * insert_list - Entry point
 * Description: insert node in ordered
 * @node: node need inserted
 * @ht: hast table
 * @idx: at index key
 * Return:
 */

void insert_list(shash_table_t *ht, shash_node_t *node, unsigned long int idx)
{
	shash_node_t *prev = NULL;
	shash_node_t *curr = NULL;

	curr = ht->array[idx];
	if ((!curr && !prev) || (!prev && strcmp(curr->key, node->key) >= 0))
	{
		node->next = ht->array[idx];
		ht->array[idx] = node;
		return;
	}
	while (1)
	{
		prev = curr;
		curr = curr->next;
		if ((curr && strcmp(curr->key, node->key) >= 0) || !curr)
		{
			prev->next = node;
			node->next = curr;
			return;
		}
	}
}

/**
 * insert_dlist - Entry point
 * Description: insert node in ordered
 * @node: node need inserted
 * @ht: hast table
 * Return: nothing
 */

void insert_dlist(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *prev = NULL;
	shash_node_t *curr = ht->shead;

	if (!curr)
	{
		ht->shead = node;
		ht->stail = node;
	}
	else
	{
		while (1)
		{
			if (!curr || strcmp(curr->key, node->key) >= 0)
			{
				node->snext = curr;
				node->sprev = prev;
				if (prev)
					prev->snext = node;
				else
					ht->shead = node;
				if (!curr)
					ht->stail = node;
				else
					curr->sprev = node;
				return;
			}
			prev = curr;
			curr = curr->snext;
		}

	}
}

/**
 * shash_table_print - Entry point
 * Description: prints a hash table in the order that they appear
 * @ht: hash table
 * Return: nothing
 */

void shash_table_print(const shash_table_t *ht)
{
	int sign = 0;
	shash_node_t *curr;

	if (!ht)
		return;
	printf("{");
	for (curr = ht->shead; curr; curr = curr->snext)
	{
		if (sign == 0)
		{
			printf("'%s': '%s'", curr->key, curr->value);
			sign = 1;
		}
		else
			printf(", '%s': '%s'", curr->key, curr->value);
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Entry point
 * Description: prints a hash table in reversed order that they appear
 * @ht: hash table
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int sign = 0;
	shash_node_t *curr;

	if (!ht)
		return;
	printf("{");
	for (curr = ht->stail; curr; curr = curr->sprev)
	{
		if (sign == 0)
		{
			printf("'%s': '%s'", curr->key, curr->value);
			sign = 1;
		}
		else
			printf(", '%s': '%s'", curr->key, curr->value);
	}
	printf("}\n");
}

/**
 * shash_table_delete - Entry Point
 * Description: delete hash table
 * @ht: shash table
 * Return: nothing
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *hnode;
	shash_node_t *temp;

	if (!ht)
		return;
	for (hnode = ht->shead; hnode;)
	{
		temp = hnode;
		hnode = hnode->snext;
		free(temp->value);
		free(temp->key);
		free(temp);
		temp = NULL;
	}
	free(ht->array);
	free(ht);
/*	ht = NULL;*/
}
