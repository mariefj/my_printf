#include <stdarg.h>

#include "my.h"
#include "conversion_base_func.h"

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
