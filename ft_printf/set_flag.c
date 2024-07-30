/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:23:12 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/04 12:49:32 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_hash(t_fmt *fmt)
{
	if (!fmt)
		return ;
	fmt->alternate = '#';
}

void	set_zero(t_fmt *fmt)
{
	if (!fmt)
		return ;
	if (fmt->padding == '-')
		return ;
	fmt->padding = '0';
}

void	set_minus(t_fmt *fmt)
{
	if (!fmt)
		return ;
	fmt->padding = '-';
}

void	set_space(t_fmt *fmt)
{
	if (!fmt)
		return ;
	if (fmt->sign == '+')
		return ;
	fmt->sign = ' ';
}

void	set_plus(t_fmt *fmt)
{
	if (!fmt)
		return ;
	fmt->sign = '+';
}
