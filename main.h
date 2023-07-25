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
int count_unsigned_digits(unsigned int number);
char get_h_digit(int num);
char *get_h_string(void *ptr);
int get_h_string_length(void *address);

int _printf(const char *format, ...);
char *print_s(va_list list);
char *print_c(va_list list);
char *print_d(va_list list);
char *itob(va_list list);
char *rot13(va_list list);
char *rev_string(va_list list);
char *itoOctal(va_list list);
char *print_unsigned(va_list list);
char *printhex(va_list list);
char *printHEX(va_list list);
char *print_address(va_list list);

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
