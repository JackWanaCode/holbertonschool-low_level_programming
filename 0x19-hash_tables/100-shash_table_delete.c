#include "hash_tables.h"

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
	ht = NULL;
}
