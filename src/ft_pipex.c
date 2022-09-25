/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:37:53 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/25 17:06:47 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// I was able to pipe information from the child process to the parent process
// by writing into fds[1] and reading in the parent process in fds[0]. This way
// I can pass the output of the first execution on to the second process.
// Additionally, the parent process is waiting for the child process to finish
// before executing, which allows for the correct order of execution to occur.

void	ft_pipex(t_prgrm *vars)
{
	int	fds[2];
	int	pid;
	int	pipe_check;

	pipe_check = pipe(fds);
	if (pipe_check == -1)
		perror("Pipe failed: ");
	vars->fd_read_pipe = fds[0];
	vars->fd_write_pipe = fds[1];
	pid = fork();
	if (pid == 0)
	{
		ft_child_process_1(vars);
		vars->i--;
	}
	else
	{
		wait(NULL);
		ft_parent_process(vars);
	}
}
