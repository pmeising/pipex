/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:11:36 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/17 23:41:04 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_initialize(t_prgrm *vars)
{
	vars->cmd_args_ptr = malloc(100);
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
	// ft_printf("Executables found.\n");
	ft_pipex(&vars);
	free (vars.main_commands);
	free (vars.cmd_paths);
	free (vars.cmds);
}
