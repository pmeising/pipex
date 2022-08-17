/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:29:13 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/17 23:38:01 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// The program receives 4 arguments. Like so: "./pipex file1 cmd1 cmd2 file2"
// This syntax check function tries to open the arguments 1 and 4 which are 
// file path names. If the open fails (because the file doesn't exist) the 
// program throws an error.
// For the arguments 2 and 3, the expected input is a Shell command like "ls"
// or "cat" etc. Here we need to make sure, that this command actually
// represents a valid command with valid flags and syntaxes.
// The finding of the binary executables is done in here. If the binary does
// not exist, it means, that the command is not valid. 

// Here I find the correct variable from the "env" command and store it in a 
// single string.

char	*ft_find_path(t_prgrm *vars)
{
	int		i;
	char	*str;

	i = 0;
	while (vars->envp[i] != NULL)
	{
		str = ft_strnstr(vars->envp[i], "PATH=", 5);
		if (str != NULL)
			break ;
		i++;
	}
	return(vars->envp[i]);
}

// In this function I split the string into several directories by the de-
// limiter ":". This is then stored in a 2D array of strings.

char	**ft_find_paths(char *path)
{
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(path, ':');
	while (paths[i] != NULL)
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

// Here I make a "fake" file, by adding the cmd1 / cmd2 to the end of the
// file path. This way I then check if it is accessible using the access
// function. If it is, I found the correct directory, if it isn't, we have
// to keep iterating through the 2D array of strings.

char	*ft_locate_binaries(t_prgrm *vars, char *cmd, char **paths, int j)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	vars->main_commands = ft_split(cmd, ' ');
	len = ft_strlen(vars->main_commands[0]);
	if (vars->main_commands[1] != NULL)
		vars->arguments[j] = &cmd[len + 1];
	else
		vars->arguments[j] = NULL;
	// ft_printf("%s\n", vars->main_commands[1]);
	// ft_printf("cmd: %s, main: %s paths[i]: %s\n", cmd, vars->main_commands[0], paths[i]);
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], vars->main_commands[0]);
		// ft_printf("temp: %s\n", temp);
		if (access(temp, F_OK | X_OK) == 0)
		{
			// ft_printf("Found directory\n");
			return (temp);
		}
		free (temp);
		i++;
	}
	if (paths[i] == NULL)
		perror("Command not found: ");
	return (NULL);
}

void	ft_syntax_check(t_prgrm *vars)
{
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	vars->cmd_paths = calloc(3000, sizeof(char));
	vars->cmds = NULL;
	if (vars->argc != 5)
		perror("Invalid input syntax; number of args: ");
	vars->file_1 = open(vars->argv[1], O_RDWR);
	vars->file_2 = open(vars->argv[vars->argc - 1], O_RDWR);
	if (vars->file_1 == -1)
		perror("File 1 couldn't be opened: ");
	if (vars->file_2 == -1)
		perror("File 2 couldn't be opened: ");
	path = ft_find_path(vars); // Stores the PATH variable of env
	paths = ft_find_paths(path); // Stores each directory in a 2D array
	while ((i + 1) <= vars->argc - 3) // Limits the amount of calls to locate the binary to the amount of cmds in the function call arguments.
	{
		vars->cmd_paths[i] = ft_locate_binaries(vars, vars->argv[i + 2], paths, i);
		vars->cmd_args_ptr[i] = vars->main_commands;
		i++;
	}
	vars->cmd_paths[i] = NULL;
}
