/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:21:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 13:16:19 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char			*my_str;
	unsigned char	my_chr;

	if (!s)
		return (NULL);
	my_str = (char *)s;
	my_chr = (unsigned char)c;
	while (*my_str != my_chr)
	{
		if (*my_str == '\0')
			return (NULL);
		my_str++;
	}
	return (my_str);
}
