/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:51:25 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 09:43:40 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*my_s;
	unsigned char	my_c;

	if (!s)
		return (NULL);
	my_s = (unsigned char *)s;
	my_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (my_s[i] == my_c)
		{
			return ((&my_s[i]));
		}
		i++;
	}
	return (NULL);
}
