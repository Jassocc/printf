#include "main.h"

/**
 * itob - change int binary
 * @list: int to change
 * @format: format
 * Return: string with binary
 */
char *itob(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int num2;
	int i, contame = 0;
	char *numbin;

	if (num == 0)
	{
		numbin = malloc(2);
		if (numbin == NULL)
			return (NULL);
		numbin[0] = '0';
		numbin[1] = '\0';
		return (numbin);
	}
	for (num2 = num; num2 != 0; contame++)
	{
		num2 = num2 / 2;
	}
	numbin = malloc(contame + 1);
	if (!numbin)
		return (NULL);
	for (i = contame - 1; i >= 0; i--)
	{
		numbin[i] = num % 2 +'0';
		num = num / 2;
	}
	numbin[contame] = '\0';
	return (numbin);
}
