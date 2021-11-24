#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_printf.h"
#include "tools.h"

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

	short int n = 5;

	printf("%ld\n", (long int)n);

	return (0);
}




// int	main()
// {
// 	my_printf("Test: %s", "string");

// 	return (0);
// }
