#include "main.h"
/**
*_putstring - fun thatoutput str
*@strg: pointer to the str we want to print
*@leng: lenth of the strg
*Return: -1 if error, 1 otherwise
*/
int _putstr(char *strg, int leng)
{
	return (write(1, strg, leng));
}
