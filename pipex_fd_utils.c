/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:50:00 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 17:21:49 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd_in(char *path)
{
	int	infile;

	infile = open(path, O_RDONLY);
	if (infile == -1)
		perror("error opening infile");
	return (infile);
}

int	get_fd_out(char *path)
{
	int	outfile;

	outfile = open(path, O_CREAT | O_TRUNC | O_WRONLY,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (outfile == -1)
		perror("error opening outfile");
	return (outfile);
}

int	*fd_pair(int read, int write)
{
	int	*pair;

	pair = ft_calloc(2, sizeof(int));
	if (!pair)
		handle_err(ENOMEM, 0);
	pair[0] = read;
	pair[1] = write;
	return (pair);
}

void	close_fds(int fd[])
{
	if (close(fd[0]) == -1)
		perror("error closing fd[0]");
	if (close(fd[1]) == -1)
		perror("error closing fd[1]");
}
