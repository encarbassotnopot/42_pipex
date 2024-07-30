/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:21:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/26 13:54:42 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*candidate;
	unsigned char	my_chr;

	if (!s)
		return (NULL);
	candidate = NULL;
	my_chr = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == my_chr)
			candidate = (char *)s;
		s++;
	}
	if (my_chr == '\0')
		return ((char *)s);
	return (candidate);
}
