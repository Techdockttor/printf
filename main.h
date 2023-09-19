#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int custom_putchar(char c);
int custom_puts(char *s);
int _printf(const char *format, ...);
<<<<<<< HEAD
int check_int(const char *format, ...);
=======
int shaprintf(char *str, const char *format, ...);
void reverseString(char *str);
void rot13Encode(char *str);
void appendToBuffer(char *buffer, const char *str, int *written, int maxLength);
>>>>>>> cdae28efc61f9fdad1098658cd60bf688ce868f5

#endif
