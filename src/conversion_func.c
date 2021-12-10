#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#include "my.h"
#include "conversion_func.h"


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

int	my_putstr_non_printable_va(va_list va)
{
	return (my_putstr_non_printable(va_arg(va, char *)));
}
