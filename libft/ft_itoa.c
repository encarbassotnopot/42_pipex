/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:38 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 16:38:33 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_str_size(int n)
{
	size_t	len;

	len = 2;
	if (n < 0)
	{
		len++;
	}
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*out;
	unsigned int	abs;
	size_t			len;

	len = get_str_size(n);
	out = malloc(len);
	if (!out)
		return (NULL);
	out[--len] = '\0';
	abs = n;
	if (n < 0)
	{
		out[0] = '-';
		abs = ~(n - 1);
	}
	while (abs >= 10)
	{
		out[--len] = '0' + (abs % 10);
		abs /= 10;
	}
	out[--len] = '0' + (abs % 10);
	return (out);
}
