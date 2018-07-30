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
	int chk = 0;
	va_list arguments;
	char c;
	char *s;
	while (format == NULL)
	{
		printf("Error\n");
		return;
	}
	va_start(arguments, format);
	while (format[j] != '\0' && format)
	{
		c = format[j];
		if (chk != 0 && (c == 'c' || c == 'i' || c == 'f' || c == 's'))
			printf(", ");
		switch (c)
		{
		case 'i':
			printf("%i", va_arg(arguments, int));
			j++;
			chk = 1;
			break;
		case 'f':
			printf("%f", va_arg(arguments, double));
			j++;
			chk = 1;
			break;
		case 'c':
			printf("%c", va_arg(arguments, int));
			j++;
			chk = 1;
			break;
		case 's':
			s = va_arg(arguments, char *);
			if (s == NULL)
				s = "(nil)";
			printf("%s", s);
			j++;
			chk = 1;
			break;
		default:
			j++;
			break;
		}
	}
	printf("\n");
	va_end(arguments);
}
