#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Entry Point
 * Description: free struct dog that created before
 * @d: pointer to structure dog_t
 *
 * Return: dog_t
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
