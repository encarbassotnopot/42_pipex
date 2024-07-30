/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:05:48 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/10 10:13:53 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

t_fmt	*init_fmt(void)
{
	t_fmt	*fmt;

	fmt = malloc(sizeof(t_fmt));
	if (!fmt)
		return (NULL);
	fmt->alternate = '\0';
	fmt->padding = '\0';
	fmt->sign = '\0';
	fmt->min_width = 0;
	fmt->precision = -1;
	fmt->conversion = '\0';
	fmt->len = 0;
	return (fmt);
}

void	fix_format(t_fmt **fmt)
{
	if (ft_strchr_idx("cspdiuxXo%", (*fmt)->conversion) == -1)
	{
		free(*fmt);
		*fmt = NULL;
		return ;
	}
	if ((*fmt)->precision != -1 && (*fmt)->padding == '0')
	{
		(*fmt)->padding = '\0';
	}
	else if ((*fmt)->min_width != -1 && (*fmt)->padding == '0'
		&& ft_strchr_idx("pdiuxXo", (*fmt)->conversion) != -1)
	{
		(*fmt)->precision = (*fmt)->min_width;
		if ((*fmt)->precision == 0)
			(*fmt)->precision = 1;
		(*fmt)->min_width = 0;
	}
}

int	parse_prec(unsigned char **c)
{
	if (**c == '-')
	{
		*c += 1;
		if (**c == '0')
			return (0);
		ft_raw_atoi_fwd((char **)c);
	}
	else
		return (ft_raw_atoi_fwd((char **)c));
	return (0);
}

int	format_picker(t_fmt *fmt, va_list *ap, int fd)
{
	if (fmt->conversion == 'c')
		return (print_char(fmt, (unsigned char)va_arg(*ap, int), fd));
	if (fmt->conversion == 's')
		return (print_str(fmt, (const char *)va_arg(*ap, int *), fd));
	if (fmt->conversion == 'p')
		return (print_ptr(fmt, va_arg(*ap, void *), fd));
	if (fmt->conversion == 'd' || fmt->conversion == 'i')
		return (print_int(fmt, va_arg(*ap, int), fd));
	if (fmt->conversion == 'o' || fmt->conversion == 'u'
		|| fmt->conversion == 'x' || fmt->conversion == 'X')
		return (print_unsigned(fmt, va_arg(*ap, unsigned int), fd));
	return (0);
}

t_fmt	*parse_format(unsigned char *c)
{
	t_fmt				*fmt;
	const unsigned char	*orig = c;
	static void			(*set_flag[])(t_fmt *)
		= {set_hash, set_zero, set_minus, set_space, set_plus};

	fmt = init_fmt();
	if (!fmt)
		return (NULL);
	while (ft_strchr_idx("#0- +", *(++c)) != -1)
		set_flag[ft_strchr_idx("#0- +", *c)](fmt);
	fmt->min_width = ft_raw_atoi_fwd((char **)&c);
	if (*c == '.')
	{
		c++;
		fmt->precision = parse_prec(&c);
	}
	fmt->conversion = *c;
	fmt->len = c - orig + 1;
	fix_format(&fmt);
	return (fmt);
}
