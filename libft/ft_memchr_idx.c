/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:51:25 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/04 12:54:06 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	ft_memchr_idx(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*my_s;
	unsigned char	my_c;

	if (!s)
		return (0);
	my_s = (unsigned char *)s;
	my_c = (unsigned char)c;
	i = 0;
	while ((size_t) i < n)
	{
		if (my_s[i] == my_c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
