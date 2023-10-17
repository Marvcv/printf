#include "main.h"

/**
 * printf_string - outputs a string
 * @args: arguments
 * Return: characters
 */

int printf_string(va_list args)
{
	char *string;
	int i;
	int length;

	string = va_arg(args, char *);

	while (*string != '\0')
	{
		string = "(null)"
		length = _strlen(string);
		for (i = 0; i < length; i++)
			_putchar(string[i]);
		return (length);
	}
	else
	{
		length = _strlen(string);
		for (i = 0; i < length; i++)
			_putchar(string[i]);
		return (length);
	}
}
