#ifndef _MY_PRINTF_H_
#define _MY_PRINTF_H_

#include "my_struct_spec.h"

int	print_flag_before(my_struct_spec_t *spec);
int	print_arg(va_list va, const char **spec_str);
int 	do_conversion(my_struct_spec_t *spec, va_list va);
int	print_conversion(my_struct_spec_t *spec, va_list va);
int	my_printf(const char *format, ...);

#endif // _MY_PRINTF_H_