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
