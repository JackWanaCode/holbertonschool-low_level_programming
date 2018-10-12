#include "hash_tables.h"

/**
 * hash_table_print - Entry point
 * Description: prints a hash table in the order that they appear
 * @ht: hash table
 * Return: nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx;
	int sign = 0;

	if (!ht)
		return;
	for (idx = 0; idx < 1024; idx++)
		if (ht->array[idx] && sign == 0)
		{
			printf("{'%s': '%s'", ht->array[idx]->key, ht->array[idx]->value);
			sign = 1;
		}
		else if (ht->array[idx])
		{
			printf(", '%s': '%s'", ht->array[idx]->key, ht->array[idx]->value);
		}
	printf("}\n");
}
