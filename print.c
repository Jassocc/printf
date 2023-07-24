#include "main.h"

/**
 * check_buffer_overflow - if writing over buffer space,
 * print everything then revert length back to 0
 * to write at buffer start
 * @buffer: buffer holding string to print
 * @len: position
 * Return: Length position
 */

int check_buffer_overflow(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}

/**
 * h_spec - process and handle a single specifier
 * @list: va_list
 * @specifier: the specifier char
 * @buffer: buffer holding string to print
 * @len: current position in buffer
 * @total_len: length of string
 * Return: updated length position in string
 */
int h_spec(va_list list, char specifier, char *buffer, int len, int *total_len)
{
	char *(*f)(va_list);
	char *str;
	int j = 0;

	f = get_func(specifier);
	if (f == NULL)
	{
		buffer[len++] = '%';
		buffer[len++] = specifier;
		*total_len += 2;
	}
	else
	{
		str = f(list);
		if (str == NULL)
			return (-1);
		if (specifier == 'c' && str[0] == '\0')
		{
			buffer[len++] = '\0';
			(*total_len)++;
		}
		else
		{
			while (str[j] != '\0')
			{
				buffer[len++] = str[j];
				(*total_len)++;
				j++;
			}
		}
		free(str);
	}
	return (len);
}
/**
 * _printf - printf function
 * @format: format
 * Return: strings with identifiers
 */
int _printf(const char *format, ...)
{
	int len = 0, total_len = 0, i = 0;
	va_list list;
	char *buffer;

	if (format == NULL)
		return (-1);
	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i++];
			total_len++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == '%')
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = '%';
				total_len++;
			}
			else
			{
				len = h_spec(list, format[i], buffer, len, &total_len);
			}
			i++;
		}
	}
	write_buffer(buffer, len, list);
	return (total_len);
}
