/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:38 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 10:29:38 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "Mylib/mylib.h"

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
	int				index;
}	t_printf;

typedef struct s_pad_vars
{
	int	space_padding;
	int	zero_padding;
	int	n_len;
}	t_pad_vars;

int		ft_printf(const char *format, ...);
void	print_character(t_printf *mystruct, unsigned char c);
void	print_string(t_printf *mystruct, char *str);
void 	print_pointer(t_printf *mystruct, unsigned long addr);
void	print_integer(t_printf *mystruct, int n);
void	print_unsigned(t_printf *mystruct, unsigned int n);

#endif
