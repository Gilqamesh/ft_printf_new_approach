/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:28 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 13:36:45 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

static char	*get_sign_prefix(t_printf *mystruct, int n)
{
	if (n < 0)
		return ("-");
	else if (mystruct->flags.is_sign_prefixed)
		return ("+");
	else if (mystruct->flags.is_space_prefixed)
		return (" ");
	else
		return ("");
}

static void	print_n(char *sign_prefix, t_pad_vars *vars, int n,
bool is_left_justified)
{
	if (!is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd(sign_prefix, 1);
	while (vars->zero_padding--)
		ft_putchar_fd('0', 1);
	if (n == INT_MIN)
		ft_putstr_fd("2147483648", 1);
	else if (vars->n_len)
		ft_putnbr_fd(ft_abs_int(n), 1);
	if (is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', 1);
}

static void	set_vars(t_printf *mystruct, t_pad_vars *vars, char **sign_prefix,
int n)
{
	vars->n_len = ft_intlen(n);
	if (mystruct->flags.is_there_precision && !n)
		vars->n_len = 0;
	*sign_prefix = get_sign_prefix(mystruct, n);
	vars->zero_padding = ft_maxofint(mystruct->flags.precision
			- vars->n_len, 0);
	vars->space_padding = ft_maxofint(mystruct->flags.min_field_width
			- ft_strlen(*sign_prefix) - vars->zero_padding - vars->n_len, 0);
	if (mystruct->flags.zero_padding && mystruct->flags.zero_padding)
		vars->zero_padding = ft_maxofint(vars->zero_padding,
				vars->space_padding);
	if (mystruct->flags.zero_padding)
		vars->space_padding = 0;
}

static void	set_flags(t_printf *mystruct)
{
	if (mystruct->flags.is_there_precision || mystruct->flags.is_left_justified)
		mystruct->flags.zero_padding = false;
	if (mystruct->flags.is_sign_prefixed)
		mystruct->flags.is_space_prefixed = false;
}

void	print_integer(t_printf *mystruct, int n)
{
	t_pad_vars	vars;
	char		*sign_prefix;

	set_flags(mystruct);
	set_vars(mystruct, &vars, &sign_prefix, n);
	mystruct->printed_bytes += vars.space_padding + ft_strlen(sign_prefix)
		+ vars.zero_padding + vars.n_len;
	if (mystruct->flags.is_left_justified)
		print_n(sign_prefix, &vars, n, 1);
	else
		print_n(sign_prefix, &vars, n, 0);
}
