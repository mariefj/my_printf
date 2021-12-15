#include <stdarg.h>
#include <stdio.h>

#include "my.h"
#include "conversion_base_func.h"

int	my_putnbr_base_octal_va(va_list va, my_struct_spec_t *spec)
{
	int nb_char = 0;
	int nb_va_arg = va_arg(va, int);

	printf("sign func %d\n", spec->sign);
	if (nb_va_arg > 0 && spec->sign)
	{
		nb_char += my_putchar('+');
	}
	if (nb_va_arg != 0)
	{
		if (spec->prefix)
		{
			nb_char += my_putchar('0');
		}
	}
	nb_char += my_putnbr_base(nb_va_arg, "01234567");

	return (nb_char);
}

int	my_putnbr_base_decimal_va(va_list va, my_struct_spec_t *spec)
{
	int nb_char = 0;
	int nb_va_arg = va_arg(va, int);

	if (nb_va_arg > 0 && spec->sign)
	{
		nb_char += my_putchar('+');
	}
	nb_char += my_putnbr_base(nb_va_arg, "0123456789");

	return (nb_char);
}

int	my_putnbr_base_hexa_lower_va(va_list va, my_struct_spec_t *spec)
{
	int nb_char = 0;
	int nb_va_arg = va_arg(va, int);

	if (nb_va_arg > 0 && spec->sign)
	{
		nb_char += my_putchar('+');
	}
	nb_char += my_putnbr_base(nb_va_arg, "0123456789abcdef");

	return (nb_char);
}

int	my_putnbr_base_hexa_upper_va(va_list va, my_struct_spec_t *spec)
{
	int nb_char = 0;
	int nb_va_arg = va_arg(va, int);

	if (nb_va_arg > 0 && spec->sign)
	{
		nb_char += my_putchar('+');
	}
	nb_char += my_putnbr_base(nb_va_arg, "0123456789ABCDEF");

	return (nb_char);
}

int	my_putnbr_base_binary_va(va_list va, my_struct_spec_t *spec)
{
	int nb_char = 0;
	int nb_va_arg = va_arg(va, int);

	if (nb_va_arg > 0 && spec->sign)
	{
		nb_char += my_putchar('+');
	}
	nb_char += my_putnbr_base(nb_va_arg, "01");

	return (nb_char);
}
