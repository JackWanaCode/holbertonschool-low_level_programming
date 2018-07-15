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
	(void)argv;
	int count = 0;
	int count_in = 0;
	int price;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else if (atoi(argv[1]) > 0)
	{
		price = atoi(argv[1]);
		while (price > 0)
		{
			if (price >= 25)
			{
				count_in = price / 25;
				count += count_in;
				price = price - count_in * 25;
			}
			else if (price >= 10)
			{
				count_in = price / 10;
				count += count_in;
				price = price - count_in * 10;
			}
			else if (price >= 5)
			{
				count_in = price / 5;
				count += count_in;
				price = price - count_in * 5;
			}
			else if (price >= 2)
			{
				count_in = price / 2;
				count += count_in;
				price = price - count_in * 2;
			}
			else
			{
				count_in = price;
				count += count_in;
				price = price - count_in * 2;
			}
		}
	}
	else
		price = 0;
	printf("%i\n", count);
	return (0);
}
