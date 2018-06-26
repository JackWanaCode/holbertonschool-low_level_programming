#include "holberton.h"

/**
 * main - Entry point
 * Description: Use function _putchar to print Holberton on the screen
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
