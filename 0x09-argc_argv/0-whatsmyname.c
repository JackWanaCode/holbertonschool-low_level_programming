#include <stdio.h>
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
	(void)argc;
	printf("%s\n", *argv);
	return (0);
}
