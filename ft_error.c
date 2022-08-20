/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:46:38 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/20 23:06:46 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	ft_free_cmd_not_found(t_prgrm *vars)
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
	free (vars->cmd_paths);
	free(vars->arguments);

}

void	ft_error_free(t_prgrm *vars, int ecode)
{
	if (ecode == 1 || ecode == 2 || ecode == 3 || ecode == 4 || ecode == 5)
	{
		free(vars->cmd_args_ptr);
		free(vars->arguments);
	}
	if (ecode == 6)
	{
		ft_free_cmd_not_found(vars);
	}
}

void	ft_file_open(t_prgrm *vars, int ecode)
{
	if (ecode == 1)
	{
		ft_printf("%s: ", vars->argv[1]);
		perror("");
		ft_printf("%s: ", vars->argv[vars->argc - 1]);
		perror("");
	}
	if (ecode == 2)
	{
		ft_printf("%s: ", vars->argv[1]);
		perror("");
	}
	if (ecode == 3)
	{
		ft_printf("%s: ", vars->argv[vars->argc - 1]);
		perror("");
	}
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

void	ft_error(t_prgrm *vars, int ecode, int index)
{
	if (ecode == 1 || ecode == 2 || ecode == 3)
		ft_file_open(vars, ecode);
	else if (ecode == 4)
		ft_file_exist(vars, ecode);
	else if (ecode == 5)
	{
		ft_printf("Invalid syntax.\n");
		ft_error_free(vars, ecode);
	}
	else if (ecode == 6)
	{
		ft_printf("%s: ", vars->argv[index + 2]);
		ft_printf("command not found\n");
		ft_error_free(vars, ecode);
	}
	exit (0);
}
