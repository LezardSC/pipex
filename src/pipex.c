/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:17:55 by lezard            #+#    #+#             */
/*   Updated: 2023/07/11 13:41:44 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(t_pipex *param, char **args)
{
	execve(param->true_path, args, param->env);
	perror("Execve");
	wait_and_clean(param, 0, 0);
	free_tab(args);
	free(param->true_path);
	exit(EXIT_FAILURE);
}

static void	path_and_access(t_pipex *param, char *cmd, int i)
{
	char	**args;

	if (!param->path)
	{
		args = ft_split(cmd, ' ');
		if (!args)
			exit_failure_access(param, args, 2);
		access_cmd(param, args, i);
	}
	while (param->path[++i])
	{
		args = ft_split(cmd, ' ');
		if (!args)
			exit_failure_access(param, args, 2);
		if (!args[0])
		{
			free_tab(args);
			break ;
		}
		access_cmd(param, args, i);
	}
	command_not_found(param, cmd);
}

static void	duplicate_file_fd(t_pipex *param)
{
	if (dup2(param->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		wait_and_clean(param, 0, 1);
		exit(EXIT_FAILURE);
	}
	if (param->infile_fd != -1)
		close(param->infile_fd);
	if (dup2(param->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		wait_and_clean(param, 0, 1);
		exit(EXIT_FAILURE);
	}
	if (param->outfile_fd != -1)
		close(param->outfile_fd);
}

static void	run_command(t_pipex *param, char *cmd, int i)
{
	if (param->pids[i] == -1)
	{
		perror("fork");
		wait_and_clean(param, 0, 1);
		exit(EXIT_FAILURE);
	}
	else if (param->pids[i] == 0)
	{
		duplicate_file_fd(param);
		if (i > 0)
			close(param->pipes[i - 1][1]);
		if (i < param->nb_cmds - 1)
			close(param->pipes[i][0]);
		path_and_access(param, cmd, -1);
	}
	else
	{
		close(param->infile_fd);
		if (i != param->nb_cmds - 1)
			close(param->outfile_fd);
		if (i > 0)
			close(param->pipes[i - 1][0]);
		if (i < param->nb_cmds - 1)
			close(param->pipes[i][1]);
	}
}

void	pipex(t_pipex *param, int i)
{
	while (++i < param->nb_cmds)
	{
		pipex_process(param, i);
		param->pids[i] = fork();
		run_command(param, param->cmds[i], i);
	}
	wait_and_clean(param, 1, 1);
}
