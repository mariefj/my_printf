#include "my.h"
#include "my_struct_spec.h"
#include "set_flags.h"

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