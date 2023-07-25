#include "main.h"
#include <string.h>

/**
 * print_s - takes as string and return
 * @str:string
 * Return: string
 */
char *print_s(va_list str)
{
	char *s, *p;
	int len;

	s = va_arg(str, char *);
	if (s == NULL)
	{
		s = "(null)";
	}

	len = _strlen(s);

	p = malloc(sizeof(char) * len + 1);

	if (p == NULL)
	{
		return (NULL);
	}
	return (_strcpy(p, s));
}
