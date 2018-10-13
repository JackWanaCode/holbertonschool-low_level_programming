#include "hash_tables.h"

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
