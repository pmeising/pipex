/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:09:52 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/26 13:46:47 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	ft_helper_5(t_prgrm *vars, int i)
{
	execve(vars->cmd_paths[(vars->i - i)],
		vars->cmd_args_ptr[(vars->i - i)], vars->envp);
	perror("Execve didnt't execute.");
	exit (0);
}
