/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:44:12 by lezard            #+#    #+#             */
/*   Updated: 2023/06/26 00:54:47 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes(t_pipex *param, int i)
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

void	access_cmd(t_pipex *param, char **args, int i)
{
	if (ft_strnstr(args[0], "/", ft_strlen(args[0])) != NULL)
	{
		param->true_path = ft_strdup(args[0]);
		if (!param->true_path)
			exit_failure_access(param, args, 1);
	}
	else
	{
		param->tmp = ft_strjoin(param->path[i], "/");
		if (!param->tmp)
			exit_failure_access(param, args, 0);
		param->true_path = ft_strjoin(param->tmp, args[0]);
		if (!param->true_path)
			exit_failure_access(param, args, 0);
		free(param->tmp);
	}
	if (access(param->true_path, R_OK) != -1)
		execute_command(param, args);
	free(param->true_path);
	param->true_path = NULL;
	free_tab(args);
}

void	pipex_process(t_pipex *param, int i)
{
	if (i == 0)
	{
		param->infile_fd = open(param->infile, O_RDONLY);
		if (param->infile_fd == -1)
			perror(param->infile);
	}
	else
		param->infile_fd = param->pipes[i - 1][0];
	if (i == param->nb_cmds - 1)
	{
		param->outfile_fd = open(param->outfile, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
		if (param->outfile_fd == -1)
		{
			perror(param->outfile);
			if (param->infile_fd != -1)
				close(param->infile_fd);
			wait_and_clean(param, 0, 0);
			exit(EXIT_FAILURE);
		}
	}
	else
		param->outfile_fd = param->pipes[i][1];
}

void	command_not_found(t_pipex *param, char *cmd)
{
	ft_putstr_fd("Pipex: Command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putchar_fd('\n', 2);
	wait_and_clean(param, 0, 0);
	exit(EXIT_FAILURE);
}

void	exit_failure_access(t_pipex *param, char **args, int error)
{
	if (error == 0)
	{
		perror("strjoin failed");
		free_tab(args);
		wait_and_clean(param, 0, 1);
		exit(EXIT_FAILURE);
	}
	else if (error == 1)
	{
		perror("strdup failed");
		free_tab(args);
		wait_and_clean(param, 0, 1);
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		perror("split failed");
		wait_and_clean(param, 0, 1);
		exit(EXIT_FAILURE);
	}
}
