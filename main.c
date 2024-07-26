/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 14:38:14 by ecoma-ba         ###   ########.fr       */
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
void	fork_manager(int fds[], char *command, char **envp)
{
	int	proc_stat;
	int	pid_exe;

	if (dup2(fds[0], STDIN_FILENO) == -1)
		handle_err(errno, "dup2 error");
	if (dup2(fds[1], STDOUT_FILENO) == -1)
		handle_err(errno, "dup2 error");
	pid_exe = fork();
	if (pid_exe == -1)
		handle_err(errno, "fork error");
	if (pid_exe == 0)
		run_exe(command, envp);
	if (waitpid(pid_exe, &proc_stat, 0) == -1)
	{
		close_fds(fds);
		handle_err(errno, "waitpid error");
	}
	close_fds(fds);
	ft_printerr("process exe %d returned %d\n", pid_exe,
		WEXITSTATUS(proc_stat));
	if (!WIFEXITED(proc_stat))
		handle_err(0, "Error: Process didn't terminate properly");
	exit(EXIT_SUCCESS);
}

void	head(char **argv, char **envp, int pair[])
{
	int		proc_stat;
	pid_t	pid_head;

	pid_head = fork();
	if (pid_head == -1)
		handle_err(errno, "fork error");
	else if (pid_head == 0)
		fork_manager(pair, argv[2], envp);
	if (waitpid(pid_head, &proc_stat, 0) == -1)
		handle_err(errno, "waitpid error");
	ft_printerr("process head %d returned %d\n", pid_head,
		WEXITSTATUS(proc_stat));
	if (!WIFEXITED(proc_stat))
		handle_err(0, "Error: Process didn't terminate properly");
}

void	tail(char **argv, char **envp, int pair[])
{
	int		proc_stat;
	pid_t	pid_head;

	pid_head = fork();
	if (pid_head == -1)
		handle_err(errno, "fork error");
	else if (pid_head == 0)
		fork_manager(pair, argv[3], envp);
	if (waitpid(pid_head, &proc_stat, 0) == -1)
		handle_err(errno, "waitpid error");
	ft_printerr("process head %d returned %d\n", pid_head,
		WEXITSTATUS(proc_stat));
	if (!WIFEXITED(proc_stat))
		handle_err(0, "Error: Process didn't terminate properly");
}

int	main(int argc, char *argv[], char **envp)
{
	int	*pairs[2];
	int	pipefd[2];

	if (argc != 5)
		handle_err(0, "Wrong number of args");
	if  (pipe(pipefd) == -1)
		handle_err(errno, "pipe");
	pairs[0] = fd_pair(get_fd_in(argv[1]), pipefd[1]);
	pairs[1] = fd_pair(pipefd[0], get_fd_out(argv[4]));
	head(argv, envp, pairs[0]);
	tail(argv, envp, pairs[1]);
	close_fds(pairs[0]);
	close_fds(pairs[1]);
}
