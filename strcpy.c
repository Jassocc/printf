#include "main.h"

/**
 * _strcpy - copies info from one string
 * @dest: destination
 * @src: source
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = src[x];
	return (dest);
}
