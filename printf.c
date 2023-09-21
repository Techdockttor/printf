#include "main.h"
#include <stdarg.h>
#include <string.h>

int yhandle_format(const char *format, va_list args, int *count, char *buffer);

/**
 * _printf - produces output according to a format
 * @format: Character string that directs the format of the output
 * Return: The number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int z = 0;
	int count = 0;
	char buffer[20];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (format[z])
	{
		if (format[z] == '%')
		{
			z++;
			z += yhandle_format(format + z, args, &count, buffer);
		}
		else
		{
			count += custom_putchar(format[z]);
			z++;
		}
	}

	va_end(args);
	return (count);
}

/**
 * yhandle_format - Handle a single format specifier
 * @format: The format specifier
 * @args: The va_list of arguments
 * @count: Pointer to the count of characters printed
 * @buffer: Buffer for temporary storage
 * Return: Number of characters processed
 */
int yhandle_format(const char *format, va_list args, int *count, char *buffer)
{
	if (format[0] == 'c')
	{
		*count += custom_putchar(va_arg(args, int));
		return (0);
	}
	else if (format[0] == 's')
	{
		char *s = va_arg(args, char *);

		s = s ? s : "(null)";
		*count += custom_puts(s);
		return (0);
	}
	else if (format[0] == 'i' || format[0] == 'd')
	{
		snprintf(buffer, 20, "%d", va_arg(args, int));
		*count += custom_puts(buffer);
		return (0);
	}
	else if (format[0] == '%')
	{
		*count += custom_putchar('%');
		return (0);
	}
	else
	{
		*count += custom_putchar('%');
		*count += custom_putchar(format[0]);
		return (0);
	}
}

