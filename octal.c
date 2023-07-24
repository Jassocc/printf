#include "main.h"

/**
 * itoOctal - change int to octal
 * @list: int to change
 * Return: string with octal
 */
char *itoOctal(va_list list)
{
	int j = 0, eights = 1;
	unsigned int i, k;
	char *s;

	k = va_arg(list, unsigned int);
	i = k;

	s = malloc(sizeof(char) * 12);
	if (s == NULL)
		return (NULL);

	while (k > 7) 
	{
		k /= 8;
		eights *= 8;
	}

	while (eights > 0)
	{
		s[j++] = (i / eights + '0');
		i %= eights;
		eights /= 8;
	}
	s[j] = '\0';

	return (s);
}
