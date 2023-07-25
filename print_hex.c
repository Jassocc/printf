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

	numhex == malloc(contame + 1);
	if (numhex == NULL)
		return (NULL);

	for (i = 0; num != 0; i++)
	{
		copy = num % 16;
		if (copy < 10)
			numhex[i] = copy + '0';
		else
			numhex[i] = copy - 10 + 'a';
		num = num / 16;
	}
	for (i2 = i - 1; i2 >= 0; i2--)
		numhex[i2] = numhex[i2];
	numhex[contame] = '\0';
	return (numhex);
}

/**
 * printHEX - prints hexadecimal
 * @list :va_list containing hex
 * Return: buffer containing hex
 */
char *printHEX(va_list list)
{
	unsigned int NUM = va_arg(list, unsigned int);
	unsigned int NUM2;
	int I, I2, COPY, CONTAME = 0;
	char *NUMHEX;

}
