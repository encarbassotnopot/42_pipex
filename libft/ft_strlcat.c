/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:25:17 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:50:17 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	index;
	unsigned int	dest_len;

	if (!dest || !src)
		return (0);
	index = 0;
	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	while (src[index] != '\0' || index < size + dest_len)
	{
		if (index + dest_len + 1 < size)
			(&dest[dest_len])[index] = src[index];
		if (index + dest_len + 1 == size && size != 0)
			(&dest[dest_len])[index] = '\0';
		if (src[index] == '\0')
			break ;
		index++;
	}
	return (index + dest_len);
}
