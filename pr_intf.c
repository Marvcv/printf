#include "main.h"

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    int printed = 0;  // To keep track of the number of characters printed

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            printed++;
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
                printed++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    printed++;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                printed++;
            }
        }

        format++;
    }

    va_end(args);

    return printed;
}

int main(void)
{
    int len;

    len = _printf("Character: %c\n", 'A');
    _printf("Length: %d\n", len);

    len = _printf("String: %s\n", "Hello, World!");
    _printf("Length: %d\n", len);

    len = _printf("Percent sign: %%\n");
    _printf("Length: %d\n", len);

    return (0);
}
