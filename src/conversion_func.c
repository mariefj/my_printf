#include <stdio.h>
#include <stdarg.h>

#include "my.h"
#include "conversion_func.h"

int	my_put_strerror_va(va_list va)
{
	va++;
	return (0);
}

int	my_put_nbr_va(va_list va)
{
	return (my_put_nbr(va_arg(va, int)));
}

int	my_putstr_va(va_list va)
{
	return (my_putstr(va_arg(va, char *)));
}

int	my_putchar_va(va_list va)
{
	return (my_putchar((char)va_arg(va, int)));
}

int	my_putnbr_base_octal_va(va_list va)
{
	return (my_putnbr_base(va_arg(va, int), "01234567"));
}

int	my_putnbr_base_decimal_va(va_list va)
{
	return (my_putnbr_base(va_arg(va, int), "0123456789"));
}

int	my_putnbr_base_hexa_lower_va(va_list va)
{
	return (my_putnbr_base(va_arg(va, int), "0123456789abcdef"));
}

int	my_putnbr_base_hexa_upper_va(va_list va)
{
	return (my_putnbr_base(va_arg(va, int), "0123456789ABCDEF"));
}

int	my_putnbr_base_binary_va(va_list va)
{
	return (my_putnbr_base(va_arg(va, int), "01"));
}

int	my_putstr_non_printable_va(va_list va)
{
	return (my_putstr_non_printable(va_arg(va, char *)));
}
