/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:49:50 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/26 13:50:40 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Reading fds[0]. Child wrote to fds[1], it was piped here.

void	ft_parent_process(t_prgrm *vars)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror("forking: ");
	else if (pid == 0)
	{
		ft_child_process_2(vars);
	}
	else
	{
		close(vars->file_1);
		close(vars->file_2);
		close(vars->fd_read_pipe);
		close(vars->fd_write_pipe);
	}
	return ;
}
