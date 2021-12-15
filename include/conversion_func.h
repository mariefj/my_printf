#ifndef CONVERSION_FUNC_H
#define CONVERSION_FUNC_H

#include <stdarg.h>

#include "my_struct_spec.h"

int	my_put_nbr_va(va_list va, my_struct_spec_t *spec);
int	my_putstr_va(va_list va, my_struct_spec_t *spec);
int	my_putchar_va(va_list va, my_struct_spec_t *spec);
int	my_putstr_non_printable_va(va_list va, my_struct_spec_t *spec);


#endif // CONVERSION_FUNC_H
