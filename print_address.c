#include "main.h"

/**
 * get_h_digit - convert hex to digit
 * @num: int to convert
 * Return: hex
 */
char get_h_digit(int num)
{
	if (num >= 0 && num <= 9)
		return (num + '0');
	else
		return (num - 10 + 'a');
}
/**
 * get_h_string_length - calculate length of string
 * @address: mem to convert
 * Return: string length
 */
int get_h_string_length(void *address)
{
		unsigned long int addr = (unsigned long int)address;
		int length = 0;

		while (addr != 0)
		{
			length++;
			addr >>= 4;
		}
		return ((length == 0) ? 1 : length);
}
/**
 * get_h_string - convert mem to hex string
 * @ptr: mem address to convert
 * Return: hex string
 */
char *get_h_string(void *ptr)
{
	unsigned long int address = (unsigned long int)ptr;
	int size = get_h_string_length(ptr) + 3;
	char *result = malloc(size);
	int digit, i;

	if (result == NULL)
	return (NULL);

	result[0] = '0';
	result[1] = 'x';
	result[size - 1] = '\0';

	for (i = size - 2; i > 1; i--)
	{
		digit = address & 0xF;
		result[i] = get_h_digit(digit);
		address >>= 4;
	}
	return (result);
}
/**
 * print_address - prints address of pointer
 * @list: va_list containing pointer
 * Return: address
 */
char *print_address(va_list list)
{
	void *ptr = va_arg(list, void *);

	return (get_h_string(ptr));
}
