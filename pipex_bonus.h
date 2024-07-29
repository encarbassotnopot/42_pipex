/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:54:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/29 13:07:15 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# define P_READ 0
# define P_WRITE 1

void	handle_err(int my_errno, char *msg);
char	*get_path(char **envp);
char	*get_exe(char *path, char *name);
void	fork_manager(int fd_in, int fd_out, char *exe, char **envp);
int		main(int argc, char *argv[], char **envp);
int		get_fd_in(char *path);
int		get_fd_out(char *path);
int		*fd_pair(int read, int write);
void	close_fds(int fd[]);
void	handle_err(int my_errno, char *msg);
char	*get_path(char **envp);
char	*get_exe(char *path, char *name);
#endif
