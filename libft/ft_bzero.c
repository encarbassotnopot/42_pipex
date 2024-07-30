/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:45:03 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:19:17 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*my_ptr;

	if (!ptr)
		return ;
	i = 0;
	my_ptr = ptr;
	while (i < n)
	{
		my_ptr[i++] = 0;
	}
}
