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
 * _printf - printf function
 * @format: format
 * Return: strings with identifiers
 */
int _printf(const char *format, ...)
{	int len = 0, total_len = 0, i = 0, j;
	va_list list;
	char *buffer, *str, *(*f)(va_list);

	if (format == NULL)
		return (-1);
	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] != '%')
		{len = check_buffer_overflow(buffer, len), buffer[len++] = format[i++];
		total_len++; }
		else
		{	i++;
			if (format[i] == '\0')
			{va_end(list), free(buffer);
				return (-1); }
			if (format[i] == '%')
			{len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i], total_len++; }
			else
			{	f = get_func(format[i]);
				if (f == NULL)
				{	len = check_buffer_overflow(buffer, len), buffer[len++] = '%';
					total_len++, buffer[len++] = format[i], total_len++; } else
				{	str = f(list);
					if (str == NULL)
					{va_end(list), free(buffer);
						return (-1); }
					if (format[i] == 'c' && str[0] == '\0')
					{len = check_buffer_overflow(buffer, len);
					buffer[len++] = '\0', total_len++; }
					for (j = 0; str[j]; j++, total_len++)
					{len = check_buffer_overflow(buffer, len), buffer[len++] = str[j]; }
					free(str);	}
			}	i++;	}
	}	write_buffer(buffer, len, list);
	return (total_len); }
