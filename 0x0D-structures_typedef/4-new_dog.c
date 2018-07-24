#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Entry Point
 * Description: create a new dog from struct dog
 * @name: name to pass to new dog
 * @age: age to pass to new dog
 * @owner: owner name to pass to new dog
 *
 * Return: dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *d;
	int i, j;

	if (name == NULL && owner == NULL)
		return (NULL);
	d = malloc(sizeof(struct dog));
	if (d == NULL)
		return (NULL);
	for (i = 0; name[i] != '\0'; i++)
		;
	for (j = 0; owner[j] != '\0'; j++)
		;
	d->name = malloc(sizeof(char) * (i + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	d->owner = malloc(sizeof(char) * (j + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	while (i >= 0)
	{
		d->name[i] = name[i];
		i--;
	}
	while (j >= 0)
	{
		d->owner[j] = owner[j];
		j--;
	}
	d->age = age;
	return (d);
}
