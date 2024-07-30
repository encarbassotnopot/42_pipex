/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:27:59 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 13:16:02 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	if (!dst || !src)
		return (0);
	count = 0;
	while (src[count] != '\0' || count <= size)
	{
		if (count < size - 1 && size != 0)
			dst[count] = src[count];
		if (count == size && size != 0)
			dst[count - 1] = '\0';
		if (src[count] == '\0')
		{
			if (count < size)
				dst[count] = src[count];
			return (count);
		}
		count++;
	}
	return (count);
}
