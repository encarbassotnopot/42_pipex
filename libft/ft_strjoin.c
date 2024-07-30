/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:25:15 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 18:11:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*src1;
	char			*src2;
	char			*dst;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	src1 = (char *)s1;
	src2 = (char *)s2;
	i = 0;
	while (*src1 != '\0')
	{
		dst[i] = *src1++;
		i++;
	}
	while (*src2 != '\0')
	{
		dst[i] = *src2++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
