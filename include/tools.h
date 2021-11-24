#ifndef TOOLS_H
#define TOOLS_H

#include <stdbool.h>

typedef struct	my_struct_spec_s
{
		bool	prefix;
		bool	zero;
		bool	left_align;
		bool	space_bf_nb;
		bool	sign;
		char	*width;
		char	*precision;
		char	*modifier;
		char	conversion;
}		my_struct_spec_t;

long long int	my_abs_(intmax_t nb);
int		my_get_digits_(intmax_t nb);
char		*my_itoa_(intmax_t nb);
char		*my_itoa(int nb);
char		*my_itoa_base_unsigned(unsigned int nbr, char const *base);


#endif // TOOLS_H