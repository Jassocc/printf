#include "main.h"

/**
 * print_S - prints non printable chars
 * @list: va_list
 * Return: string
 */
char *print_S(va_list list)
{
	char *str = va_arg(list, char *);
	char *conv_str = malloc(sizeof(char) * (_strlen(str) * 4 + 1));
	int i, j;

	if (conv_str == NULL)
		return (NULL);
	for (i = 0, j = 0; str[i] != '\0'; i++, j++)
	{
		if (str[i] < ' ' || str[i] >= 127)
		{
			conv_str[j++] = '\\';
			conv_str[j++] = 'x';
			conv_str[j++] = (str[i] / 16) < 10 ? (str[i] / 16) + '0' :
				(str[i] / 16) - 10 + 'A';
			conv_str[j] = (str[i] % 16) < 10 ? (str[i] % 16) + '0' :
				(str[i] % 16) - 10 + 'A';
		}
		else
		{
			conv_str[j] = str[i];
		}
	}
	conv_str[j] = '\0';

	return (conv_str);
}
