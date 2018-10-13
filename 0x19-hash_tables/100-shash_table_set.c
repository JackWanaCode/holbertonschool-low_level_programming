#include "hash_tables.h"

void insert_sorted_list(shash_table_t *ht, shash_node_t *node, unsigned long int idx);
void insert_dlist(shash_table_t *ht, shash_node_t *node);

/**
 * shash_table_set - Entry point
 * Description: adds an element to the hash table
 * @key: key
 * @ht: hast table
 * @value: value
 * Return: index of the key
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *hnode;

	if (!ht || !key || !*key || !value)
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
	insert_sorted_list(ht, hnode, idx);
	insert_dlist(ht, hnode);
	return (1);
}

/**
 * insert_sorted_list - Entry point
 * Description: insert node in ordered
 * @node: node need inserted
 * @ht: hast table
 * @idx: at index key
 * Return:
 */

void insert_sorted_list(shash_table_t *ht, shash_node_t *node, unsigned long int idx)
{
	shash_node_t *prev = NULL;
	shash_node_t *curr = NULL;

	curr = ht->array[idx];
	while (1)
	{
		if ((!curr && !prev) || (!prev && strcmp(curr->key, node->key) >= 0))
		{
			node->next = ht->array[idx];
			ht->array[idx] = node;
			return;
		}
		else
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
}

/**
 * insert_sorted_list - Entry point
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
