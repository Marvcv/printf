#include "main.h"

int _printf(const char *format, ...);
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
		}

		format++;
	}

	va_end(arglist);

	return (cha_pr);
