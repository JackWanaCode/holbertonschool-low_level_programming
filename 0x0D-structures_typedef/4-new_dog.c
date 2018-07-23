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

	d = malloc(sizeof(struct dog));
	if (d == NULL)
		return (NULL);
	if (d->name == NULL)
		d->name = "";
	else
		d->name = name;
	d->age = age;
	if (d->owner == NULL)
		d->owner = "";
	else
		d->owner = owner;
	return (d);
}
