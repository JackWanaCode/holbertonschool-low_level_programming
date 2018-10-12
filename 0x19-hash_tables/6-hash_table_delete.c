#include "hash_tables.h"

/**
 * hash_table_delete - Entry Point
 * Description: delete hash table
 * @ht: hash table
 * Return: nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *hnode;
	hash_node_t *temp;

	if (!ht)
		return;
	for (idx = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx])
		{
			for (hnode = ht->array[idx]; hnode;)
			{
				temp = hnode;
				hnode = hnode->next;
				free(temp->value);
				free(temp->key);
				free(temp);
				temp = NULL;
			}
		}
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}
