/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:03:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 16:33:29 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	strtoupper(char **str)
{
	char	*cp;

	if (!str || !*str)
		return ;
	cp = *str;
	while (*cp)
	{
		*cp = ft_toupper(*cp);
		cp++;
	}
}

static void	print_n(char *alt_form, t_pad_vars *vars, t_unsigned_int_and_char x,
bool is_left_justified)
{
	char	*conv_result;

	conv_result = ft_itobase(x.n, 16);
	if (x.c > 'A' && x.c < 'Z')
		strtoupper(&conv_result);
	if (!is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd(alt_form, 1);
	while (vars->zero_padding--)
		ft_putchar_fd('0', 1);
	if (vars->n_len)
		ft_putstr_fd(conv_result, 1);
	if (is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', 1);
	free(conv_result);
}

static void	set_vars(t_printf *mystruct, t_pad_vars *vars, char **alt_form,
t_unsigned_int_and_char x)
{
	if (mystruct->flags.is_alternate_form && x.n)
	{
		if (x.c >= 'A' && x.c <= 'Z')
			*alt_form = "0X";
		else
			*alt_form = "0x";
	}
	else
		*alt_form = "";
	vars->n_len = ft_baselen(x.n, 16);
	if (mystruct->flags.is_there_precision && !x.n)
	{
		*alt_form = "";
		vars->n_len = 0;
	}
	vars->zero_padding = ft_maxofint(mystruct->flags.precision
		- vars->n_len, 0);
	vars->space_padding = ft_maxofint(mystruct->flags.min_field_width
		- ft_strlen(*alt_form) - vars->zero_padding - vars->n_len, 0);
	if (mystruct->flags.zero_padding)
	{
		vars->zero_padding = ft_maxofint(vars->zero_padding,
				vars->space_padding);
		vars->space_padding = 0;
	}
}

static void	set_flags(t_printf *mystruct)
{
	if (mystruct->flags.is_there_precision || mystruct->flags.is_left_justified)
		mystruct->flags.zero_padding = false;
}

void	print_hexa(t_printf *mystruct, unsigned int n, char conversion)
{
	t_pad_vars	vars;
	char		*alt_form;

	set_flags(mystruct);
	set_vars(mystruct, &vars, &alt_form,
		(t_unsigned_int_and_char){n, conversion});
	mystruct->printed_bytes += vars.space_padding + ft_strlen(alt_form)
		+ vars.zero_padding + vars.n_len;
	if (mystruct->flags.is_left_justified)
		print_n(alt_form, &vars, (t_unsigned_int_and_char){n, conversion}, 1);
	else
		print_n(alt_form, &vars, (t_unsigned_int_and_char){n, conversion}, 0);
}
