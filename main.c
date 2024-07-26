/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:14 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/26 12:17:31 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_head(int infile, int outfile, char *command, char **envp)
{
	char	**args;
	char	*exe;
	int		my_errno;

	args = ft_split(command, ' ');
	if (!args)
		handle_err(0, "error splitting args");
	ft_printf("testing fds 1\n");
	if (dup2(infile, STDIN_FILENO) == -1)
		handle_err(errno, "dup2 error");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		handle_err(errno, "dup2 error");
	exe = get_exe(get_path(envp), args[0]);
	printf("exe is: %s\n", exe);
	execve(exe, args, envp);
	my_errno = errno;
	if (exe != args[0])
		free(exe);
	ft_free_arr((void **) args);
	handle_err(my_errno, "execve error");
}

int	main(int argc, char *argv[], char **envp)
{
	int		proc_stat;
	pid_t	pid_head;

	int infile, outfile;
	proc_stat = 0;
	if (argc != 4)
		handle_err(0, "Wrong number of args");
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
	ft_printf("process head %d returned %d\n", pid_head,
		WEXITSTATUS(proc_stat));
	if (!WIFEXITED(proc_stat))
		handle_err(0, "Error: Process didn't terminate properly");
}
