#include "main.h"

/**
 * printhex - prints a hex
 * @list: va_list containing hex
 * Return: hex characters
 */
char *printhex(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int num2;
	int i, copy, contame = 0;
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
	numhex = malloc(contame + 1);
	if (numhex == NULL)
		return (NULL);
	numhex[contame] = '\0';

	for (i = contame - 1; num != 0; i--)
	{
		copy = num % 16;
		if (copy < 10)
			numhex[i] = copy + '0';
		else
			numhex[i] = copy - 10 + 'a';
		num = num / 16;
	}
	return (numhex);
}

/**
 * printHEX - prints hex
 * @list: va_list conatining hex
 * Return: hex characters
 */
char *printHEX(va_list list)
{
	unsigned int NUM = va_arg(list, unsigned int);
	unsigned int NUM2;
	int I, COPY, CONTAME = 0;
	char *NUMHEX;

	if (NUM == 0)
	{
		NUMHEX = malloc(2);
		if (NUMHEX == NULL)
			return (NULL);
		NUMHEX[0] = '0';
		NUMHEX[1] = '\0';
		return (NUMHEX);
	}
	for (NUM2 = NUM; NUM2 != 0; CONTAME++)
	{
		NUM2 = NUM2 / 16;
	}
	NUMHEX = malloc(CONTAME + 1);
	if (NUMHEX == NULL)
		return (NULL);
	NUMHEX[CONTAME] = '\0';
	for (I = CONTAME - 1; NUM != 0; I--)
	{
		COPY = NUM % 16;
		if (COPY < 10)
			NUMHEX[I] = COPY + '0';
		else
			NUMHEX[I] = COPY - 10 + 'A';
		NUM = NUM / 16;
	}
	return (NUMHEX);
}
