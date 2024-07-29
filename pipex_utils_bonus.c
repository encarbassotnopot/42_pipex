/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:50:00 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/29 10:50:03 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_err(int my_errno, char *msg)
{
	errno = my_errno;
	if (my_errno)
		perror(msg);
	else
		ft_printerr("%s\n", msg);
	exit(EXIT_FAILURE);
}

char	*get_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (ft_strbeginswith(envp[i], "PATH="))
			return (envp[i] + 5);
	return (NULL);
}

char	*get_exe(char *path, char *name)
{
	char	**paths;
	char	*file;
	int		i;

	i = -1;
	if (ft_strchr(name, '/'))
		return (name);
	paths = ft_split(path, ':');
	if (!paths)
		handle_err(0, "Error spliting path");
	while (paths[++i])
	{
		file = ft_strjoinc(paths[i], name, '/');
		if (access(file, X_OK) == 0)
			break ;
	}
	if (!paths[i])
		file = NULL;
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (file);
}
