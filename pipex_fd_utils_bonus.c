/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fd_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:50:00 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/30 11:47:05 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	close_pipe(int *fd)
{
	int	i;

	i = -1;
	while (++i < 2)
		if (fd[i] > 0)
			if (close(fd[i]) == -1)
				perror("error closing fd");
}
