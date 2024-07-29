/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/29 14:47:01 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	run_exe(char *command, char **envp)
{
	char	**args;
	char	*exe;
	int		my_errno;

	args = ft_split(command, ' ');
	if (!args)
		handle_err(0, "error splitting args");
	exe = get_exe(get_path(envp), args[0]);
	ft_printerr("exe is: %s\n", exe);
	execve(exe, args, envp);
	my_errno = errno;
	if (exe != args[0])
		free(exe);
	ft_free_arr((void **)args);
	handle_err(my_errno, "execve error");
}

/**
 * Manages a command in the chain and its fds and dups.
 */
void	fork_manager(int fd_in, int fd_out, char *command, char **envp)
{
	int	proc_stat;
	int	pid_exe;

	ft_printerr("command %s in: %d, out %d\n", command, fd_in, fd_out);
	if (dup2(fd_in, STDIN_FILENO) == -1)
		handle_err(errno, "dup2 error");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		handle_err(errno, "dup2 error");
	pid_exe = fork();
	if (pid_exe == -1)
		handle_err(errno, "fork error");
	if (pid_exe == 0)
		run_exe(command, envp);
	close(fd_in);
	close(fd_out);
	if (waitpid(pid_exe, &proc_stat, 0) == -1)
		handle_err(errno, "waitpid error");
	if (!WIFEXITED(proc_stat))
		handle_err(0, "Error: Process didn't terminate properly.");
	exit(EXIT_SUCCESS);
}

void	do_fork(int ***fds, char *command, char **envp)
{
	pid_t	pid_child;
	int		fd_in;
	int		fd_out;

	fd_in = (*fds)[P_READ][P_READ];
	fd_out = (*fds)[P_WRITE][P_WRITE];
	pid_child = fork();
	if (pid_child == -1)
		handle_err(errno, "fork error");
	else if (pid_child == 0)
	{
		/*if (fd_in[P_WRITE])*/
		/*	close(fd_in[P_WRITE]);*/
		/*if (fd_out[P_READ])*/
		/*	close(fd_out[P_READ]);*/
		close_pipe((*fds)[P_READ]);
		close_pipe((*fds)[P_WRITE]);
		ft_free_arr((void **)*fds);
		fork_manager(fd_in, fd_out, command, envp);
	}
	waitpid(pid_child, 0, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	int	**pipes;
	int	i;

	i = 1;
	if (argc < 5)
		handle_err(0, "Wrong number of args");
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
		close_pipe(pipes[P_READ]);
		free(pipes[P_READ]);
	}
	pipes[P_WRITE][P_WRITE] = get_fd_out(argv[argc - 1]);
	do_fork(&pipes, argv[argc - 2], envp);
	close_pipe(pipes[P_READ]);
	close_pipe(pipes[P_WRITE]);
	ft_free_arr((void **)pipes);
}
