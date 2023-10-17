#include "main.h"
/**
*_putcha -  prints a character
*@ss_ch: character we want to print on terminal
*Return: -1 if there is error, 1 otherwise
*/
int _putcha(char ss_ch)
{
        return (write(1, &ss_ch, 1)); /* 1 for write on the stander output */
}
