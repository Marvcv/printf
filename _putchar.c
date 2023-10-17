#include "main.c"

/**
 * _putchar -outputs a character
 * @character: specify the character to output
 * Return: 1, if successful
 */

int _putchar(char character)
{
	return (write(1, &character, 1));
}
