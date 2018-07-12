#include <stdio.h>
#include "holberton.h"

/**
 * checkprime - Entry point
 * Description: check prime
 * @num: num to be checked
 * @m: check modula
 * Return: 1 if prime, else 0
 */
int checkprime(int num, int m)
{
	if (num % m == 0 && m != num)
		return (0);
	else if (m == num)
		return (1);
	checkprime(num, m + 1);
	return (1);
}

/**
 * is_prime_number - Entry point
 * Description: check number is prime or nut
 * @n: number will be checked
 *
 * Return: 1 if prime, otherwise 0
 */
int is_prime_number(int n)
{
	int checkprime(int num, int m);
	int m = 2;

	if (n <= 0)
		return (0);
	else if (n == 1)
		return (0);
	else if (n == 2)
		return (1);
	if (checkprime(n, m))
		return (1);
	return (0);
}
