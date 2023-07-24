#ifndef main_h
#define main_h

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char* (*get_func(char i))(va_list);
char *create_buffer(void);
void write_buffer(char *buffer, int len, va_list list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

int h_spec(va_list list, char specifier, char *buffer, int len, int *total_len);
int _printf(const char *format, ...);
char *print_s(va_list list);
char *print_c(va_list list);
char *print_d(va_list list);
char *itob(va_list list);
char *rot13(va_list list);
char *rev_string(va_list list);
char *itoOctal(va_list list);

/**
 * struct types - struct
 * @id: identifier of type print
 * @func: ptr to funcs that according to indentifier
 */
typedef struct types
{
	char id;
	char* (*func)(va_list);
} print;

#endif
