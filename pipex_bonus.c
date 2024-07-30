/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/30 12:50:27 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	run_exe(char *command, char **envp, int fds[])
{
	char	**args;
	char	*exe;
	int		my_errno;

	args = ft_split(command, ' ');
	if (!args)
	{
		handle_err(0, "error splitting args");
		close_pipe(fds);
	}
	exe = get_exe(get_path(envp), args[0]);
	if (!exe)
	{
		close_pipe(fds);
		ft_printerr("command not found: %s\n", args[0]);
		ft_free_arr((void **)args);
		exit(EXIT_FAILURE);
	}
	execve(exe, args, envp);
	my_errno = errno;
	close_pipe(fds);
	if (exe != args[0])
		free(exe);
	ft_free_arr((void **)args);
	handle_err(my_errno, "execve error");
}

/**
 * Manages a command in the chain and its fds and dups.
 */
void	fork_manager(int fds[], char *command, char **envp)
{
	int	proc_stat;
	int	pid_exe;

	if (fds[P_READ] > 0 && dup2(fds[P_READ], STDIN_FILENO) == -1)
		perror("dup2 error");
	if (fds[P_WRITE] > 0 && dup2(fds[P_WRITE], STDOUT_FILENO) == -1)
		perror("dup2 error");
	pid_exe = fork();
	if (pid_exe == -1)
		handle_err(errno, "fork error");
	if (pid_exe == 0)
		run_exe(command, envp, fds);
	close_pipe(fds);
	if (waitpid(pid_exe, &proc_stat, 0) == -1)
		handle_err(errno, "waitpid error");
	exit(EXIT_SUCCESS);
}

void	do_fork(int ***fds, char *command, char **envp)
{
	pid_t	pid_child;
	int		my_fds[2];

	my_fds[P_READ] = (*fds)[P_READ][P_READ];
	my_fds[P_WRITE] = (*fds)[P_WRITE][P_WRITE];
	pid_child = fork();
	if (pid_child == -1)
		handle_err(errno, "fork error");
	else if (pid_child == 0)
	{
		if ((*fds)[P_WRITE][P_READ] > 0)
			close((*fds)[P_WRITE][P_READ]);
		if ((*fds)[P_READ][P_WRITE] > 0)
			close((*fds)[P_READ][P_WRITE]);
		ft_free_arr((void **)*fds);
		fork_manager(my_fds, command, envp);
		close_pipe((*fds)[P_READ]);
		close_pipe((*fds)[P_WRITE]);
	}
	else
	{
		close_pipe(pipes[P_READ]);
		free(pipes[P_READ]);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	**pipes;
	int	i;

	i = 1;
	if (argc < 5)
		handle_err(0, "wrong number of args");
	pipes = ft_calloc(3, sizeof(int *));
	pipes[P_WRITE] = ft_calloc(3, sizeof(int));
	pipes[P_WRITE][P_READ] = get_fd_in(argv[1]);
	while (++i <= argc - 2)
	{
		pipes[P_READ] = pipes[P_WRITE];
		pipes[P_WRITE] = ft_calloc(3, sizeof(int));
		if (i == argc - 2)
			break ;
		if (pipe(pipes[P_WRITE]) == -1)
			handle_err(errno, "pipe");
		do_fork(&pipes, argv[i], envp);
	}
	pipes[P_WRITE][P_WRITE] = get_fd_out(argv[argc - 1]);
	do_fork(&pipes, argv[argc - 2], envp);
	close_pipe(pipes[P_READ]);
	close_pipe(pipes[P_WRITE]);
	ft_free_arr((void **)pipes);
}
