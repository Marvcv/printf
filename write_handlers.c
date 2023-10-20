#include "main.h"

/**
 * write_char - Writes a character to stdout
 * @c: The character to write
 * Return: Number of printed characters (always 1)
 */
int write_char(char c)
{
	return write(1, &c, 1);
}

/**
 * write_str - Writes a string to stdout
 * @str: The string to write
 * Return: Number of printed characters
 */
int write_str(char *str)
{
	int len = str_len(str);

	return write(1, str, len);
}

/**
 * write_percent - Writes a percent character to stdout
 * Return: Number of printed characters (always 1)
 */
int write_percent(void)
{
	return write(1, "%", 1);
}

/**
 * write_int - Writes an integer to stdout
 * @n: The integer to write
 * Return: Number of printed characters
 */
int write_int(int n)
{
	char buffer[BUFF_SIZE];
	int len, neg;

	neg = (n < 0) ? 1 : 0;
	if (n == 0)
		return (write_char('0'));
	if (n == INT_MIN)
	{
		str_cpy(buffer, "-2147483648");
		return (write_str(buffer));
	}
	n = (neg == 1) ? -n : n;
	len = 0;
	while (n > 0)
	{
		buffer[len] = (n % 10) + '0';
		n /= 10;
		len++;
	}
	if (neg)
	{
		buffer[len] = '-';
		len++;
	}
	buffer[len] = '\0';
	str_rev(buffer);
	return (write_str(buffer));
}

/**
 * write_unsigned - Writes an unsigned integer to stdout
 * @n: The unsigned integer to write
 * Return: Number of printed characters
 */
int write_unsigned(unsigned int n)
{
	char buffer[BUFF_SIZE];
	int len;

	if (n == 0)
		return (write_char('0'));
	len = 0;
	while (n > 0)
	{
		buffer[len] = (n % 10) + '0';
		n /= 10;
		len++;
	}
	buffer[len] = '\0';
	str_rev(buffer);
	return (write_str(buffer));
}

/**
 * write_hex - Writes a hexadecimal number to stdout
 * @n: The hexadecimal number to write
 * @is_upper: Uppercase or lowercase letters
 * Return: Number of printed characters
 */
int write_hex(unsigned int n, int is_upper)
{
	char buffer[BUFF_SIZE];
	int len, rem;

	if (n == 0)
		return (write_char('0'));
	len = 0;
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
			buffer[len] = rem + '0';
		else
			buffer[len] = is_upper ? (rem - 10) + 'A' : (rem - 10) + 'a';
		n /= 16;
		len++;
	}
	buffer[len] = '\0';
	str_rev(buffer);
	return (write_str(buffer));
}

