/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:12:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 09:49:00 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		index;
	const unsigned char	*my_s1;
	const unsigned char	*my_s2;

	if (!s1 || !s2)
		return (0);
	my_s1 = (const unsigned char *)s1;
	my_s2 = (const unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (my_s1[index] != my_s2[index])
		{
			return (my_s1[index] - my_s2[index]);
		}
		index++;
	}
	return (0);
}
