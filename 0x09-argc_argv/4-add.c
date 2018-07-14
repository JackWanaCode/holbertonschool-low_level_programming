#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
	int sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (*argv[i] >= '0' && *argv[i] <= '9')
		{
			sum += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%i\n", sum);
	return (0);
}
