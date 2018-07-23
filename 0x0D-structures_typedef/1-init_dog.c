#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Entry Point
 * Description: create struct to keep data of dog
 * @d: pointer to struct dog.
 * @name: pointer to member name of dog.
 * @age: member age of dog.
 * @owner: member owner of dog.
 *
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
