#include "ft_printf.h"
#include <stdio.h>

void print_pointer(t_printf *mystruct, unsigned long addr)
{
	int		addrHexLen;
	char	*addrStr;

	addrHexLen = ft_baselen(addr, 16) + 2;
	mystruct->printed_bytes += ft_maxofint(mystruct->flags.min_field_width,
		addrHexLen);
	addrStr = ft_strjoin_free(ft_strdup("0x"), ft_itobase(addr, 16));
	if (mystruct->flags.is_left_justified)
		ft_putstr_fd(addrStr, 1);
	while (mystruct->flags.min_field_width-- - addrHexLen > 0)
		ft_putchar_fd(' ', 1);
	if (!mystruct->flags.is_left_justified)
		ft_putstr_fd(addrStr, 1);
	free(addrStr);
}
