#include "hash_tables.h"

/**
 * hash_table_get - Entry point
 * Description: retrieves a value associated with a key
 * @key: key
 * @ht: hash table
 * Return: value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int size = 1024;
	unsigned long int idx;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);
	idx = key_index((unsigned char *)key, size);
	if (ht->array[idx])
	{
		return (ht->array[idx]->value);
	}
	return (NULL);
}
