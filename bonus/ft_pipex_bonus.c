/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:21:44 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/26 13:46:49 by pmeising         ###   ########.fr       */
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

void	ft_pipex_bonus(t_prgrm *vars)
{
	int	i;
	int	fds_old[2];
	int	fds_new[2];
	int	pid;
	int	pipe_check;

	i = vars->i;
	while (i > 0)
	{
		if ((vars->i - i) < (vars->i - 1))
		{
			pipe_check = pipe(fds_new);
			if (pipe_check == -1)
				perror("Pipe failed.");
		}
		pid = fork();
		if (pid == -1)
			perror("Fork failed.");
		if (pid == 0)
			ft_helper_4(vars, i, fds_old, fds_new);
		ft_helper_3(vars, fds_old, fds_new, i);
		i--;
	}
	close(fds_old[0]);
	close(fds_old[1]);
}
