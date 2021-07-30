#include "ft_printf.h"
#include <unistd.h>

void	set_flags(char **format, t_printf *mystruct)
{
	// #0- +
	ft_bzero(&mystruct->flags, sizeof(mystruct->flags));
	if (**format == '#')
	{
		(*format)++;
		mystruct->flags.is_altarnate_form = TRUE;
	}
	if (**format == '0')
	{
		(*format)++;
		mystruct->flags.zero_padding = TRUE;
	}
	if (**format == '-')
	{
		(*format)++;
		mystruct->flags.is_left_justified = TRUE;
	}
	if (**format == ' ')
	{
		(*format)++;
		mystruct->flags.is_space_prefixed = TRUE;
	}
	if (**format == '+')
	{
		(*format)++;
		mystruct->flags.is_sign_prefixed = TRUE;
	}
	if (ft_isdigit(**format))
	{
		mystruct->flags.min_field_width = ft_atoi(*format);
		*format += ft_intlen(mystruct->flags.min_field_width);
	}
	if (**format == '.')
	{
		mystruct->flags.is_there_precision = TRUE;
		(*format)++;
		if (ft_isdigit(**format))
			mystruct->flags.precision = ft_atoi(*format);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	mystruct;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			set_flags(&format, &mystruct);
			handle_conversion(format++, &mystruct, ap);
		}
		else
		{
			write(1, format, 1);
			mystruct.printed_bytes++;
		}
	}
	va_end(ap);
	return (mystruct.printed_bytes);
}
