/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sttoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:38 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/08 17:24:21 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_str_size(size_t n, unsigned int radix)
{
	int	len;

	len = 1;
	while (n >= radix)
	{
		n /= radix;
		len++;
	}
	return (len);
}

char	*ft_sttoa_base(size_t n, const char *base)
{
	char	*out;
	size_t	radix;
	int		len;

	radix = ft_strlen(base);
	len = get_str_size(n, radix);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (len > 0)
	{
		out[--len] = base[n % radix];
		n /= radix;
	}
	return (out);
}
