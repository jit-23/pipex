/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:56:45 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/28 03:09:51 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void check_files(t_pipex *pipex)
{
	pipex->fd1 = open(pipex->file1, O_RDONLY);
	if (pipex->fd1 == -1)
		ext("cant find file1",pipex);
	pipex->fd2 = open(pipex->file2, O_RDWR, 0777);
	if (pipex->fd2 == -1)
	{
		pipex->fd2 = open(pipex->file2, O_CREAT | O_RDWR, 0777);
		if (pipex->fd2 == -1)
			ext("error with file2", pipex);
	}
}

void ext(char *str, t_pipex *pp)
{
	printf("%s\n", str);
	exit_pipe(pp);
	exit(1);
}

void check_comands(t_pipex *pipex)
{
	pipex->cmd1_args = ft_split(pipex->cmd_set1, ' ');
	pipex->cmd2_args = ft_split(pipex->cmd_set2, ' ');
	if (!pipex->cmd1_args || !pipex->cmd2_args)
		ext("error with cmds", pipex);
}

char **	organize_env(char **path_arr, char *path ,char *cmd)
{
	int i;
	path_arr = ft_split_path(path, ':');
	i = -1;
	while(path_arr[++i])
		path_arr[i] = ft_strjoin(path_arr[i], cmd);
	return (path_arr);
}

char *get_access(char *cmd_path,char **path_exec)
{
	int i;

	i = 0;
	if (!cmd_path)
		cmd_path = "";
	while(path_exec[i])
	{
		if (access(path_exec[i],X_OK) == 0)
		{
			cmd_path  = ft_strdup(path_exec[i]);
			return (cmd_path);
		}
		i++;
	}
	return (0);
}