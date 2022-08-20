/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_for_real_now.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:21:44 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/20 21:11:56 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// I can't reuse the same pipe, as writing and reading to the same pipe is
// not allowed.
// Therefore I'll use an array of ints, each pair of 2 holding a set of fds for 
// a pipe.
// The key here was to pipe in the while loop and eliminate potential issues
// with the fd array. :) 

// Comments for Lines:
// l. 48:  execute if there is a next cmd
// l. 59: execute if there is a previous command.
// l. 65: execute if there is no previous command
// l. 70: execute if there is a next command
// l. 76: execute if we reached the last command.
// l. 94: execute if there is a next command.

void	ft_pipex_bonus_third_try(t_prgrm *vars)
{
	int	i;
	int	fds_old[2];
	int	fds_new[2];
	int	pid;
	int	index;
	int	pipe_check;

	fds_new[0] = -1;
	fds_new[1] = -1;
	fds_old[0] = -1;
	fds_old[1] = -1;
	i = vars->i;
	ft_printf("vars->i: %d i: %d\n", vars->i, i);
	while (i > 0)
	{
		index = (vars->i - i);
		if (index < (vars->i - 1))
		{
			pipe_check = pipe(fds_new);
			if (pipe_check == -1)
				perror("Pipe failed.");
		}
		pid = fork();
		if (pid == -1)
			perror("Fork failed.");
		if (pid == 0)
		{
			if (index > 0)
			{
				dup2((fds_old[0]), STDIN_FILENO);
				close(fds_old[0]);
				close(fds_old[1]);
			}
			else
			{
				dup2(vars->file_1, STDIN_FILENO);
				close(vars->file_1);
			}
			if (index < (vars->i - 1))
			{
				close(fds_new[0]);
				dup2(fds_new[1], STDOUT_FILENO);
				close(fds_new[1]);
			}
			else
			{
				close(fds_new[0]);
				close(fds_new[1]);
				dup2(vars->file_2, STDOUT_FILENO);
				close(vars->file_2);
			}
			execve(vars->cmd_paths[index], vars->cmd_args_ptr[index], vars->envp);
			perror("Execve didnt't execute.");
			exit (0);
		}
		else
		{
			if (index > 0)
			{
				close(fds_old[0]);
				close(fds_old[1]);
			}
			if (index < (vars->i - 1))
			{
				fds_old[0] = fds_new[0];
				fds_old[1] = fds_new[1];
			}
		}
		i--;
	}
	close(fds_old[0]);
	close(fds_old[1]);
}