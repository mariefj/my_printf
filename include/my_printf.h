#ifndef _MY_PRINTF_H
#define _MY_PRINTF_H

#include "tools.h"

//int	my_printf(const char *format, ...);
int	is_flag(char flag);
int	set_flags(my_struct_spec_t *spec, char flag);
int	set_width(my_struct_spec_t *spec, char digit);
int	set_precision(my_struct_spec_t *spec, char digit);
int	is_modifier(char modifier);
int	set_double_letters_modifier(my_struct_spec_t *spec, const char *spec_str, char modifier);
int	set_modifier(my_struct_spec_t *spec, const char *spec_str);
int	is_conversion(char conversion);
int	print_arg(va_list va, const char **spec_str);
int	my_printf(const char *format, ...);
int	print_conversion(my_struct_spec_t *spec, va_list va);

#endif // _MY_PRINTF_H