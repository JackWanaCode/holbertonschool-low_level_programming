#include "hash_tables.h"

/**
 * hash_table_create - Entry point
 * Description: Create a new hash table
 * @size: size of the array
 * Return: pointer newly created hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashtb = NULL;
	unsigned long int i = 0;

	if (size < 1)
		return (NULL);
	hashtb = malloc(sizeof(hash_table_t));
	if (!hashtb)
		return (NULL);
	hashtb->array = malloc(sizeof(hash_node_t *) * size);
	if (!(hashtb->array))
		return (NULL);
	for (; i < size; i++)
		hashtb->array[i] = NULL;
	hashtb->size = size;
	return (hashtb);
}
