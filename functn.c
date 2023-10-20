#include "main.h"

/**
 * print_char - Prints a char.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);

    /* Handle the char 'c' using the authorized 'write' function */
    write(1, &c, 1);

    return (1); /* 1 character printed */
}

/**
 * print_string - Prints a string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int length = 0;
    char *str = va_arg(types, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        str = "(null)";

    /* Calculate the length of the string */
    while (str[length] != '\0')
        length++;

    /* Use the authorized 'write' function to print the string */
    write(1, str, length);

    return (length); /* Number of characters printed */
}

/**
 * print_percent - Prints a percent sign.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    /* Print the percent sign using the authorized 'write' function */
    write(1, "%", 1);

    return (1); /* 1 character printed */
}

/* Implementing 'print_int' and 'print_binary' following the same pattern... */

