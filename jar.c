#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: Character string that directs the format of the output
 * Return: The number of characters printed, excluding the null byte
 */
int _printf_unsigned(const char *format, ...)
{
	va_list args;
	char buffer[20];
	int count = 0, z = 0;

	va_start(args, format);
	while (format[z])
	{
		if (format[z] == '%' && format[z + 1])
		{
			z++;
			if (format[z] == 'c')
				count += custom_putchar(va_arg(args, int));
			else if (format[z] == 's')
			{
				char *s = va_arg(args, char *);

				s = s ? s : "(null)";
				count += custom_puts(s);
			}
			else if (format[z] == 'i' || format[z] == 'd')
			{
				snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));
				count += custom_puts(buffer);
			}
			else if (format[z] == 'u')
			{
				snprintf(buffer, sizeof(buffer), "%u", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[z] == 'o')
			{
				snprintf(buffer, sizeof(buffer), "%o", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[z] == 'x')
			{
				snprintf(buffer, sizeof(buffer), "%x", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[z] == 'X')
			{
				snprintf(buffer, sizeof(buffer), "%X", va_arg(args, unsigned int));
				count += custom_puts(buffer);
			}
			else if (format[z] == '%')
				count += custom_putchar('%');
			else
			{
				count += custom_putchar('%');
				count += custom_putchar(format[z]);
			}
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
