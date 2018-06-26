#include "holberton.h"
int _putchar(char c);

/**
 * main - write a program that print Holberton on the screen
 * use function _putchar
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char holberton[] = "Holberton";
	int i = 0;

	while (holberton[i] != '\0')
	{
		_putchar(holberton[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}
