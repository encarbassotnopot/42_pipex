/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:54:21 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/26 13:39:35 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	found_index;
	char	*my_big;
	char	*my_little;
	size_t	i;

	if (!big || !little)
		return (NULL);
	my_big = (char *)big;
	my_little = (char *)little;
	i = 0;
	while ((my_big[i] && i < len) || i == 0)
	{
		found_index = 0;
		while (my_big[i + found_index] == my_little[found_index]
			&& my_big[i + found_index] && my_little[found_index] && found_index
			+ i < len)
			found_index++;
		if (my_little[found_index] == '\0')
			return ((char *)(my_big + i));
		i++;
	}
	return (0);
}
