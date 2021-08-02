/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:42 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 10:29:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Pointer test
// int main()
// {
// 	int *a = malloc(sizeof(*a));

// 	printf("return: %d", printf("|%p|\n", a));
// 	printf("return: %d", ft_printf("|%p|\n\n", a));

// 	printf("return: %d", printf("|%2p|\n", a));
// 	printf("return: %d", ft_printf("|%2p|\n\n", a));

// 	printf("return: %d", printf("|%30p|\n", a));
// 	printf("return: %d", ft_printf("|%30p|\n\n", a));

// 	printf("return: %d", printf("|%-p|\n", a));
// 	printf("return: %d", ft_printf("|%-p|\n\n", a));

// 	printf("return: %d", printf("|%-2p|\n", a));
// 	printf("return: %d", ft_printf("|%-2p|\n\n", a));

// 	printf("return: %d", printf("|%-30p|\n", a));
// 	printf("return: %d", ft_printf("|%-30p|\n\n", a));

// 	printf("return: %d", printf("|%p|\n", NULL));
// 	printf("return: %d", ft_printf("|%p|\n\n", NULL));

// 	printf("return: %d", printf("|%2p|\n", NULL));
// 	printf("return: %d", ft_printf("|%2p|\n\n", NULL));

// 	printf("return: %d", printf("|%30p|\n", NULL));
// 	printf("return: %d", ft_printf("|%30p|\n\n", NULL));

// 	printf("return: %d", printf("|%-p|\n", NULL));
// 	printf("return: %d", ft_printf("|%-p|\n\n", NULL));

// 	printf("return: %d", printf("|%-2p|\n", NULL));
// 	printf("return: %d", ft_printf("|%-2p|\n\n", NULL));

// 	printf("return: %d", printf("|%-30p|\n", NULL));
// 	printf("return: %d", ft_printf("|%-30p|\n\n", NULL));
// 	return (0);
// }

// Integer test
// int main()
// {
// 	printf("|%-d|\n", -122);
// 	ft_printf("|%-d|\n\n", -122);

// 	printf("|%-.6d|\n", -122);
// 	ft_printf("|%-.6d|\n\n", -122);

// 	printf("|%- .2d|\n", -122);
// 	ft_printf("|%- .2d|\n\n", -122);

// 	printf("|%-+.8d|\n", +122);
// 	ft_printf("|%+-.8d|\n\n", +122);

// 	printf("|%-+20.8d|\n", +122);
// 	ft_printf("|%+-20.8d|\n\n", +122);

// 	printf("|%-+20.8d|\n", INT_MIN);
// 	ft_printf("|%+-20.8d|\n\n", INT_MIN);
	
// 	printf("|%0 5d|\n", 12);
// 	ft_printf("|%0 5d|\n", 12);

// 	printf("|%d|\n", -122);
// 	ft_printf("|%d|\n\n", -122);

// 	printf("|%.6d|\n", -122);
// 	ft_printf("|%.6d|\n\n", -122);

// 	printf("|% .2d|\n", -122);
// 	ft_printf("|% .2d|\n\n", -122);

// 	printf("|%+.8d|\n", +122);
// 	ft_printf("|%+.8d|\n\n", +122);

// 	printf("|%+20.8d|\n", +122);
// 	ft_printf("|%+20.8d|\n\n", +122);

// 	printf("|%+20.8d|\n", INT_MIN);
// 	ft_printf("|%+20.8d|\n\n", INT_MIN);

// 	printf("|this %d number|\n", 17);
// 	ft_printf("|this %d number|\n\n", 17);

// 	printf("|%+d|\n", 0);
// 	ft_printf("|%+d|\n\n", 0);

// 	printf("|%5.d|\n", 0);
// 	ft_printf("|%5.d|\n", 0);

// 	printf("|%+5.d|\n", 0);
// 	ft_printf("|%+5.d|\n", 0);

// 	printf("|%.d|\n", 0);
// 	ft_printf("|%.d|\n", 0);

// 	printf("|%+.d|\n", 0);
// 	ft_printf("|%+.d|\n", 0);
// 	return (0);
// }

// String test
// int main()
// {
// 	printf("|%s|\n", NULL);
// 	ft_printf("|%s|\n\n", NULL);

// 	printf("|%.2s|\n", NULL);
// 	ft_printf("|%.2s|\n\n", NULL);

// 	printf("|%.8s|\n", NULL);
// 	ft_printf("|%.8s|\n\n", NULL);

// 	printf("|%s|\n", "hey");
// 	ft_printf("|%s|\n\n", "hey");

// 	printf("|%.2s|\n", "hey");
// 	ft_printf("|%.2s|\n\n", "hey");

// 	printf("|%.8s|\n", "hey");
// 	ft_printf("|%.8s|\n\n", "hey");
// }

// Unsigned test
// int main()
// {
// 	printf("|%u|\n", 12);
// }

// Hexa (X) test
// int main()
// {
// 	printf("|%#5.3x|\n", 123);
// 	ft_printf("|%#5.3x|\n\n", 123);

// 	printf("|%#-8.x|\n", 123);
// 	ft_printf("|%#-8.x|\n\n", 123);

// 	printf("|%#08.3x|\n", 123);
// 	printf("|%#08.3x|\n", 123);

// 	printf("|%#08x|\n", 123);
// 	ft_printf("|%#08x|\n", 123);

// 	printf("|%#08.x|\n", 0);
// 	ft_printf("|%#08.x|\n", 0);

// 	printf("|%#08.2x|\n", 1);
// 	ft_printf("|%#08.2x|\n", 1);
// }

// Percent test
// int main()
// {
// 	printf("|%#%|\n");
// 	printf("|%3%|\n");
// 	printf("|%-%|\n");
// 	printf("|%-3%|\n");
// 	printf("|%03%|\n");
// 	printf("|%-03%|\n");
// 	printf("|% %|\n");
// 	printf("|%+%|\n");
// 	printf("|%+ 03.6%|\n");
// 	printf("|%+ 03.%|\n");
// 	printf("|%+ 03.65%|\n");
// 	printf("|%+ 03.08%|\n");
// 	printf("|%.6%|\n");
// 	printf("|%.%|\n");
// 	printf("|%.65%|\n");
// 	printf("|%.08%|\n");
// 	printf("|%.1%|\n");
// 	printf("|%.2%|\n");
// }

// Additional tests
int main()
{
	printf("|c%#X-i|\n", 42000);
	ft_printf("|c%#X-i|\n\n", 42000);

	printf("|%p|\n", (void *)-1);
	ft_printf("|%p|\n\n", (void *)-1);

	printf("|--.%#Xs|\n", 0);
	ft_printf("|--.%#Xs|\n\n", 0);

	printf("|--.%#xs|\n", 0);
	ft_printf("|--.%#xs|\n\n", 0);

	printf("|--.%#.xs|\n", 0);
	ft_printf("|--.%#.xs|\n\n", 0);
}