#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int arr[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (i = 0; i < 11; i++)
		putchar(arr[i] + '0');
	putchar('\n');
	return (0);
}
