/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:59:24 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/20 16:24:30 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// void	ft_pipex_bonus(t_prgrm *vars)
// {
// 	int	i;
// 	int	j;
// 	int	pid;
// 	int	pipe_check;

// 	// vars->fds = malloc(((vars->i - 1) * 2) * sizeof(int));
// 	i = vars->i;
// 	j = 0;
// 	while (i > 1)
// 	{
// 		pipe_check = pipe(&vars->fds[j]);
// 		if (pipe_check == -1)
// 			perror("Pipe failed: ");
// 		ft_printf("vars->fds[%d]: %d\n", j, vars->fds[j]);
// 		ft_printf("vars->fds[%d]: %d\n", j + 1, vars->fds[j + 1]);
// 		j = j + 2;
// 		i--;
// 	}
// 	i = vars->i + 1;
// 	while (i > 1)
// 	{
// 		i--;
// 		ft_printf("Hi about to fork:\n");
// 		pid = fork();
// 		wait(NULL);
// 		if (pid == -1)
// 			perror("Forking failed: ");
// 		if (pid == 0)
// 		{
// 			ft_printf("Forked %dst. time\n", ((vars->argc - 2) - i));
// 			ft_child_process(vars, ((vars->argc - 3) - i));
// 		}
// 		else
// 			ft_printf("In parent.\n");
// 	}
// 	if (vars->i == 0)
// 	{
// 		wait(NULL);
// 		ft_printf("We made it.\n");
// 	}
// 	else
// 		perror("Parent didn't execute.\n");
// }

// void	ft_child_process(t_prgrm *vars, int i)
// {
// 	ft_printf("Entering Child process.\n");
// 	if (i == 0)
// 	{
// 		ft_printf("Entered i == 0\n");
// 		dup2(vars->file_1, STDIN_FILENO);
// 		dup2(vars->fds[1], STDOUT_FILENO);
// 		ft_close_fds(vars);
// 	}
// 	else if (i == (vars->argc-4))
// 	{
// 		ft_printf("Hi am on last command. i == %d\n", i);
// 		dup2(vars->fds[0], 0);
// 		dup2(vars->file_2, 1);
// 		close(vars->file_1);
// 		close(vars->file_2);
// 		close(vars->fds[1]);
// 		// close(vars->fds[2]);
// 		close(vars->fds[0]);
// 		// ft_close_fds(vars);
// 	}
// 	else
// 	{
// 		ft_printf("i == %d middle cmd.\n", i);
// 		dup2(vars->fds[((i * 2) - 2)], 0);
// 		dup2(vars->fds[((i * 2) + 1)], 1);
// 		// close(vars->fds[4]);
// 		ft_close_fds(vars);
// 	}
// 	ft_printf("Executing command %d\n", i);
// 	execve(vars->cmd_paths[i], vars->cmd_args_ptr[i], vars->envp);
// 	perror("execve i: ");
// }

// void	ft_close_fds(t_prgrm *vars)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = vars->i;
// 	close(vars->file_1);
// 	close(vars->file_2);
// 	while (i > 1)
// 	{
// 		close(vars->fds[j]);
// 		close(vars->fds[j + 1]);
// 		j = j + 2;
// 		i--;
// 	}
// }

// void	ft_pipex_bonus_second_try(t_prgrm *vars)
// {
// 	int	fd_in[2];
// 	int	fd_out[2];
// 	int	i;
// 	int	pid;

// 	fd_in[0] = -1;
// 	fd_in[1] = -1;
// 	fd_out[0] = -1;
// 	fd_out[1] = -1;
// 	i = vars->i;
// 	if(pipe(fd_out) == - 1) // fd_out[0] = 5; fd_out[1] = 6
// 		perror("Piping: ");
// 	while (i > 0) // i = 3 // i == 2
// 	{
// 		pid = fork();
// 		if (pid < 0)
// 			perror("Forking failed:\n");
// 		if (pid == 0)
// 		{
// 			ft_printf("In child process %d\n", ((vars->argc - 3) - i));
// 			if (((vars->argc - 3) - i) == 0) // does not get executed a second time.
// 			{
// 				ft_printf("i == 0\n");
// 				dup2(vars->file_1, STDIN_FILENO);
// 				close(vars->file_1);
// 			}
// 			else if (fd_in[0] != -1) // assigns read from to the output from cmd1
// 			{
// 				ft_printf("Entered fd_in[0] != -1.\n");
// 				dup2(fd_in[1], STDOUT_FILENO);
// 				close(fd_in[1]);
// 				dup2(fd_in[0], STDIN_FILENO); //STDIN == 5
// 				close(fd_in[0]);
// 			}
// 			if (fd_out[0] != -1)
// 			{
// 				ft_printf("Entered fd_out[0] != -1.\n");
// 				close(fd_out[0]);
// 				dup2(fd_out[1], STDOUT_FILENO);
// 				close(fd_out[1]);
// 			}
// 			ft_printf("Executing a command: %d\n", ((vars->argc - 3) - i));
// 			if (execve(vars->cmd_paths[((vars->argc - 3) - i)], vars->cmd_args_ptr[((vars->argc - 3) - i)], vars->envp) == -1)
// 				perror("Execve: ");
// 		}
// 		fd_in[0] = fd_out[0]; // fd_in[0] = 5
// 		fd_in[1] = fd_out[1]; // fd_in[1] = 6
// 		fd_out[0] = -1;
// 		fd_out[1] = -1;
// 		// close(fd_in[0]);
// 		// close(fd_in[1]);
// 		i--;
// 		if (pid > 0)
// 			waitpid(pid, NULL, 0);
// 	}
// }

// void	ft_print_file()
// {
// 	char	*buffer;

// 	buffer = malloc(100);
// 	while (buffer != NULL)
// 	{
// 		buffer = malloc(100);
// 		buffer = get_next_line(0);
// 		ft_printf("%s", buffer);
// 		free(buffer);
// 	}
// }

// void	ft_child_process_bonus(t_prgrm *vars, int *pipe_fds, int i)
// {
// 	// FDs that are open in each iteration are: 
// 	// pipe_fds[0], pipe_fds[1], file1.txt, file2.txt, temp[0], temp[1]
// 	if (i == 0)
// 	{
// 		ft_printf("Entered first cmd.\n");
// 		close(vars->file_2);
// 		close(pipe_fds[0]);
// 		close(vars->file_2);
// 		close(vars->file_test);
// 		dup2(vars->file_1, STDIN_FILENO);
// 		ft_printf("Cmd input of i = %d\n", i);
// 		ft_print_file();
// 		dup2(pipe_fds[1], STDOUT_FILENO);
// 	}
// 	else if (i > 0 && i < (vars->i - 1))
// 	{
// 		ft_printf("Entering mid part.\n");
// 		close(vars->file_1);
// 		close(vars->file_2);
// 		close(pipe_fds[1]);
// 		close(vars->file_test2);
// 		close(vars->file_test);
// 		dup2(pipe_fds[0], STDIN_FILENO);
// 		ft_printf("Cmd input of i = %d\n", i);
// 		ft_print_file();
// 		dup2(pipe_fds[1], STDOUT_FILENO);
// 		if (execve(vars->cmd_paths[i], vars->cmd_args_ptr[i], vars->envp) == -1)
// 		perror("%d Execve: ");
// 	}
// 	else if (i == (vars->i - 1))
// 	{
// 		ft_printf("Entered last cmd.\n");
// 		close(vars->file_1);
// 		close(vars->file_test);
// 		close(pipe_fds[1]);
// 		close(vars->file_1);
// 		dup2(pipe_fds[0], STDIN_FILENO);
// 		ft_printf("Cmd input of i = %d\n", i);
// 		ft_print_file();
// 		dup2(vars->file_2, STDOUT_FILENO);
// 	}
// 	else
// 		perror("Assignment failed: ");
// 	// ft_printf("Trying to execute i == %d\n", i);
// 	if (execve(vars->cmd_paths[i], vars->cmd_args_ptr[i], vars->envp) == -1)
// 	perror("%d Execve: ");
// }

// void	ft_pipex_bonus_second_try(t_prgrm *vars)
// {
// 	int	*pipe_fds
// 	int	i;
// 	int	pid;

// 	vars->file_test = open("testingfile.txt", O_CREAT | O_RDWR, 0777);
// 	// vars->file_test2 = open("testingfile2.txt", O_CREAT | O_RDWR, 0777);
// 	// vars->file_test = open("testingfile3.txt", O_CREAT | O_RDWR, 0777);
// 	if (pipe(pipe_fds) == -1)
// 		perror("Pipe failed");
// 	// if (pipe(pipe_temp) == -1)
// 	// 	perror("Pipe failed");
// 	i = vars->i;
// 	while (i > 0)
// 	{
// 		pid = fork();
// 		if (pid == -1)
// 			perror("Forking failed: ");
// 		if (pid == 0)
// 		{
// 			ft_printf("We just created a child process\n");
// 			ft_child_process_bonus(vars, pipe_fds, ((vars->argc - 3) - i));
// 		}
// 		// waitpid(pid, NULL, 0);
// 		i--;
// 	}
// 	wait(NULL);
// 	close(pipe_fds[0]);
// 	close(pipe_fds[1]);
// 	close(vars->file_1);
// 	close(vars->file_2);
// 	ft_printf("We did it.\n");
// }

// can't write back to same pipe where you read from.
