#ifndef TOOLS_H
#define TOOLS_H

#define CONVERSION_NB 10

#include <stdbool.h>
#include <stdarg.h>

typedef struct	my_struct_spec_s
{
		bool	prefix;
		bool	zero;
		bool	left_align;
		bool	space_before_number;
		bool	sign;
		char	*width;
		char	*precision;
		char	*modifier;
		char	conversion;
}		my_struct_spec_t;

typedef struct	my_struct_func_ptr_conversion_s
{
		char	conversion_tag;
		int	(*conversion_func)(va_list va);
}		my_struct_func_ptr_conversion_t;

void		set_up_struct_conversion(my_struct_func_ptr_conversion_t *ops);
void		my_show_spec_struct(my_struct_spec_t *spec);
my_struct_spec_t *spec_init();
int 		do_conversion(char conversion_flag, va_list va);

// long long int	my_abs_(intmax_t nb);
// int		my_get_digits_(intmax_t nb);
// char		*my_itoa_(intmax_t nb);
// char		*my_itoa(int nb);
// char		*my_itoa_base_unsigned(unsigned int nbr, char const *base);


#endif // TOOLS_H