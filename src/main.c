/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 05:36:46 by jrenault          #+#    #+#             */
/*   Updated: 2023/06/26 02:15:20 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_params(t_pipex *param, int argc, char **argv, char **envp)
{
	param->env = envp;
	param->nb_cmds = argc - 3;
	param->nb_pipes = param->nb_cmds - 1;
	param->infile = argv[1];
	param->outfile = argv[argc - 1];
	if (!param->outfile || !param->outfile[0])
		exit(ft_printf("Pipex: Empty outfile name\n"));
	initialize_cmds(param, argv);
	initialize_pipes(param);
	param->pids = malloc(sizeof(pid_t) * param->nb_cmds);
	if (!param->pids)
	{
		perror("malloc failed");
		wait_and_clean(param, 0, 0);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	param;

	if (argc != 5)
	{
		ft_putstr_fd("Error.\n", 2);
		ft_putstr_fd("Usage: <infile> \"cmd1\" \"cmd2\" <outfile>\n", 2);
		return (1);
	}
	init_params(&param, argc, argv, envp);
	find_all_path(&param, -1);
	pipex(&param, -1);
	return (0);
}
