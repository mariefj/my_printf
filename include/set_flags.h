#ifndef _SET_FLAGS_H_
#define _SET_FLAGS_H_

#include "my_struct_spec.h"

int	set_flags(my_struct_spec_t *spec, char flag);
int	set_width(my_struct_spec_t *spec, char digit);
int	set_precision(my_struct_spec_t *spec, char digit);
int	set_double_letters_modifier(my_struct_spec_t *spec, const char *spec_str, char modifier);
int	set_modifier(my_struct_spec_t *spec, const char *spec_str);

#endif // _SET_FLAGS_H_
