/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:15:11 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/09 16:14:04 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

void	pad(char **orig, char pad_ch, size_t total_len, char side)
{
	char	*new;
	char	*pad;
	size_t	orig_len;
	size_t	pad_len;

	orig_len = ft_strlen(*orig);
	pad_len = total_len - orig_len;
	pad = ft_calloc(pad_len + 1, sizeof(char));
	if (!pad)
	{
		free(*orig);
		*orig = NULL;
		return ;
	}
	ft_memset(pad, pad_ch, pad_len);
	if (side == 'l')
		new = ft_strjoin(pad, *orig);
	else
		new = ft_strjoin(*orig, pad);
	free(*orig);
	free(pad);
	*orig = new;
}

void	pad_spaces(t_fmt *fmt, char **orig)
{
	if (fmt->min_width > (int)ft_strlen(*orig))
	{
		if (fmt->padding == '-')
			pad(orig, ' ', fmt->min_width, 'r');
		else if (fmt->padding == '\0')
			pad(orig, ' ', fmt->min_width, 'l');
	}
}

void	pad_zeroes(t_fmt *fmt, char **orig)
{
	int	len;

	len = ft_strlen(*orig);
	if (fmt->precision > len)
	{
		len = fmt->precision;
		pad(orig, '0', fmt->precision, 'l');
	}
	if (fmt->alternate == '#')
	{
		if (ft_strchr_idx("xX", fmt->conversion) != -1)
		{
			pad(orig, '0', len + 2, 'l');
			(*orig)[1] = fmt->conversion;
		}
		else if (fmt->conversion == 'o' && **orig != '0')
			pad(orig, '0', len + 1, 'l');
	}
}

void	add_sign(t_fmt *fmt, char **orig)
{
	if (fmt->sign)
		pad(orig, fmt->sign, ft_strlen(*orig) + 1, 'l');
}

char	*get_nbr_base(unsigned int num, char base)
{
	if (base == 'o')
		return (ft_utoa_base(num, "01234567"));
	if (base == 'u')
		return (ft_utoa_base(num, "0123456789"));
	if (base == 'x')
		return (ft_utoa_base(num, "0123456789abcdef"));
	if (base == 'X')
		return (ft_utoa_base(num, "0123456789ABCDEF"));
	return (NULL);
}
