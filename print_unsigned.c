#include "main.h"

/**
 * print_unsigned - print unsigned int
 * @list: va_list containing int
 * Return: string of int
 */

char *print_unsigned(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int copy = num, divisor;
	int count = 0, j, i;
	char *result;

	if (num == 0)
	{
		result = malloc(2);
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	count = count_unsigned_digits(num);
	result = malloc(count + 1);
	if (result == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		divisor = 1;
		for (j = 1; j < count - i; j++)
			divisor *= 10;
		result[i] = '0' + (copy / divisor);
		copy %= divisor;
	}
	result[count] = '\0';
	return (result);
}

/**
 * count_unsigned_digits - counts digits of int
 * @number: input of int
 * Return: digit
 */
int count_unsigned_digits(unsigned int number)
{
	int count = 0;

	if (number == 0)
		return (1);

	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
