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
	hash_node_t *curr;

	if (!ht)
		return;
	printf("{");
	for (idx = 0; idx < ht->size; idx++)
		if (ht->array[idx])
		{
			for (curr = ht->array[idx]; curr; curr = curr->next)
			{
				if (sign == 0)
				{
					printf("'%s': '%s'", curr->key, curr->value);
					sign = 1;
				}
				else
					printf(", '%s': '%s'", curr->key, curr->value);
			}
		}
	printf("}\n");
}
