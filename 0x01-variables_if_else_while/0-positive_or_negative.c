#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * maint - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
		printf("%i is positive\n", n);
	else if (n < 0)
		printf("%i is negativ\n", n);
	else
		printf("%i is zero", n);
	return (0);
}
