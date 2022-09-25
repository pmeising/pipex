/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:07:46 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/25 20:44:23 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// ll. 24. It should be O_APPEND I believe, otherwise it would overwrite each line with the last one, which would end up in an incorrect input for the first command.

void	ft_pipex_heredoc(t_prgrm *vars)
{
	int		check;
	char	*line;

	vars->fd_temp_file_heredoc = open("temp.txt", O_CREAT| O_WRONLY | O_TRUNC, 0644);
	if (vars->fd_temp_file_heredoc == -1)
		ft_error(vars, 9);
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(0);
		if (ft_strncmp(line, vars->DELIMITER, ft_strlen(vars->DELIMITER)) == 0)
		{
			free(line);
			break;
		}
		else
		{
			check = write(vars->fd_temp_file_heredoc, line, ft_strlen(line));
			if (check == -1)
				ft_error(vars, 10);
			free(line);
		}
	}
	close(vars->fd_temp_file_heredoc);
	vars->fd_temp_file_heredoc = open("temp.txt", O_RDONLY);
	ft_pipex_bonus(vars);
}
