/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/22 16:28:30 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

extern char	**environ;

int	main(int argc, char *argv[])
{
	char	**envp;
	int		i;

	envp = environ;
	i = -1;
	while (++i < argc)
		ft_printf("argv[%d]: %s\n", i, argv[i]);
	i = -1;
	while (envp[++i])
		ft_printf("envp[%d]: %s\n", i, envp[i]);
}
