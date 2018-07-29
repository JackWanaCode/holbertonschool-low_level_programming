#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - Entry point
 * Description: print strings follow by given format
 * @separator: pointer to const char that contain separator(s) between numbers
 * @n: numbers of arguments
 * @...: elipses
 *
 * Return: nothings
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *print_str;
	va_list arguments;

	va_start(arguments, n);
	for (i = 0; i < n; i++)
	{
		print_str = va_arg(arguments, char *);
		if (!print_str)
			print_str = "(nil)";
		if (i > 0 && separator)
			printf("%s%s", separator, print_str);
		else
			printf("%s", print_str);
	}
	va_end(arguments);
	printf("\n");
}
