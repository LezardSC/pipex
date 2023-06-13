/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 05:36:46 by jrenault          #+#    #+#             */
/*   Updated: 2023/06/13 14:27:33 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_params(t_pipex *param, int argc, char **argv, char **envp)
{
	param->env = envp;
	if (!param->env || !param->env[0])
		exit(ft_printf("Pipex: No environement has been found\n"));
	param->nb_cmds = argc - 3;
	param->infile = argv[1];
	param->outfile = argv[argc - 1];
	if (!param->outfile || !param->outfile[0])
		exit(ft_printf("Pipex: Empty outfile name\n"));
	initialize_cmds(param, argv);
	initialize_pipes(param);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	param;
	pid_t	*pids;

	if (argc < 5)
	{
		ft_printf("Error.\n");
		ft_printf("Usage: <infile> \"cmd1\" \"cmd2\" ... \"cmdn\" <outfile>\n");
		return (1);
	}
	init_params(&param, argc, argv, envp);
	find_all_path(&param, -1);
	pids = malloc(sizeof(pid_t) * param.nb_cmds);
	if (!pids)
	{
		perror("malloc failed");
		wait_and_clean(&param, NULL, 0);
		exit(EXIT_FAILURE);
	}
	pipex(&param, pids, -1);
	return (0);
}
