#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "my_printf.h"
#include "tools.h"

int	print_int(va_list va, my_struct_spec_t spec)
{
	int nb = va_arg(va, int);
	char *str = my_itoa(nb);

	return (my_putstr(manage_str(str, spec)));
}

int	print_arg(va_list va, const char *spec_str, int *i)
{
	int nb_char_printed = 0;
	my_struct_spec_t spec = spec_init();

	while (is_flag(spec_str[i]))
	{
		set_flags(spec, spec_str[i], &i);
	}
	while (is_digit(spec_str[i]))
	{
		set_width(spec, spec_str[i], &i);
	}
	if (spec_str[i] = '.')
	{
		while (is_digit(spec_str[i]))
		{
			set_precision(spec, spec_str[i], &i);
		}
	}
	while (is_modifier(spec_str[i]))
	{
		set_modifier(spec, spec_str[i], &i);
	}
	if (is_conversion(spec_str[i]))
	{
		spec->conversion = spec_str[i];
		i++;
	}
	nb_char_printed += print_conversion(spec, va);

	return (nb_char_printed);
}

int	my_printf(const char *format, ...)
{
	int i = 0;
	int nb_char_printed = 0;
	va_list va;

	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			nb_char_printed += print_arg(va, &format[i], &i);
		else
			nb_char_printed += my_putchar(format[i]);
		i++;
	}
	va_end(va);

	return (nb_char_printed);
}