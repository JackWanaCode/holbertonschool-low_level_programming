#include "hash_tables.h"

/**
 * key_index - Entry point
 * Description: return index of key
 * @key: key
 * @size: size of the array
 * Return: index of the key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2((unsigned char *)key) % size);
}
