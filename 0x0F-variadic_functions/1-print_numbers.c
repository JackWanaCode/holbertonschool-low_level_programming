#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - Entry point
 * Description: print number follow by given format
 * separator: pointer to const char that contain separator(s) between numbers
 * @n: numbers of arguments
 * @...: elipses
 *
 * Return: nothings
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	int print_num;
	va_list arguments;

	va_start(arguments, n);
	for (i = 0; i < n; i++)
	{
		print_num = va_arg(arguments, int);
		if (i > 0)
			printf("%s%i", separator, print_num);
		else
			printf("%i", print_num);
	}
	va_end(arguments);
	printf("\n");
}
