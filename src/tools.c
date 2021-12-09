#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "tools.h"
#include "conversion_func.h"

// char	*my_itoa_base_unsigned(unsigned int nbr, char const *base)
// {
// 	int i = 0;
// 	char str[64];
// 	int base_len = my_strlen(base);

// 	while (nbr > 0)
// 	{
// 		str[i] = base[nbr % base_len];
// 		nbr = nbr / base_len;
// 		i++;
// 	}
// 	str[i] = '\0';

// 	return (my_revstr(str));
// }


// intmax_t	my_abs_(intmax_t nb)
// {
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 	}

// 	return (nb);
// }

// int	my_get_digits_(intmax_t nb)
// {
// 	int i = 1;

// 	nb = my_abs_(nb);
// 	while (nb >= 10)
// 	{
// 		nb /= 10;
// 		i++;
// 	}

// 	return (i);
// }

// char	*my_itoa_(intmax_t nb)
// {
// 	int i = my_get_digits_(nb);
// 	char *str = NULL;
// 	intmax_t nb_abs = my_abs_(nb);

// 	while (i > 0)
// 	{
// 		str = my_append_c(str, nb_abs % 10 + 48);
// 		if (str == NULL)
// 			return (NULL);
// 		nb_abs = nb_abs / 10;
// 		i--;
// 	}
// 	if (nb < 0)
// 		str = my_append_c(str, '-');

// 	return (my_revstr(str));
// }

// char	*my_itoa(int nb)
// {
// 	int i = my_get_digits(nb);
// 	char *str = NULL;
// 	int nb_abs = my_abs(nb);

// 	while (i > 0)
// 	{
// 		str = my_append_c(str, nb_abs % 10 + 48);
// 		if (str == NULL)
// 			return (NULL);
// 		nb_abs = nb_abs / 10;
// 		i--;
// 	}
// 	if (nb < 0)
// 		str = my_append_c(str, '-');

// 	return (my_revstr(str));
// }

void	my_show_spec_struct(my_struct_spec_t *spec)
{
	printf("prefix = %d\n", spec->prefix);
	printf("zero = %d\n", spec->zero);
	printf("left_align = %d\n", spec->left_align);
	printf("space_before_nb = %d\n", spec->space_before_number);
	printf("sign = %d\n", spec->sign);
	printf("width = %s\n", spec->width);
	printf("precision = %s\n", spec->precision);
	printf("modifier = %s\n", spec->modifier);
	printf("conversion = %c\n", spec->conversion);
}

my_struct_spec_t *spec_init()
{
	my_struct_spec_t *spec = (my_struct_spec_t *)malloc(sizeof(my_struct_spec_t));
	if (!spec)
		exit(84);
	spec->prefix = 0;
	spec->zero = 0;
	spec->left_align = 0;
	spec->space_before_number = 0;
	spec->sign = 0;
	spec->width = NULL;
	spec->precision = NULL;
	spec->modifier = NULL;
	spec->conversion = -1;

	return (spec);
}

void 	set_up_struct_conversion(my_struct_func_ptr_conversion_t *conversions)
{
	conversions[0].conversion_tag = 'd';
	conversions[0].conversion_func = &my_put_nbr_va;

	conversions[1].conversion_tag = 'i';
	conversions[1].conversion_func = &my_put_nbr_va;

	conversions[2].conversion_tag = 'o';
	conversions[2].conversion_func = &my_putnbr_base_octal_va;

	conversions[3].conversion_tag = 'u';
	conversions[3].conversion_func = &my_putnbr_base_decimal_va;

	conversions[4].conversion_tag = 'x';
	conversions[4].conversion_func = &my_putnbr_base_hexa_lower_va;

	conversions[5].conversion_tag = 'X';
	conversions[5].conversion_func = &my_putnbr_base_hexa_upper_va;

	conversions[6].conversion_tag = 'c';
	conversions[6].conversion_func = &my_putchar_va;

	conversions[7].conversion_tag = 's';
	conversions[7].conversion_func = &my_putstr_va;

	conversions[8].conversion_tag = 'p';
	conversions[8].conversion_func = &my_put_nbr_va;

	conversions[9].conversion_tag = 'm';
	conversions[9].conversion_func = &my_put_strerror_va;

	conversions[10].conversion_tag = 'b';
	conversions[10].conversion_func = &my_putnbr_base_binary_va;

	conversions[11].conversion_tag = 'S';
	conversions[11].conversion_func = &my_putstr_non_printable_va;
}

int 	do_conversion(char conversion_flag, va_list va)
{
	my_struct_func_ptr_conversion_t	conversions[CONVERSION_NB];
	int				i = 0;

	set_up_struct_conversion(conversions);
	while (i != CONVERSION_NB)
	{
		if (conversions[i].conversion_tag == conversion_flag)
			return (conversions[i].conversion_func(va));
		i++;
	}

	return (0);
}
