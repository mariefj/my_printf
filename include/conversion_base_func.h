#ifndef CONVERSION_BASE_FUNC_H
#define CONVERSION_BASE_FUNC_H

#include <stdarg.h>

#include "my_struct_spec.h"

int	my_putnbr_base_octal_va(va_list va, my_struct_spec_t *spec);
int	my_putnbr_base_decimal_va(va_list va, my_struct_spec_t *spec);
int	my_putnbr_base_hexa_lower_va(va_list va, my_struct_spec_t *spec);
int	my_putnbr_base_hexa_upper_va(va_list va, my_struct_spec_t *spec);
int	my_putnbr_base_binary_va(va_list va, my_struct_spec_t *spec);
;
#endif // CONVERSION_FUNC_H