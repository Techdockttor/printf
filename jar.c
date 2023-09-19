#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * custom_putchar - Write a character to the standard output
 * @c: The character to be written
 * Return: 1 on success, -1 on error
 */
int custom_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * custom_puts - Write a string to the standard output
 * @s: The string to be written
 * Return: The number of characters written
 */
int custom_puts(char *s)
{
	int custom_puts(char *s);
	int count = 0;

	if (!s)
	return (custom_puts("(null)"));

	while (*s)
	{
		if (custom_putchar(*s) == -1)
			return (-1);
		count++;
		s++;
	}
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: Character string that directs the format of the output
 * Return: The number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[20];
	int count = 0, i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				count += custom_putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				s = s ? s : "(null)";
				count += custom_puts(s);
			}
			else if (format[i] == 'i' || format[i] == 'd')
			{
				snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));
				count += custom_puts(buffer);
			}
			else if (format[i] == 'u')
			{
				snprintf(buffer, sizeof(buffer), "%u", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[i] == 'o')
			{
				snprintf(buffer, sizeof(buffer), "%o", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[i] == 'x')
			{
				snprintf(buffer, sizeof(buffer), "%x", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[i] == 'X')
			{
				snprintf(buffer, sizeof(buffer), "%X", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[i] == '%')
				count += custom_putchar('%');
			else
			{
				count += custom_putchar('%');
				count += custom_putchar(format[i]);
			}
		}
		else
		{
			count += custom_putchar(format[i]);
		i++;
		}
	}

	va_end(args);
	return (count);
}
