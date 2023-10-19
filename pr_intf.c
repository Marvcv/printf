#include "main.h"
/**
 * _printf - A simplified implementation of printf.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */



int _printf(const char *format, ...)
{
    int cha_pr = 0;
    va_list arglist;

    if (format == NULL)
        return (-1);

    va_start(arglist, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            cha_pr++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == '%')
            {
                write(1, format, 1);
                cha_pr++;
            }
            else if (*format == 'c')
            {
                char c = va_arg(arglist, int);

                write(1, &c, 1);
                cha_pr++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(arglist, char*);
                int str_len = 0;

                while (str[str_len] != '\0')
                    str_len++;

                write(1, str, str_len);
                cha_pr += str_len;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(arglist, int);
                char num_str[12];

                int num_len = snprintf(num_str, sizeof(num_str), "%d", num);
                write(1, num_str, num_len);
                cha_pr += num_len;
            }
            else if (*format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(arglist, unsigned int);
                char hex_str[9];

                int hex_len = snprintf(hex_str, sizeof(hex_str), "%x", num);
                write(1, hex_str, hex_len);
                cha_pr += hex_len;
            }
            else if (*format == 'u')
            {
                unsigned int num = va_arg(arglist, unsigned int);
                char unsigned_str[12];
                int unsigned_len = snprintf(unsigned_str, sizeof(unsigned_str), "%u", num);
                write(1, unsigned_str, unsigned_len);
                cha_pr += unsigned_len;
            }
            else if (*format == 'o')
            {
                unsigned int num = va_arg(arglist, unsigned int);
                char octal_str[12];
                int octal_len = snprintf(octal_str, sizeof(octal_str), "%o", num);
                write(1, octal_str, octal_len);
                cha_pr += octal_len;
            }
            else if (*format == 'p')
            {
                void *ptr = va_arg(arglist, void *);
                char ptr_str[16];
                int ptr_len = snprintf(ptr_str, sizeof(ptr_str), "%p", ptr);
                write(1, ptr_str, ptr_len);
                cha_pr += ptr_len;
            }
            else
            {
                write(1, format - 1, 2);
                cha_pr += 2;
            }
        }
        format++;
    }

    va_end(arglist);

    return cha_pr;
}
