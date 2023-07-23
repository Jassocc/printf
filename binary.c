#include "main.h"

/**
 * itob - change int binary
 * @list: int to change
 * Return: string with binary
 */
char *itob(va_list list)
{
	int j = 0, two = 1;
	int i, k;
	char *s;

	k = va_arg(list, int);
	i = k;

	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);

	if (k < 0)
	{
		s[0] = 1 + '0';
		j++;
		k *= -1;
		i *= -1;
	}

	while (k > 1)
	{
		k /= 2;
		two *= 2;
	}

	while (two > 0)
	{
		s[j++] = (i / two + '0');
		i %= two;
		two /= 2;
	}

	s[j] = '\0';

	return (s);
}
