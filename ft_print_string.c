#include "ft_printf.h"

void	print_string(t_printf *mystruct, char *str)
{
	int	space_padding;
	int	printedStrLen;

	if (mystruct->flags.is_there_precision)
		printedStrLen = ft_minofint(mystruct->flags.precision, ft_strlen(str));
	else
		printedStrLen = ft_strlen(str);
	space_padding = mystruct->flags.min_field_width - printedStrLen;
	mystruct->printed_bytes += ft_maxofint(space_padding, 0) + printedStrLen;
	if (mystruct->flags.is_left_justified)
		ft_putnstr_fd(str, printedStrLen, 1);
	while (space_padding-- > 0)
		ft_putchar_fd(' ', 1);
	if (!mystruct->flags.is_left_justified)
		ft_putnstr_fd(str, printedStrLen, 1);
}
