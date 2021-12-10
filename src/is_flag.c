#include "my.h"
#include "is_flag.h"


int	is_flag(char flag)
{
	int i = 0;
	const char *array_flag = "#0- +";
	int nb_flag = my_strlen(array_flag);

	while (i < nb_flag)
	{
		if (flag == array_flag[i])
			return 1;
		i++;
	}

	return 0;
}

int	is_modifier(char modifier)
{
	int i = 0;
	const char *array_modifier = "hlqjzt";
	int nb_modifier = my_strlen(array_modifier);

	while (i < nb_modifier)
	{
		if (modifier == array_modifier[i])
			return 1;

		i++;
	}

	return 0;
}

int	is_conversion(char conversion)
{
	int i = 0;
	const char *array_conversion = "diouxXcspm%bS";
	int nb_conversion = my_strlen(array_conversion);

	while (i < nb_conversion)
	{
		if (conversion == array_conversion[i])
			return 1;
		i++;
	}

	return 0;
}