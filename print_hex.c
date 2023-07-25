#include "main.h"

/**
 * printhex - print hexadecimal
 * @list: va_list that contains hex
 * Return: digits
 */
int printhex(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int num2;
	int i, i2, copy, contame = 0;
	char *numhex;

	if (num == 0)
	{
		numhex = malloc(2);
		if (numhex == NULL)
			return (NULL);
		numhex[0] = '0';
		numhex[1] = '\0';
		return (numhex);
	}
	for (num2 = num; num2 != 0; contame++)
	{
		num2 = num2 / 16;
	}

	numhex == malloc(contame + 1)
