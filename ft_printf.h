#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>

typedef struct s_printf_flags
{
	bool	is_left_justified;
	bool	zero_padding;
	bool	is_there_precision;
	int		precision;
	bool	is_altarnate_form;
	bool	is_space_prefixed;
	bool	is_sign_prefixed;
	int		min_field_width;
}	t_printf_flags;

typedef struct s_printf
{
	t_printf_flags	flags;
	int				printed_bytes;
}	t_printf;

int	ft_printf(const char *format, ...);

#endif
