#ifndef _MY_PRINTF_H_
#define _MY_PRINTF_H_

#include "my_struct_spec.h"

int	print_arg(va_list va, const char **spec_str);
int 	do_conversion(char conversion_flag, va_list va);
int	print_conversion(my_struct_spec_t *spec, va_list va);
int	my_printf(const char *format, ...);

#endif // _MY_PRINTF_H_