/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:06:37 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 13:17:06 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	result;
	char			*my_str;

	if (!str)
		return (0);
	my_str = (char *)str;
	sign = 1;
	result = 0;
	while ((*my_str >= 9 && *my_str <= 13) || *my_str == ' ')
		my_str++;
	if (*my_str == '+' || *my_str == '-')
	{
		if (*my_str == '-')
			sign *= -1;
		my_str++;
	}
	while (*my_str >= '0' && *my_str <= '9')
	{
		result *= 10;
		result += *my_str - '0';
		my_str++;
	}
	return (sign * (int)result);
}
