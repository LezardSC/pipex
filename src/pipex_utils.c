/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:12:38 by lezard            #+#    #+#             */
/*   Updated: 2023/06/25 21:27:05 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_cmds(t_pipex *param, char **argv)
{
	int	i;

	param->cmds = malloc(sizeof(char *) * (param->nb_cmds + 1));
	if (!param->cmds)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < param->nb_cmds)
	{
		param->cmds[i] = ft_strdup(argv[i + 2]);
		if (!param->cmds[i])
		{
			while (i >= 0)
			{
				free(param->cmds[i]);
				i--;
			}
			free(param->cmds);
			perror("strdup failed");
			exit(EXIT_FAILURE);
		}
	}
	param->cmds[i] = NULL;
}

void	initialize_pipes(t_pipex *param)
{
	int	i;

	param->pipes = malloc(sizeof(int *) * param->nb_pipes);
	if (!param->pipes)
	{
		free_tab(param->cmds);
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < param->nb_pipes)
		create_pipes(param, i);
}

void	find_all_path(t_pipex *param, int i)
{
	param->path = NULL;
	i = -1;
	while (param->env[++i])
	{
		if (ft_strnstr(param->env[i], "PATH=", 5) != NULL)
		{
			param->path = ft_split(&param->env[i][5], ':');
			if (!param->path)
			{
				free_tab(param->cmds);
				i = -1;
				while (++i < param->nb_pipes)
				{
					close(param->pipes[i][0]);
					close(param->pipes[i][1]);
				}
				free_tab_int(param->pipes, param->nb_pipes);
				perror("split failed");
				exit(EXIT_FAILURE);
			}
			return ;
		}
	}
}

static void	close_pipes(t_pipex *param)
{
	int	i;

	i = 0;
	while (i < param->nb_pipes)
	{
		close(param->pipes[i][0]);
		close(param->pipes[i][1]);
		i++;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	wait_and_clean(t_pipex *param, int wait, int close_fd)
{
	int	i;

	i = param->nb_pipes;
	while (wait == 1 && i >= 0)
	{
		if (waitpid(param->pids[i], NULL, 0) == -1)
		{
			perror("waitpid");
			wait_and_clean(param, 0, 1);
			exit(EXIT_FAILURE);
		}
		i--;
	}
	close_pipes(param);
	if (close_fd == 1)
	{
		if (param->infile_fd != -1)
			close(param->infile_fd);
		if (param->outfile_fd != -1)
			close(param->outfile_fd);
	}
	free_tab(param->path);
	free_tab_int(param->pipes, param->nb_pipes);
	free(param->pids);
	free_tab(param->cmds);
}
