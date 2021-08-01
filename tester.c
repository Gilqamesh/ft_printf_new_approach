#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a = malloc(sizeof(*a));

	printf("%p\n", a);
	ft_printf("%p\n\n", a);

	printf("%2p\n", a);
	ft_printf("%2p\n\n", a);

	printf("%30p\n", a);
	ft_printf("%30p\n\n", a);

	printf("%-p\n", a);
	ft_printf("%-p\n\n", a);

	printf("%-2p\n", a);
	ft_printf("%-2p\n\n", a);
	
	printf("%-30p\n", a);
	ft_printf("%-30p\n\n", a);

	printf("%p\n", NULL);
	ft_printf("%p\n\n", NULL);

	printf("%2p\n", NULL);
	ft_printf("%2p\n\n", NULL);

	printf("%30p\n", NULL);
	ft_printf("%30p\n\n", NULL);

	printf("%-p\n", NULL);
	ft_printf("%-p\n\n", NULL);

	printf("%-2p\n", NULL);
	ft_printf("%-2p\n\n", NULL);

	printf("%-30p\n", NULL);
	ft_printf("%-30p\n\n", NULL);
	return (0);
}