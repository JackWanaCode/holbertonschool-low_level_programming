#include <stdio.h>

/**
 * turtle_first - the function that excuted before main
 *
 * Return: Always 0.
 */
void turtle_first(void) __attribute__ ((constructor));
void turtle_first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
