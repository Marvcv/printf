#include "main.h"

/**
 * printf_charac - prints a binary number
 * @val: the arguements to use
 * @output: the outputed characters
 * Return: printed charcaters
 */

int printf_charac(va_list val, int output)
{
	int character = va_arg(val, int);

	_putchar(character);
	return (output + 1);
}
