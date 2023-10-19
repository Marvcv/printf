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
			else if (*format == 'd')
              {
                  int num = va_arg(arglist, int);
                  char num_str[12];
 
                  int num_len = snprintf(num_str, sizeof(num_str), "%d", num);
                  write(1, num_str, num_len);
                  cha_pr += num_len;
              }
              else if (*format == 'x')
              
                  unsigned int num = va_arg(arglist, unsigned int);
                  char hex_str[9];
 
                  int hex_len = snprintf(hex_str, sizeof(hex_str), "%x", num);
                  write(1, hex_str, hex_len);
                  cha_pr += hex_len;
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

	return (cha_pr);
}
