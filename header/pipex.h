/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezard <lezard@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:09:27 by jrenault          #+#    #+#             */
/*   Updated: 2023/06/12 18:53:17 by lezard           ###   ########lyon.fr   */
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
}				t_pipex;

int			main(int argc, char **argv, char **envp);

void		pipex(t_pipex *param, pid_t *pids, int i);
void		execute_command(t_pipex *param, char **args, pid_t *pids);

void		initialize_cmds(t_pipex *param, char **argv);
void		initialize_pipes(t_pipex *param);
void		find_all_path(t_pipex *param);
void		wait_and_clean(t_pipex *param, pid_t *pids, int close_fd);

void		execute_dot_slash(t_pipex *param, char **args, pid_t *pids);
void		access_path(t_pipex *param, char **args, pid_t *pids, int i);
void		pipex_process(t_pipex *param, pid_t *pids, int i);

void		command_not_found(t_pipex *param, pid_t *pids);
void		exit_failure_pipes(t_pipex *param, int i);
void		exit_failure_access(t_pipex *param, char **args,
				pid_t *pids, int error);

#endif