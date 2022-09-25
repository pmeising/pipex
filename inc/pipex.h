/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:11:56 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/25 20:16:30 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_prgrm
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**cmds;
	char	**cmd_paths;
	char	**main_commands;
	char	**arguments;
	char	**cmd_args;
	char	***cmd_args_ptr;
	int		file_1;
	int		file_2;
	int		file_1_nok;
	int		file_2_nok;
	int		fd_read_pipe;
	int		fd_write_pipe;
	int		i;
	int		*fds;
	int		file_test;
	int		file_test2;
	int		eflag;
	int		here_doc;
	int		fd_temp_file_heredoc;
	char	*DELIMITER;
}				t_prgrm;

// Mandatory part functions:

void	ft_syntax_check(t_prgrm *vars);
char	*ft_find_path(t_prgrm *vars);
char	**ft_find_paths(char *path);
char	*ft_locate_binaries(t_prgrm *vars, char *cmd, char **paths, int j);
char	*ft_cmd_as_path(t_prgrm *vars, int i);
void	ft_pipex(t_prgrm *vars);
void	ft_child_process_1(t_prgrm *vars);
void	ft_child_process_2(t_prgrm *vars);
void	ft_parent_process(t_prgrm *vars);
void	ft_child_process(t_prgrm *vars, int i);
void	ft_free(t_prgrm *vars);
void	ft_helper_0(t_prgrm *vars);
void	ft_helper_1(t_prgrm *vars, char *cmd, int j);
void	ft_helper_2(t_prgrm *vars, char **paths);
void	ft_helper_3(t_prgrm *vars, int *fds_old, int *fds_new, int i);
void	ft_helper_4(t_prgrm *vars, int i, int *fds_old, int *fds_new);
void	ft_helper_5(t_prgrm *vars, int i);

// ERROR handling

void	ft_error(t_prgrm *vars, int ecode);
void	ft_error_free(t_prgrm *vars, int ecode);

// BONUS functions

void	ft_syntax_check_bonus(t_prgrm *vars);
void	ft_pipex_bonus(t_prgrm *vars);

// // BONUS: HERE_DOC functions

void	ft_heredoc_check(t_prgrm *vars);
void	ft_heredoc(t_prgrm *vars);
void	ft_pipex_heredoc(t_prgrm *vars);

#endif