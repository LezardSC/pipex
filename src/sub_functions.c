/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:44:12 by lezard            #+#    #+#             */
/*   Updated: 2023/06/13 14:32:24 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_dot_slash(t_pipex *param, char **args, pid_t *pids)
{
	param->true_path = ft_strdup(args[0]);
	if (!param->true_path)
		exit_failure_access(param, args, pids, 1);
	if (access(param->true_path, R_OK) != -1)
		execute_command(param, args, pids);
	free_tab(args);
}

void	access_path(t_pipex *param, char **args, pid_t *pids, int i)
{
	if (args[0][0] != '/')
	{
		param->tmp = ft_strjoin(param->path[i], "/");
		if (!param->tmp)
			exit_failure_access(param, args, pids, 0);
		param->true_path = ft_strjoin(param->tmp, args[0]);
		if (!param->true_path)
			exit_failure_access(param, args, pids, 0);
		free(param->tmp);
	}
	else
	{
		param->true_path = ft_strdup(args[0]);
		if (!param->true_path)
			exit_failure_access(param, args, pids, 1);
	}
	if (access(param->true_path, R_OK) != -1)
		execute_command(param, args, pids);
	free(param->true_path);
	param->true_path = NULL;
	free_tab(args);
}

void	pipex_process(t_pipex *param, pid_t *pids, int i)
{
	if (i == param->nb_cmds - 1)
	{
		param->outfile_fd = open(param->outfile, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
		if (param->outfile_fd == -1)
		{
			perror(param->outfile);
			close(param->infile_fd);
			free(pids);
			wait_and_clean(param, NULL, 0);
			exit(EXIT_FAILURE);
		}
	}
	else
		param->outfile_fd = param->pipes[i][1];
}
