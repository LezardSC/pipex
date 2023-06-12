/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezard <lezard@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 05:30:27 by jrenault          #+#    #+#             */
/*   Updated: 2023/06/12 18:43:02 by lezard           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_failure_pipes(t_pipex *param, int i)
{
	param->pipes[i] = malloc(sizeof(int) * 2);
	if (!param->pipes[i])
	{
		free_tab(param->cmds);
		while (i >= 0)
		{
			free(param->pipes[i]);
			i--;
		}
		free(param->pipes);
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	if (pipe(param->pipes[i]) == -1)
	{
		free_tab(param->cmds);
		while (i >= 0)
		{
			free(param->pipes[i]);
			i--;
		}
		free(param->pipes);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	exit_failure_access(t_pipex *param, char **args, pid_t *pids, int error)
{
	if (error == 0)
	{
		free_tab(args);
		wait_and_clean(param, NULL, 1);
		free(pids);
		perror("strjoin failed");
		exit(EXIT_FAILURE);
	}
	else if (error == 1)
	{
		free_tab(args);
		wait_and_clean(param, NULL, 1);
		free(pids);
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		wait_and_clean(param, NULL, 1);
		free(pids);
		perror("split failed");
		exit(EXIT_FAILURE);
	}
}

void	command_not_found(t_pipex *param, pid_t *pids)
{
	perror("Command not found");
	free(pids);
	wait_and_clean(param, NULL, 0);
	exit(EXIT_FAILURE);
}
