#include "main.h"

/**
 * printf_percent - prints the '%'
 * @args: variable argument list
 * @printed: printed characters
 * Return: printed xters +1
 */

int printf_percent(va_list args, int printed)
{
	_putchar('%');
	return (printed + 1);
}
