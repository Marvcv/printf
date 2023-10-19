#include "main.h"
/**
 * _printf - A simplified implementation of printf.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
    int char_count = 0;
    va_list arglist;

    if (format == NULL)
        return (-1);

    va_start(arglist, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            char_count++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                char c = va_arg(arglist, int);
                putchar(c);
                char_count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(arglist, char *);
                int str_len = 0;

                while (str[str_len] != '\0')
                    str_len++;

                fputs(str, stdout);
                char_count += str_len;
            }
            else if (*format == '%')
            {
                putchar('%');
                char_count++;
            }
            else
            {
                putchar('%');
                putchar(*format);
                char_count += 2;
            }
        }
        format++;
    }
