/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:46:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/04 12:55:37 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strchr_idx(const char *s, int c)
{
	unsigned char	*my_str;
	unsigned char	my_chr;
	size_t			count;

	count = 0;
	if (!s)
		return (-1);
	my_str = (unsigned char *)s;
	my_chr = (unsigned char)c;
	while (my_str[count] != my_chr)
	{
		if (my_str[count] == '\0')
			return (-1);
		count++;
	}
	return (count);
}
