#include <stdio.h>
#include "holberton.h"

/**
 * set_string - Entry point
 * Description: change a pointer to poiter to another pointer
 * @s: pointer to pointer
 * @to: pointer
 *
 * Return: pointer to the memory area s.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
