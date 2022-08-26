/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:46:38 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/26 13:49:50 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	ft_free_cmd_not_found_1(t_prgrm *vars)
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
	i = 0;
	while (i < vars->i)
	{
		free(vars->cmd_paths[i]);
		i++;
	}
	free(vars->cmd_paths);
	free(vars->arguments);
	free(vars->cmd_args_ptr);
}

void	ft_error_free(t_prgrm *vars, int ecode)
{
	if (ecode == 1 || ecode == 2 || ecode == 3 || ecode == 4 || ecode == 5)
	{
		free(vars->cmd_args_ptr);
		free(vars->arguments);
	}
	if (ecode == 6 || ecode == 0 || ecode == 7)
	{
		ft_free_cmd_not_found_1(vars);
	}
}

void	ft_file_open(t_prgrm *vars, int ecode)
{
	ft_error_free(vars, ecode);
}

void	ft_file_exist(t_prgrm *vars, int ecode)
{
	if (ecode == 4)
	{
		ft_printf("%s: ", vars->argv[1]);
		perror("");
	}
	ft_error_free(vars, ecode);
}

void	ft_error(t_prgrm *vars, int ecode)
{
	if (ecode == 0)
		ft_file_open(vars, ecode);
	else if (ecode == 1 || ecode == 2 || ecode == 3)
		ft_file_open(vars, ecode);
	else if (ecode == 4)
		ft_file_exist(vars, ecode);
	else if (ecode == 5)
	{
		ft_printf("Invalid syntax.\n");
		ft_error_free(vars, ecode);
	}
	else if (ecode == 6)
		ft_error_free(vars, ecode);
	else if (ecode == 7)
		ft_error_free(vars, ecode);
	exit (0);
}
