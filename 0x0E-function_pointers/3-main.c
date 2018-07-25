#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point
 * Description: print the result
 * @argc: number of argument
 * @argv: array of strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	int n1, n2;
	char c = argv[2][0];
	char c1 = argv[2][1];

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (c1 != '\0')
	{
                printf("Error\n");
                exit(99);
        }
	if (c != '+' && c != '-' && c != '*' && c != '/' && c != '%')
	{
		printf("Error\n");
		exit(99);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	printf("%i\n", (*get_op_func(argv[2]))(n1, n2));
	return (0);
}
