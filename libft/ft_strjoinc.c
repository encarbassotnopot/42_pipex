/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:25:15 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 12:47:58 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoinc(const char *s1, const char *s2, char c)
{
	char			*src1;
	char			*src2;
	char			*dst;
	unsigned int	i;

	if (!s1 || !s2 || !c)
		return (NULL);
	dst = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 2, sizeof(char));
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
	dst[i++] = c;
	while (*src2 != '\0')
	{
		dst[i] = *src2++;
		i++;
	}
	return (dst);
}
