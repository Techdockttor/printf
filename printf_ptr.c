#include "main.h"

/**
 * print_ptr - prints pointer address
 * @format: formatted string to check
 * Return: number of characters printed
 */

int print_ptr(const char *format, ...)
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

			if (format[i] == 'p')
			{
				void *ptr = va_arg(args, void *);

				snprintf(buffer, sizeof(buffer), "%p", ptr);
				count += custom_puts(buffer);
			}
		}
		else
		{
			count += custom_putchar(format[i]);
		}
		i++;
	}

	va_end(args);

	return (count);
}
