#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_struct_spec.h"
#include "my_printf.h"

int	main()
{
	//*********************** TEST m ***********************//
	//******************************************************//

	printf("TEST m\n");
	my_printf("%-10.5m");
	printf("\n");
	printf("%-10.5m");
	printf("\n");
	my_printf("%m");
	printf("\n");
	printf("%m");
	printf("\n");

	//******************************************************//

	//*********************** TEST c ***********************//
	//******************************************************//

	printf("TEST c\n");
	my_printf("%5c", 'h');
	printf("\n");
	printf("%5c", 'h');
	printf("\n");
	my_printf("%c", 'h');
	printf("\n");
	printf("%c", 'h');
	printf("\n");

	//******************************************************//

	//*********************** TEST s ***********************//
	//******************************************************//

	printf("TEST s\n");
	my_printf("%.2s", "hello");
	printf("\n");
	printf("%.2s", "hello");
	printf("\n");
	my_printf("%10s", "hello");
	printf("\n");
	printf("%10s", "hello");
	printf("\n");
	my_printf("%-10.3s", "hello");
	printf("\n");
	printf("%-10.3s", "hello");
	printf("\n");
	my_printf("%s", "hello");
	printf("\n");
	printf("%s", "hello");
	printf("\n");

	//******************************************************//

	//*********************** TEST S ***********************//
	//******************************************************//

	printf("TEST S\n");
	my_printf("%.6S", "hello\e");
	printf("\n");
	// printf("%.6S", "hello\e");
	printf("\n");
	my_printf("%10S", "hello\e");
	printf("\n");
	// printf("%10S", "hello\e");
	printf("\n");
	my_printf("%-10.3S", "hello\e");
	printf("\n");
	// printf("%-10.3S", "hello\e");
	printf("\n");
	my_printf("%S", "hello\e");
	printf("\n");
	// printf("%S", "hello\e");
	printf("\n");

	//******************************************************//

	//*********************** TEST D/I ***********************//
	//******************************************************//

	printf("TEST D\n");
	my_printf("%05d", 20);
	printf("\n");
	printf("%05d", 20);
	printf("\n");
	my_printf("%+d", 20);
	printf("\n");
	printf("%+d", 20);
	printf("\n");
	my_printf("% d", 20);
	printf("\n");
	printf("% d", 20);
	printf("\n");
	my_printf("%10.4d", 20);
	printf("\n");
	printf("%10.4d", 20);
	printf("\n");
	my_printf("%d", 20);
	printf("\n");
	printf("%d", 20);
	printf("\n");

	//******************************************************//

	//*********************** TEST O ***********************//
	//******************************************************//

	printf("TEST O\n");
	my_printf("%05o", 20);
	printf("\n");
	printf("%05o", 20);
	printf("\n");
	my_printf("%#o", 20);
	printf("\n");
	printf("%#o", 20);
	printf("\n");
	my_printf("%+o", 20);
	printf("\n");
	printf("%+o", 20);
	printf("\n");
	my_printf("% o", 20);
	printf("\n");
	printf("% o", 20);
	printf("\n");
	my_printf("%10.4o", 20);
	printf("\n");
	printf("%10.4o", 20);
	printf("\n");
	my_printf("%o", 20);
	printf("\n");
	printf("%o", 20);
	printf("\n");

	//******************************************************//

	//*********************** TEST X ***********************//
	//******************************************************//

	printf("TEST x\n");
	my_printf("%05x", 20);
	printf("\n");
	printf("%05x", 20);
	printf("\n");
	my_printf("%#x", 20);
	printf("\n");
	printf("%#x", 20);
	printf("\n");
	my_printf("%+x", 20);
	printf("\n");
	printf("%+x", 20);
	printf("\n");
	my_printf("% x", 20);
	printf("\n");
	printf("% x", 20);
	printf("\n");
	my_printf("%10.4x", 20);
	printf("\n");
	printf("%10.4x", 20);
	printf("\n");
	my_printf("%x", 20);
	printf("\n");
	printf("%x", 20);
	printf("\n");

	//******************************************************//

	return (0);
}




// int	main()
// {
// 	my_printf("Test: %s", "string");

// 	return (0);
// }
