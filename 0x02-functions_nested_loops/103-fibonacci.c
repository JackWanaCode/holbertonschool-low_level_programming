#include <stdio.h>

/**
 * main - Entry point
 * Description: print sum of even fib nums. fib nums < 40000000
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int first = 1;
	int second = 1;
	int fibnum = 2;
	int result = 0;

	while (fibnum <= 4000000)
	{
		if (fibnum % 2 == 0)
			result += fibnum;
		first = second;
		second = fibnum;
		fibnum = first + second;
	}
	printf("%i\n", result);
	return (0);
}
