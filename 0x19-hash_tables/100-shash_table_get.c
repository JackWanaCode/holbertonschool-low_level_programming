#include "hash_tables.h"

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
