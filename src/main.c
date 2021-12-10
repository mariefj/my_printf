#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_struct_spec.h"
#include "my_printf.h"


int	main()
{
	// unsigned int nb = 122;

	// printf("%s\n", my_itoa_base_unsigned(nb, "0123456789abcdef"));
	// my_putnbr_base(nb, "0123456789abcdef");

	// int nb  = 122;
	// my_putnbr_base(nb, "01234567");
	// printf("%p", &nb);

	// short int nb = 10;
	// my_putstr(my_itoa_(nb));

	const char *str1 = "%% test %o test %x et %X et %b test str : %S";
	unsigned int nb = 30;
	char *str = "hello \n world";

	my_printf(str1, nb, nb, nb, nb, str);
	printf("\n");
	printf("vraie adresse : %p", &nb);
	printf("\n");
	my_printf("test adresse  : %p", &nb);
	printf("\n");

	printf("%m");
	printf("\n");
	my_printf("test : %m");

	return (0);
}




// int	main()
// {
// 	my_printf("Test: %s", "string");

// 	return (0);
// }
