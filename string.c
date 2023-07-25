#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * print_s - takes as string and return
 * @str:string
 * Return: string
 */
char *print_s(va_list str)
{
	char *s, *result;
	int len, i, j;

	s = va_arg(str, char *);
	if (s == NULL)
	{ s = "(NULL)"; }

	len = _strlen(s);
	result = malloc(sizeof(char) * (len * 4) + 1);

	if (result == NULL)
		return (NULL);

	j = 0;
	for (i = 0; i < len; i++)
	{
		if (s[i] >= 32 && s[i] < 127)
		{
			result[j++] = s[i];
		} else
		{
			sprintf(result + j, "\\x%02X", (unsigned char)s[i]);
			j += 4;
		}
	}
	result[j] = '\0';

	return (result);
}
