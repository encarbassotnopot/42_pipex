/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbeginswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:45:37 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/23 14:00:24 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strbeginswith(const char *big, const char *little)
{
	size_t	found_index;

	if (!big || !little)
		return (0);
	big = (char *)big;
	little = (char *)little;
	found_index = 0;
	while (big[found_index] == little[found_index] && big[found_index]
		&& little[found_index])
		found_index++;
	if (little[found_index] == '\0')
		return (1);
	return (0);
}
