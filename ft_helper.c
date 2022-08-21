/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:44:52 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/21 20:08:43 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	ft_helper_0(t_prgrm *vars)
{
	ft_printf("%s: ", vars->argv[1]);
	ft_printf("No such file or directory\n");
	ft_printf("%s: ", vars->argv[vars->argc - 1]);
	ft_printf("No such file or directory\n");
}

void	ft_helper_1(t_prgrm *vars, char *cmd, int j)
{
	int		len;

	vars->main_commands = ft_split(cmd, ' ');
	len = ft_strlen(vars->main_commands[0]);
	if (vars->main_commands[1] != NULL)
		vars->arguments[j] = &cmd[len + 1];
	else
		vars->arguments[j] = NULL;
}

void	ft_helper_2(t_prgrm *vars, char **paths)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
	{
		free (paths[i]);
		i++;
	}
	free (paths);
	if (vars->eflag == 1)
		ft_error(vars, 0);
	else if (vars->eflag == 2)
		ft_error(vars, 7);
}

void	ft_helper_3(t_prgrm *vars, int *fds_old, int *fds_new, int i)
{
	if ((vars->i - i) > 0)
	{
		close(fds_old[0]);
		close(fds_old[1]);
	}
	if ((vars->i - i) < (vars->i - 1))
	{
		fds_old[0] = fds_new[0];
		fds_old[1] = fds_new[1];
	}
}

void	ft_helper_4(int *fds_new, int *fds_old)
{
	fds_new[0] = -1;
	fds_new[1] = -1;
	fds_old[0] = -1;
	fds_old[1] = -1;
}