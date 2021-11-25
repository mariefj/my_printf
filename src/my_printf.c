#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "my_printf.h"
#include "tools.h"

// int	print_int(va_list va, my_struct_spec_t *spec)
// {
// 	int nb = va_arg(va, int);
// 	char *str = my_itoa(nb);

// 	return (my_putstr(manage_str(str, spec)));
// }


int	is_flag(char flag)
{
	int i = 0;
	const char *array_flag = "#0- +";
	int nb_flag = my_strlen(array_flag);

	while (i < nb_flag)
	{
		if (flag == array_flag[i])
			return 1;
		i++;
	}

	return 0;
}

int	set_flags(my_struct_spec_t *spec, char flag)
{
	if (flag == '#')
		spec->prefix = 1;
	if (flag == '0')
		spec->zero = 1;
	if (flag == '-')
		spec->left_align = 1;
	if (flag == ' ')
		spec->space_before_number = 1;
	if (flag == '+')
		spec->sign = 1;

	return 1;

}

int	set_width(my_struct_spec_t *spec, char digit)
{
	spec->width = my_append_c(spec->width, digit);

	return 1;
}

int	set_precision(my_struct_spec_t *spec, char digit)
{
	spec->precision = my_append_c(spec->precision, digit);

	return 1;
}

int	is_modifier(char modifier)
{
	int i = 0;
	const char *array_modifier = "hlqjzt";
	int nb_modifier = my_strlen(array_modifier);

	while (i < nb_modifier)
	{
		if (modifier == array_modifier[i])
			return 1;

		i++;
	}

	return 0;
}

int	set_double_letters_modifier(my_struct_spec_t *spec, const char *spec_str, char modifier)
{
	if (*spec_str == modifier)
	{
		spec->modifier = my_append_c(spec->modifier, modifier);
		spec_str = spec_str + 1;
		if (*spec_str == modifier)
		{
			spec->modifier = my_append_c(spec->modifier, modifier);

			return 2;
		}

		return 1;
	}

	return 0;

}

int	set_modifier(my_struct_spec_t *spec, const char *spec_str)
{
	int i = 0;

	i = set_double_letters_modifier(spec, spec_str, 'h');
	if (i == 0)
		i = set_double_letters_modifier(spec, spec_str, 'l');
	if (i == 0)
	{
		spec->modifier = my_append_c(spec->modifier, *spec_str);

		return 1;
	}

	return i;
}

int	is_conversion(char conversion)
{
	int i = 0;
	const char *array_conversion = "diouxXcspm%bS";
	int nb_conversion = my_strlen(array_conversion);

	while (i < nb_conversion)
	{
		if (conversion == array_conversion[i])
			return 1;
		i++;
	}

	return 0;
}

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

int	print_conversion(my_struct_spec_t *spec, va_list va)
{
	my_show_spec_struct(spec);
	va++;

	return 0;
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