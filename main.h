#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int custom_putchar(char c);
int custom_puts(char *s);
int _printf(const char *format, ...);
int check_int(const char *format, ...);

#endif
