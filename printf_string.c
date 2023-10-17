#include "main.h"

/**
 * printf_string - outputs a string
 * @args: arguments
 * @printed: output characters
 * Return: characters
 */

int printf_string(va_list args, int printed)
{
	char *string = va_arg(args, char *);

	while (*string != '\0')
	{
		_putchar(*string);
		printed++;
		string++;
	}
	return (printed);
}
