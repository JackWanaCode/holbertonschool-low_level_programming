#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - Entry point
 * Description: print the name as format requested
 * @name: string to be printed
 * @f: pointer to function
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name)
		return;
	f(name);
}
