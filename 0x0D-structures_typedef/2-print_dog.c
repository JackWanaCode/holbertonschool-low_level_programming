#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Entry Point
 * Description: print a struct dog
 * @d: pointer to struct dog.
 *
 * Return: nothing
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	else
	{
		if (d->name == NULL)
			d->name = "(nil)";
		printf("Name: %s\n", d->name);
		printf("Age: %.6f\n", d->age);
		if (d->owner == NULL)
			d->owner = "(nil)";
		printf("Owner: %s\n", d->owner);
	}
}
