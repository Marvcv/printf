#include "main.c"

/**
 * printf_char - outputs a character
 * @args: arguments
 * @printed: the output
 * Return: output characters
 */

int printf_char(va_list args, int printed)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (printed + 1);
}
