#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 * Discription: print the name of program itself.
 *
 * Return: Always 0
*/
int main(int argc, char **argv)
{
	if (argc >= 1)
		printf("%s\n", *argv);
	return (0);
}
