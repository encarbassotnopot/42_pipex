/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:28:04 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/23 12:02:48 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putabs_fd(unsigned int n, int fd)
{
	char	to_write;

	if (n >= 10)
		ft_putabs_fd(n / 10, fd);
	to_write = n % 10 + '0';
	write(fd, &to_write, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putabs_fd((unsigned int) ~(n - 1), fd);
	}
	else
		ft_putabs_fd((unsigned int)n, fd);
}
