/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raw_atoi_fwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:06:37 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/06 11:16:48 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_raw_atoi_fwd(char **str)
{
	int	result;

	if (!str)
		return (0);
	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		result *= 10;
		result += **str - '0';
		*str += 1;
	}
	return (result);
}
