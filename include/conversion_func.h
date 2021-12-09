#ifndef CONVERSION_FUNC_H
#define CONVERSION_FUNC_H

#include <stdarg.h>

int	my_put_strerror_va(va_list va);
int	my_put_nbr_va(va_list va);
int	my_putstr_va(va_list va);
int	my_putchar_va(va_list va);
int	my_putnbr_base_octal_va(va_list va);
int	my_putnbr_base_decimal_va(va_list va);
int	my_putnbr_base_hexa_lower_va(va_list va);
int	my_putnbr_base_hexa_upper_va(va_list va);
int	my_putnbr_base_binary_va(va_list va);
int	my_putstr_non_printable_va(va_list va);


#endif // CONVERSION_FUNC_H
