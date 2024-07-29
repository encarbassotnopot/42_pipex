/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/29 13:09:16 by ecoma-ba         ###   ########.fr       */
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

void	do_fork(int fd_in, int fd_out, char *command, char **envp)
{
	pid_t	pid_child;

	pid_child = fork();
	if (pid_child == -1)
		handle_err(errno, "fork error");
	else if (pid_child == 0)
		fork_manager(fd_in, fd_out, command, envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int	files[2];
	int	**pipes;
	int	i;

	i = 2;
	pipes = ft_calloc(3, sizeof(int *));
	pipes[P_WRITE] = ft_calloc(3, sizeof(int));
	if (argc < 5)
		handle_err(0, "Wrong number of args");
	files[P_READ] = get_fd_in(argv[1]);
	files[P_WRITE] = get_fd_out(argv[argc - 1]);
	if (pipe(pipes[P_WRITE]) == -1)
		handle_err(errno, "pipe");
	do_fork(files[P_READ], pipes[P_WRITE][P_WRITE], argv[2], envp);
	while (++i <= argc - 2)
	{
		pipes[P_READ] = pipes[P_WRITE];
		// hauria de poder fer això
		close(pipes[P_READ][P_WRITE]);
		if (i == argc - 2)
			break ;
		pipes[P_WRITE] = ft_calloc(3, sizeof(int));
		if (pipe(pipes[P_WRITE]) == -1)
			handle_err(errno, "pipe");
		do_fork(pipes[P_READ][P_READ], pipes[P_WRITE][P_WRITE], argv[i], envp);
	}
	do_fork(pipes[P_READ][P_READ], files[P_WRITE], argv[argc - 2], envp);
}
