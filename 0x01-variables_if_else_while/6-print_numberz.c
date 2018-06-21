#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;
	int arr[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	while (i < 11)
	{
		putchar(arr[i]);
		i++;
	}
	putchar('\n');
	return (0);
}
