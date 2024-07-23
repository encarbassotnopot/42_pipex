/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/23 14:52:26 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	**get_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (ft_strbeginswith(envp[i], "PATH="))
			return (ft_split(envp[i] + 5, ':'));
	return (NULL);
}

char	*get_pwd(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (ft_strbeginswith(envp[i], "PWD="))
			return (envp[i] + 4);
	return (NULL);
}

char *get_exe();

int fork_head()
{
	// aconseguir executable real, dup2 de infile, i jo què sé.
	
}

int	main(int argc, char *argv[], char **envp)
{
	int		i;
	int		infile;
	char	*buf;
	int		r;

	i = -1;
	while (++i < argc)
		ft_printf("argv[%d]: %s\n", i, argv[i]);
	if (argc != 3)
	{
		ft_printf("Not enough args\n");
		exit(-1);
	}
	char **path = get_path(envp);
	i = -1;
	if (path)
		while (path[++i])
			ft_printf("PATH: %s\n", path[i]);
	char *pwd = get_pwd(envp);
	if (pwd)
		ft_printf("PWD: %s\n", pwd);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror(NULL);
		exit(errno);
	}
	close(infile);
}
