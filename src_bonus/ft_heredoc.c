/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:29:23 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/25 20:42:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_heredoc(t_prgrm *vars)
{
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	if (vars->argc != 6)
		ft_error(vars, 8);
	vars->file_2 = open(vars->argv[vars->argc - 1], O_CREAT | O_RDWR | O_APPEND,
			0777);
	vars->cmd_paths = malloc(10000);
	path = ft_find_path(vars);
	paths = ft_find_paths(path);
	while (i < 2)
	{
		vars->cmd_paths[i] = ft_locate_binaries(vars, vars->argv[i + 3],
				paths, i);
		if (vars->eflag == 1)
			free(vars->cmd_paths[i]);
		vars->cmd_args_ptr[i] = vars->main_commands;
		i++;
	}
	vars->cmd_paths[i] = NULL;
	ft_helper_2(vars, paths);
}

void	ft_heredoc_check(t_prgrm *vars)
{
	if (ft_strnstr(vars->argv[1], "here_doc", 8) == NULL)
	{
		vars->here_doc = 0;
		vars->DELIMITER = "END";
		return ;
	}
	vars->here_doc = 1;
	vars->DELIMITER = vars->argv[2];
}
