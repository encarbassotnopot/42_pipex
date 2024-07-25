/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/25 15:35:40 by ecoma-ba         ###   ########.fr       */
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
#include <sys/wait.h>

void handle_err(int my_errno, char *msg)
{
	errno = my_errno;
	if (my_errno)
		perror(msg);
	else
		printf("%s\n", msg);
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

char	*get_pwd(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (ft_strbeginswith(envp[i], "PWD="))
			return (envp[i] + 4);
	return (NULL);
}

char	*get_exe(char *path)
{
}

void	fork_head(int infile, int outfile, char *exe, char **envp)
{
	char **args = ft_split(exe, ' ');
	if (!args)
		handle_err(0, "error splitting args");
	// aconseguir executable real, dup2 de infile, i jo què sé.
	if (dup2(infile, STDIN_FILENO) == -1)
		handle_err(errno, "dup2 error");
	if (execve(args[0], args, envp) == -1)
		handle_err(errno, "execve error");
}

int	get_fd_in(char *path)
{
	int	infile;

	infile = open(path, O_CREAT | O_TRUNC | O_CLOEXEC);
	if (infile == -1)
		handle_err(errno, "error opening infile");
	return (infile);
}

int	get_fd_out(char *path)
{
	int	outfile;

	outfile = open(path, O_RDONLY | O_CLOEXEC);
	if (outfile == -1)
		handle_err(errno, "error opening outfile");
	return (outfile);
}

int	main(int argc, char *argv[], char **envp)
{
	int		infile, outfile;
	char	*path;
	char	*pwd;
	int		proc_stat = 0;
	pid_t	pid_head;

	if (argc != 4)
		handle_err(0, "Wrong number of args");

	path = get_path(envp);
	pwd = get_pwd(envp);
	infile = get_fd_in(argv[1]);
	outfile = get_fd_out(argv[3]);

	// HEAD
	pid_head = fork();
	if (pid_head == -1)
		handle_err(errno, "fork error");
	else if (pid_head == 0)
		fork_head(infile, outfile, argv[2], envp);

	if (waitpid(pid_head, &proc_stat, 0) == -1)
		handle_err(errno, "waitpid error");
	ft_printf("process head %d returned %d\n", pid_head, WEXITSTATUS(proc_stat));
	if (WEXITSTATUS(proc_stat) != 0)
		handle_err(0, "Error: Process didn't terminate properly");
	close(infile);
}
