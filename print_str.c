#include "main.h"
/**
*puut_str - fun that printstr
*@ba: points to the listofarguments
*@bCount: pointer to counter
*Return: 1 if no error , -1 otherwise
*/
int puut_str(va_list ba, int *bCount)
{
	char *str;

	str = va_arg(ba, char *);
	if (str == NULL)
		str = "(null)";

	if (_putstr(str, _strlen(str)) != -1)
		*bCount += _strlen(str);
	else
		return (-1);

	return (1);
}

/**
*prt_ch - fun that print char
*@ba: points to the list of arguments
*@bCount: pointer to counter
*Return: 1 if sucess , -1 otherwise
*/
int prt_ch(va_list ba, int *bCount)
{
	if (_putchar((unsigned char)va_arg(ba, int)) != -1)
		*bCount += 1;
	else
		return (-1);

	return (1);
}
