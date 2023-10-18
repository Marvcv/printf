#include "main.h"

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    int cha_pr = 0;
    va_list arglist;
    va_start(arglist, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c' || *format == 's')
            {
                if (*format == 'c')
                    write(1, &va_arg(arglist, int), 1);
                else
                {
                    char *str = va_arg(arglist, char*);
                    int str_len = 0;
                    while (str[str_len] != '\0')
                        str_len++;
                    write(1, str, str_len);
                    cha_pr += str_len;
                }
            }
            else if (*format == '%')
                write(1, format, 1);
            cha_pr += (*format == 'c' || *format == 's') ? 1 : 0;
        }
        else
        {
            write(1, format, 1);
            cha_pr++;
        }
        format++;
    }

    va_end(arglist);
    return cha_pr;
}

