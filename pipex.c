/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 17:28:29 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
void	fork_manager(int fd_in[], int fd_out[], char *command, char **envp)
{
	int	proc_stat;
	int	pid_exe;

	close(fd_in[1]);
	close(fd_out[0]);
	if (dup2(fd_in[0], STDIN_FILENO) == -1)
		handle_err(errno, "dup2 error");
	if (dup2(fd_out[1], STDOUT_FILENO) == -1)
		handle_err(errno, "dup2 error");
	pid_exe = fork();
	if (pid_exe == -1)
		handle_err(errno, "fork error");
	if (pid_exe == 0)
		run_exe(command, envp);
	close(fd_in[0]);
	close(fd_out[1]);
	if (waitpid(pid_exe, &proc_stat, 0) == -1)
		handle_err(errno, "waitpid error");
	ft_printerr("process exe %d returned %d\n", pid_exe,
		WEXITSTATUS(proc_stat));
	if (!WIFEXITED(proc_stat))
		handle_err(0, "Error: Process didn't terminate properly");
	exit(EXIT_SUCCESS);
}

void	do_fork(int fd_in[], int fd_out[], char *command, char **envp)
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
	int	pipefd[2];

	if (argc != 5)
		handle_err(0, "Wrong number of args");
	files[0] = get_fd_in(argv[1]);
	files[1] = get_fd_out(argv[4]);
	if (pipe(pipefd) == -1)
		handle_err(errno, "pipe");
	do_fork(files, pipefd, argv[2], envp);
	do_fork(pipefd, files, argv[3], envp);
}
