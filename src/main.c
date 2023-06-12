/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 05:36:46 by jrenault          #+#    #+#             */
/*   Updated: 2023/06/12 05:52:42 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	param.env = envp;
	param.nb_cmds = argc - 3;
	param.infile = argv[1];
	param.outfile = argv[argc - 1];
	initialize_cmds(&param, argv);
	initialize_pipes(&param);
	find_all_path(&param);
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
