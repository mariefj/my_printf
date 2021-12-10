#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#include "my.h"
#include "my_put_ptr_address_va.h"

static int	my_putnbr_hexa_addr(uintptr_t nbr)
{
	int i = 0;
	char str[64];
	char base[] = "0123456789abcdef";
	int nb_char = 0;

	while (nbr > 0)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	str[i] = '\0';
	nb_char += my_putstr("0x");
	nb_char += my_putstr(my_revstr(str));

	return (nb_char);
}

static	int	my_showaddr_ptr(void *ptr)
{
	uintptr_t addr = (uintptr_t)ptr;

	return (my_putnbr_hexa_addr(addr));
}

int	my_put_ptr_address_va(va_list va)
{
	return (my_showaddr_ptr(va_arg(va, void *)));
}