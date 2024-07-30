/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:56:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 13:43:38 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include "ft_printf.h"

typedef struct s_fmt
{
	char	alternate;
	char	padding;
	char	sign;
	int		min_width;
	int		precision;
	char	conversion;
	size_t	len;
}			t_fmt;

int			ft_fprintf(int fd, const char *format, ...);
int			ft_printerr(const char *format, ...);
int			ft_printf(const char *format, ...);
#endif
