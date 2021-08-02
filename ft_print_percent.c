/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:24:53 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 15:41:31 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_n(t_pad_vars *vars, bool is_left_justified)
{
	if (!is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', 1);
	while (vars->zero_padding--)
		ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', 1);
}

static void	set_vars(t_printf *mystruct, t_pad_vars *vars)
{
	vars->n_len = 1;
	if (mystruct->flags.zero_padding)
	{
		vars->zero_padding = ft_maxofint(mystruct->flags.min_field_width
			- vars->n_len, 0);
		vars->space_padding = 0;
	}
	else
	{
		vars->space_padding = ft_maxofint(mystruct->flags.min_field_width
			- vars->n_len, 0);
		vars->zero_padding = 0;
	}
}

static void	set_flags(t_printf *mystruct)
{
	if (mystruct->flags.is_left_justified)
		mystruct->flags.zero_padding = false;
}

void	print_percent(t_printf *mystruct)
{
	t_pad_vars	vars;

	set_flags(mystruct);
	set_vars(mystruct, &vars);
	mystruct->printed_bytes += vars.space_padding + vars.zero_padding
		+ vars.n_len;
	if (mystruct->flags.is_left_justified)
		print_n(&vars, 1);
	else
		print_n(&vars, 0);
}
