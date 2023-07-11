/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:09:27 by jrenault          #+#    #+#             */
/*   Updated: 2023/06/26 00:26:59 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_pipex
{
	int		nb_cmds;
	int		nb_pipes;
	int		**pipes;
	int		infile_fd;
	int		outfile_fd;
	char	*infile;
	char	*outfile;
	char	*true_path;
	char	*tmp;
	char	**cmds;
	char	**env;
	char	**path;
	pid_t	*pids;
}				t_pipex;

int			main(int argc, char **argv, char **envp);

void		pipex(t_pipex *param, int i);
void		execute_command(t_pipex *param, char **args);

void		initialize_cmds(t_pipex *param, char **argv);
void		initialize_pipes(t_pipex *param);
void		find_all_path(t_pipex *param, int i);
void		wait_and_clean(t_pipex *param, int wait, int close_fd);
void		exit_failure_access(t_pipex *param, char **args, int error);

void		access_cmd(t_pipex *param, char **args, int i);
void		pipex_process(t_pipex *param, int i);
void		create_pipes(t_pipex *param, int i);
void		free_all(t_pipex *param);
void		command_not_found(t_pipex *param, char *cmd);

#endif