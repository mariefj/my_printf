#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "my.h"
#include "my_printf.h"
#include "my_struct_spec.h"
#include "is_flag.h"
#include "set_flags.h"


int	print_arg(va_list va, const char **spec_str)
{
	int nb_char_printed = 0;
	my_struct_spec_t *spec = spec_init();

	while (is_flag(**spec_str))
	{
		*spec_str += set_flags(spec, **spec_str);
	}
	while (is_digit(**spec_str))
	{
		*spec_str += set_width(spec, **spec_str);
	}
	if (**spec_str == '.')
	{
		*spec_str = *spec_str + 1;
		while (is_digit(**spec_str))
		{
			*spec_str += set_precision(spec, **spec_str);
		}
	}
	if (is_modifier(**spec_str))
	{
		*spec_str += set_modifier(spec, *spec_str);
	}
	if (is_conversion(**spec_str))
		spec->conversion = **spec_str;
	nb_char_printed += print_conversion(spec, va);

	return (nb_char_printed);
}

int 	do_conversion(char conversion_flag, va_list va)
{
	my_struct_func_ptr_conversion_t	conversions[CONVERSION_NB];
	int				i = 0;

	set_up_struct_conversion(conversions);
	set_up_struct_conversion_base(conversions);
	while (i != CONVERSION_NB)
	{
		if (conversions[i].conversion_tag == conversion_flag)
			return (conversions[i].conversion_func(va));
		i++;
	}

	return (0);
}

int	print_conversion(my_struct_spec_t *spec, va_list va)
{
	if (spec->conversion == '%')
	{
		return (my_putchar('%'));
	}
	if (spec->conversion == 'm')
	{
		return (my_putstr(strerror(errno)));
	}

	return (do_conversion(spec->conversion, va));
}

int	my_printf(const char *format, ...)
{
	int nb_char_printed = 0;
	va_list va;

	va_start(va, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = format + 1;
			nb_char_printed += print_arg(va, &format);
		}
		else
			nb_char_printed += my_putchar(*format);
		format = format + 1;
	}
	va_end(va);

	return (nb_char_printed);
}