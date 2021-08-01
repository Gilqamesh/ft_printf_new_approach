#include "ft_printf.h"
#include <unistd.h>

static void	set_flags_helper(char *format, t_printf *mystruct)
{
	if (format[mystruct->index] == '#')
	{
		mystruct->index++;
		mystruct->flags.is_altarnate_form = true;
	}
	if (format[mystruct->index] == '0')
	{
		mystruct->index++;
		mystruct->flags.zero_padding = true;
	}
	if (format[mystruct->index] == '-')
	{
		mystruct->index++;
		mystruct->flags.is_left_justified = true;
	}
	if (format[mystruct->index] == ' ')
	{
		mystruct->index++;
		mystruct->flags.is_space_prefixed = true;
	}
	if (format[mystruct->index] == '+')
	{
		mystruct->index++;
		mystruct->flags.is_sign_prefixed = true;
	}
}
#include <stdio.h>
static void	set_flags(char *format, t_printf *mystruct)
{
	ft_bzero(&mystruct->flags, sizeof(mystruct->flags));
	set_flags_helper(format, mystruct);
	if (ft_isdigit(format[mystruct->index]))
	{
		mystruct->flags.min_field_width = ft_atoi(format + mystruct->index);
		mystruct->index += ft_intlen(mystruct->flags.min_field_width);
	}
	if (format[mystruct->index] == '.')
	{
		mystruct->flags.is_there_precision = true;
		mystruct->index++;
		if (ft_isdigit(format[mystruct->index]))
		{
			mystruct->flags.precision = ft_atoi(format + mystruct->index);
			mystruct->index += ft_intlen(mystruct->flags.precision);
		}
	}
}

static void	handle_conversion(char conversion, t_printf *mystruct, va_list ap)
{
	if (conversion == 'c')
		print_character(mystruct, (unsigned char)va_arg(ap, int));
	else if (conversion == 's')
		print_string(mystruct, va_arg(ap, char *));
	else if (conversion == 'p')
		print_pointer(mystruct, (unsigned long)va_arg(ap, void *));
	// else if (conversion == 'd' || conversion == 'i')
	// 	print_integer(mystruct, va_arg(ap, int));
	// else if (conversion == 'u')
	// 	print_unsigned(mystruct, va_arg(ap, unsigned int));
	// else if (conversion == 'x' || conversion == 'X')
	// 	print_hexa(mystruct, va_arg(ap, unsigned int), conversion);
	// else if (conversion == '%')
	// 	print_percent(mystruct);
}

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	mystruct;

	ft_bzero(&mystruct, sizeof(mystruct));
	va_start(ap, format);
	while (format[mystruct.index])
	{
		if (format[mystruct.index] == '%')
		{
			mystruct.index++;
			set_flags((char *)format, &mystruct);
			handle_conversion(format[mystruct.index], &mystruct, ap);
		}
		else
		{
			ft_putchar_fd(format[mystruct.index], 1);
			mystruct.printed_bytes++;
		}
		mystruct.index++;
	}
	va_end(ap);
	return (mystruct.printed_bytes);
}
