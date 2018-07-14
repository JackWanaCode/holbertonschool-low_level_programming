#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - Entry point
 * Discription: print the name of program itself.
 * @argc: argc contains the number of arguments passed to the program.
 * @argv: array of string. each is one of the arg will be passed to program.
 *
 * Return: Always 0
*/
int main(int argc, char **argv)
{
	int i;
	int product = 1;

	if (argc == 3)
	{
		for (i = 1; i < argc; i++)
		{
			product *= atoi(argv[i]);
		}
		printf("%d\n", product);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
