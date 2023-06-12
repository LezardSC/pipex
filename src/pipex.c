/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezard <lezard@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:17:55 by lezard            #+#    #+#             */
/*   Updated: 2023/06/12 18:53:02 by lezard           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(t_pipex *param, char **args, pid_t *pids)
{
	execve(param->true_path, args, param->env);
	perror("Execve");
	wait_and_clean(param, NULL, 0);
	free_tab(args);
	free(pids);
	free(param->true_path);
	exit(EXIT_FAILURE);
}

static void	path_and_access(t_pipex *param, char *cmd, int i, pid_t *pids)
{
	char	**args;

	while (param->path[++i])
	{
		args = ft_split(cmd, ' ');
		if (!args)
			exit_failure_access(param, args, pids, 2);
		if (!args[0])
		{
			free_tab(args);
			break ;
		}
		if ((args[0][0] == '.' && args[0][1] == '/'))
		{
			execute_dot_slash(param, args, pids);
			break ;
		}
		access_path(param, args, pids, i);
	}
	command_not_found(param, pids);
}

static void	duplicate_file_fd(t_pipex *param)
{
	if (dup2(param->infile_fd, STDIN_FILENO) == -1)
	{
		wait_and_clean(param, NULL, 1);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(param->infile_fd);
	if (dup2(param->outfile_fd, STDOUT_FILENO) == -1)
	{
		wait_and_clean(param, NULL, 1);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(param->outfile_fd);
}

static void	run_command(t_pipex *param, pid_t *pids, char *cmd, int i)
{
	pids[i] = fork();
	if (pids[i] == -1)
	{
		wait_and_clean(param, NULL, 1);
		free(pids);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pids[i] == 0)
	{
		duplicate_file_fd(param);
		path_and_access(param, cmd, -1, pids);
	}
	else if (i == 0)
		close(param->infile_fd);
}

void	pipex(t_pipex *param, pid_t *pids, int i)
{
	while (++i < param->nb_cmds)
	{
		if (i == 0)
		{
			param->infile_fd = open(param->infile, O_RDONLY);
			if (param->infile_fd == -1)
			{
				wait_and_clean(param, NULL, 0);
				free(pids);
				perror(param->infile);
				continue ;
			}
		}
		else
			param->infile_fd = param->pipes[i - 1][0];
		pipex_process(param, pids, i);
		run_command(param, pids, param->cmds[i], i);
		if (i > 0)
			close(param->pipes[i - 1][0]);
		if (i < param->nb_cmds - 1)
			close(param->pipes[i][1]);
	}
	wait_and_clean(param, pids, 1);
}
