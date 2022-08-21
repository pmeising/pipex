/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:11:36 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/21 18:47:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_initialize(t_prgrm *vars)
{
	vars->cmd_args_ptr = malloc(100);
	vars->arguments = malloc(100);
	vars->eflag = 0;
	vars->file_1_nok = 0;
	vars->file_2_nok = 0;
}

void	ft_free(t_prgrm *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->i)
	{
		j = 0;
		while (vars->cmd_args_ptr[i][j] != NULL)
		{
			free(vars->cmd_args_ptr[i][j]);
			j++;
		}
		free(vars->cmd_args_ptr[i]);
		i++;
	}
	free (vars->cmd_args_ptr);
	i = 0;
	while (vars->cmd_paths[i] != NULL)
	{
		free (vars->cmd_paths[i]);
		i++;
	}
	free (vars->cmd_paths);
	free (vars->arguments);
}

int	main(int argc, char **argv, char **envp)
{
	t_prgrm	vars;

	vars.argc = argc;
	vars.argv = argv;
	vars.envp = envp;
	vars.i = argc - 3;
	ft_initialize(&vars);
	ft_syntax_check(&vars);
	ft_pipex(&vars);
	ft_free(&vars);
}
