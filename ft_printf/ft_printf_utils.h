/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:23:48 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 13:44:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include "ft_printf.h"
# include <stdarg.h>

int		ft_printf_fd(const char *format, va_list *ap, int fd);
t_fmt	*init_fmt(void);
t_fmt	*parse_format(unsigned char *c);
int		format_picker(t_fmt *fmt, va_list *ap, int fd);
int		format_str(unsigned char **str, va_list *ap, int fd);
int		traverse_str(unsigned char *str, va_list *ap, int fd);
int		ft_printf_fd(const char *format, va_list *ap, int fd);
t_fmt	*init_fmt(void);
t_fmt	*parse_format(unsigned char *c);
int		format_picker(t_fmt *fmt, va_list *ap, int fd);
int		format_str(unsigned char **str, va_list *ap, int fd);
void	pad(char **orig, char padding, size_t total_len, char side);
void	pad_spaces(t_fmt *fmt, char **orig);
void	pad_zeroes(t_fmt *fmt, char **orig);
int		print_int(t_fmt *fmt, int arg, int fd);
int		print_char(t_fmt *fmt, unsigned char arg, int fd);
int		print_str(t_fmt *fmt, const char *arg, int fd);
int		print_ptr(t_fmt *fmt, void *arg, int fd);
int		print_unsigned(t_fmt *fmt, unsigned int arg, int fd);
void	set_hash(t_fmt *fmt);
void	set_zero(t_fmt *fmt);
void	set_minus(t_fmt *fmt);
void	set_space(t_fmt *fmt);
void	set_plus(t_fmt *fmt);
void	pad(char **orig, char pad_ch, size_t total_len, char side);
void	pad_spaces(t_fmt *fmt, char **orig);
void	pad_zeroes(t_fmt *fmt, char **orig);
void	add_sign(t_fmt *fmt, char **orig);
char	*get_nbr_base(unsigned int num, char base);
#endif
