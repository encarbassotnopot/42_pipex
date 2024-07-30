/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:50:27 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 13:43:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = ft_printf_fd(format, &ap, fd);
	va_end(ap);
	return (count);
}

int	ft_printerr(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = ft_printf_fd(format, &ap, 2);
	va_end(ap);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = ft_printf_fd(format, &ap, 1);
	va_end(ap);
	return (count);
}
