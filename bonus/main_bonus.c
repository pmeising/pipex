/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:11:36 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/20 16:27:33 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_initialize(t_prgrm *vars)
{
	vars->cmd_args_ptr = malloc(100);
	vars->arguments = malloc(100);
}

void	ft_free(t_prgrm *vars)
{
	int	i;

	i = 0;
	// free (vars->argv); // invalid free
	// free (vars->envp); // invalid free
	// free (vars->cmds); // don't need cmds anymore.
	// free (vars->cmd_args); // invalid free
	while (vars->cmd_paths[i] != NULL)
	{
		free (vars->cmd_paths[i]);
		i++;
	}
	free (vars->cmd_paths);
	i = 0;
	while (vars->main_commands[i] != NULL)
	{
		free (vars->main_commands[i]);
		i++;
	}
	// i = 0;
	// while (vars->arguments[i] != NULL)
	// {
	// 	free (vars->arguments[i]);
	// 	i++;
	// }
	free (vars->arguments);
	free (vars->cmd_args_ptr);
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
	ft_printf("Executables found.\n");
	ft_pipex_bonus_third_try(&vars);
	ft_free(&vars);
}
