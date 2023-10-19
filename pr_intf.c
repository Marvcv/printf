#include "main.h"
/**
 * _printf - A simplified implementation of printf.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list args;
    va_start(args, format);

    int char_pr = 0;
 
    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            char_pr++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                char_pr++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    char_pr++;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                char_pr++;
            }
        }

        format++;
    }

    va_end(args);

    return char_pr;
}

