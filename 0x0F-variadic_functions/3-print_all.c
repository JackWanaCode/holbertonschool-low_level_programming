#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Entry point
 * Description: print all type of arguments
 * @format: abbreviation of type
 * @...: elipses
 *
 * Return: nothings
 */
void print_all(const char * const format, ...)
{
	unsigned int j = 0;
	va_list arguments;

	va_start(arguments, format);
	while (format[j] != '\0')
	{
		if (j > 0 && (format[j] == 'c' || format[j] == 'i' || \
format[j] == 'f' || format[j] == 's'))
			printf(", ");
		switch (format[j])
		{
		case 'i':
			printf("%i", va_arg(arguments, int));
			j++;
			break;
		case 'f':
			printf("%f", va_arg(arguments, double));
			j++;
			break;
		case 'c':
			printf("%c", va_arg(arguments, int));
			j++;
			break;
		case 's':
			printf("%s", va_arg(arguments, char *));
			j++;
			break;
		default:
			j++;
			break;
		}
	}
	printf("\n");
	va_end(arguments);
}
