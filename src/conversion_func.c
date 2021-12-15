#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#include "my.h"
#include "conversion_func.h"


// int	my_get_nb_char(my_struct_spec_t *spec, int nb_va_arg)
// {
// 	int nb_char = 0;

 	// if (nb_va_arg > 0 && (spec->sign || spec->space_before_number))
// 	{
// 		nb_char++;
// 	}

// }

int	my_put_nbr_va(va_list va, my_struct_spec_t *spec)
{
	int nb_char = 0;
	int nb_va_arg = va_arg(va, int);

	if (nb_va_arg > 0 && spec->sign)
	{
		nb_char += my_putchar('+');
	}
	else if (nb_va_arg > 0 && spec->space_before_number)
	{
		nb_char += my_putchar(' ');
	}
	nb_char += my_put_nbr(nb_va_arg);

	return (nb_char);
}

int	my_putstr_va(va_list va, my_struct_spec_t *spec)
{
	int i = 0;
	int nb_char = 0;
	int nb_char_printed = 0;
	char *str = my_strdup(va_arg(va, char *));
	int precision = 0;

	if (spec->precision_point && spec->precision == NULL)
	{
		if (spec->width != NULL)
		{
			while (nb_char < my_getnbr(spec->width))
			{
				nb_char += my_putchar(' ');
			}
		}

		return (nb_char);
	}
	if (spec->precision != NULL)
	{
		precision = my_getnbr(spec->precision);
	}
	else
	{
		precision = my_strlen(str);
	}
	if (spec->left_align)
	{
		if (precision != 0)
		{
			while (i < precision)
			{
				nb_char += my_putchar(str[i]);
				nb_char_printed = nb_char;
				i++;
			}
		}
		else
		{
			nb_char += my_putstr(str);
			nb_char_printed = nb_char;
		}
		if (spec->width != NULL)
		{
			while (nb_char < my_getnbr(spec->width) - (precision - nb_char_printed))
			{
				nb_char += my_putchar(' ');
			}
		}
	}
	else
	{
		if (spec->width != NULL)
		{
			while (nb_char < my_getnbr(spec->width) - precision)
			{
				nb_char += my_putchar(' ');
			}
		}
		if (precision != 0)
		{
			while (i < precision)
			{
				nb_char += my_putchar(str[i]);
				i++;
			}
		}
		else
		{
			nb_char += my_putstr(str);
		}
	}

	return (nb_char);
}

int	my_putchar_va(va_list va, my_struct_spec_t *spec)
{
	int i = 0;
	int nb_char = 0;
	char char_to_print = (char)va_arg(va, int);

	if (spec->left_align)
	{
		nb_char += my_putchar(char_to_print);
		if (spec->width != NULL)
		{
			while (i < my_getnbr(spec->width) - 1)
			{
				nb_char += my_putchar(' ');
				i++;
			}
		}
	}
	else
	{
		if (spec->width != NULL)
		{
			while (i < my_getnbr(spec->width) - 1)
			{
				nb_char += my_putchar(' ');
				i++;
			}
		}
		nb_char += my_putchar(char_to_print);

	}

	return (nb_char);
}

int	my_putstr_non_printable_va(va_list va, my_struct_spec_t *spec)
{
	spec++;
	return (my_putstr_non_printable(va_arg(va, char *)));
}
