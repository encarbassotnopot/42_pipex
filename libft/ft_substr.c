/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:56:40 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/25 13:47:19 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	real_len(const char *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	unsigned int	s_start_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (0);
	s_start_len = s_len - start;
	if (s_start_len > len)
		return (len);
	return (s_start_len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*src;
	char			*dst;
	unsigned int	i;

	if (!s)
		return (NULL);
	src = (char *)s;
	len = real_len(s, start, len);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
