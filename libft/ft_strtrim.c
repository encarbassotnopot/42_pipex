/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:57:36 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:51:22 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	size;
	unsigned int	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	size = 0;
	i = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	while (s1[start + i + size] != '\0')
	{
		if (ft_strchr(set, s1[start + size + i]))
			i++;
		else
		{
			size += i;
			i = 0;
			size++;
		}
	}
	return (ft_substr(s1, start, size));
}
