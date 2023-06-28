#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct flags - flags
 * @plus: +
 * @space: ' '
 * @hash: #
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_f;

/**
 * struct print_handler - choose right func
 * @a: char
 * @f: pointer
 */
typedef struct print_handler
{
	char a;
	int (*f)(va_list args, flags_f *f);
} handler;

int print_perc(va_list args, flags_f *f);
int print_char(va_list args, flags_f *f);
int print_string(va_list args, flags_f *f);
int print_int(va_list args, flags_f *f);
int print_unsign(va_list args, flags_f *f);
int print_oct(va_list args, flags_f *f);
int print_binary(va_list args, flags_f *f);
int print_hex(va_list args, flags_f *f);
int print_HEXA(va_list args, flags_f *f);
int print_rev(va_list args, flags_f *f);
int print_rot13(va_list args, flags_f *f);
int print_specStr(va_list args, flags_f *f);
int print_address(va_list args, flags_f *f);
int get_flag(char c, flags_f *f);
int (*get_print(char c))(va_list args, flags_f *);
void print_num(int n);
int counting(int i);
char *convert(unsigned long int n, int b, int lc);
int _printf(const char *format, ...);
int _puts(char *s);
int _putchar(char c);

#endif
