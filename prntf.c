#include "main.h"

int _printf(const char *format, ...);

int main(void)
{
    char c = 'A';
    char *str = "Hello, world!";
    int num = 42;

    _printf("Character: %c\n", c);
    _printf("String: %s\n", str);
    _printf("Number: %d\n", num);

    return (0);
}

int _printf(const char *format, ...)
{
    int index, printed_chars = 0;
    va_list args;

    if (format == NULL)
        return -1;

    va_start(args, format);

    for (index = 0; format && format[index] != '\0'; index++)
    {
        if (format[index] != '%')
        {
            char character_buffer[1];
            character_buffer[0] = format[index];
            write(1, character_buffer, 1);
            printed_chars++;
        }
        else
        {
            int value = va_arg(args, int);
            if (format[index + 1] == 'c')
            {
                char character_buffer[1];
                character_buffer[0] = value;
                write(1, character_buffer, 1);
                printed_chars++;
            }
            else if (format[index + 1] == 's')
            {
                char *str = va_arg(args, char *);
                int length = 0;
                while (str[length] != '\0')
                    length++;
                write(1, str, length);
                printed_chars += length;
            }
            else if (format[index + 1] == 'd')
            {
                // Handle integer printing here
                // Use va_arg to get the integer and write to the output
            }
            index++;
        }
    }

    va_end(args);

    return printed_chars;
}

