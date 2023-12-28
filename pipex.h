/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:53:56 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/28 02:59:15 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_pipex // ./pipex file1 comand1 comand2 file2
{
	char **path_arr1;
	char **path_arr2;
	char *path;

	char *file1;
	char *file2;
	int fd1;
	int fd2;
	
	char *cmd_set1;
	char *cmd_set2;

	char	**cmd1_args;
	char	**cmd2_args;
	
	char *cmd1_path;
	char *cmd2_path;
	
	char *cmd1;
	char *cmd2;	
}t_pipex;

char **	organize_env(char **path_arr, char *path ,char *cmd);
void 	check_comands(t_pipex *pipex);
void 	ext(char *str, t_pipex *pp);
void 	check_files(t_pipex *pipex);
void 	init_pipe(t_pipex *pipex, char **argv);
void    find_path(char ** env, t_pipex *pipex);
char 	*get_access(char *cmd_path,char ** path_exec);
void 	pp(t_pipex *pipex, char **env);
void	proccess_parent(t_pipex *pp, int *fd, char **env);
void 	proccess_child(t_pipex *pp, int *fd, char **env);
void exit_pipe(t_pipex *pp);

#endif
