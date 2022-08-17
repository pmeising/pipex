/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:11:56 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/17 23:40:37 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include "./libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_prgrm
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**cmds; // "ls -la"
	char	**cmd_paths; // "/usr/bin/cat/"
	char	**main_commands; // "ls" "cat" without any command arguments.r
	char	**arguments;
	char	**cmd_args;
	char	***cmd_args_ptr;
	int		file_1;
	int		file_2;
	int		fd_read_pipe;
	int		fd_write_pipe;
	int		i;
}				t_prgrm;

// First try functions:

void	ft_syntax_check(t_prgrm *vars);
void	ft_pipex(t_prgrm *vars);
void	ft_child_process_1(t_prgrm *vars);
void	ft_child_process_2(t_prgrm *vars);
void	ft_parent_process(t_prgrm *vars);

#endif