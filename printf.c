#include "main.h"

/**
 * _printf - inbuilt
 * @format: the specifier
 * Return: the string
 */

int _printf(const char *format, ...)
{
	int printed = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '\0')
		{
			format++;
			printed = selector(format, args, printed);
			format++
		}
		else
		{
			_putchar(*format);
			printed++;
			format++;
		}
	}
	va_end(args);
	return (printed);
}
