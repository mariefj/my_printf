#include <stdio.h>
#include <stdarg.h>

#include "my.h"
#include "conversion_func.h"

int	my_put_strerror_ptr(va_list va)
{
	va++;
	return (0);
}

int	my_put_nbr_ptr(va_list va)
{
	return (my_put_nbr(va_arg(va, int)));
}

int	my_putstr_ptr(va_list va)
{
	return (my_putstr(va_arg(va, char *)));
}

int	my_putchar_ptr(va_list va)
{
	return (my_putchar((char)va_arg(va, int)));
}

int	my_putnbr_base_ptr(va_list va)
{
	va++;
	return (0);
}
