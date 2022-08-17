/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:50:04 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/17 23:56:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process_1(t_prgrm *vars)
{
	// ft_printf("Entering child process 1.\n");
	dup2(vars->file_1, 0); // STDIN is now coming from file1.txt
	dup2(vars->fd_write_pipe, 1); // STDOUT is now going to the write-end of the pipe.
	// ft_printf("changed STDIN and STDOUT.\n");
	close(vars->fd_read_pipe);
	close(vars->file_2);
	close(vars->fd_write_pipe);
	// ft_printf("Still going.\n");
	execve(vars->cmd_paths[0], vars->cmd_args_ptr[0], vars->envp);
	perror("execve 1: ");
}

void	ft_child_process_2(t_prgrm *vars)
{
	// ft_printf("Entered child 2\n");
	dup2(vars->fd_read_pipe, 0);
	dup2(vars->file_2, 1);
	close(vars->fd_read_pipe);
	close(vars->fd_write_pipe);
	close(vars->file_1);
	close(vars->file_2);
	execve(vars->cmd_paths[1], vars->cmd_args_ptr[1], vars->envp);
	perror("execve 2: ");
}
