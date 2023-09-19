#include <stdarg.h>
#include "main.h"

/**
 * handle_format - Handle a single format specifier
 * @format: The format specifier
 * @args: The va_list of arguments
 * @count: Pointer to the count of characters printed
 */

void handle_format(const char *format, va_list args, int *count)
{
	char buffer[20];

	if (format == NULL)
		return;

	if (*format == 'c')
		(*count) += custom_putchar(va_arg(args, int));
	else if (*format == 's')
	{
		char *s = va_arg(args, char *);

		s = s ? s : "(null)";
		(*count) += custom_puts(s);
	}
	else if (*format == 'i' || *format == 'd')
	{
		snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));
		(*count) += custom_puts(buffer);
	}
	else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
	{
		snprintf(buffer, sizeof(buffer),
		(*format == 'u') ? "%u" :
		((*format == 'o') ? "%o" :
		((*format == 'x') ? "%x" : "%X")),
		va_arg(args, unsigned int));
		(*count) += custom_puts(buffer);
	}
	else if (*format == '%')
		(*count) += custom_putchar('%');
	else
	{
		(*count) += custom_putchar('%');
		(*count) += custom_putchar(*format);
	}
}
