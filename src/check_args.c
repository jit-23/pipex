/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:56:45 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/30 20:19:11 by fde-jesu         ###   ########.fr       */
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
char **organize_env(char *path ,char *cmd)
{
	int i;
	char **buff;
	buff = ft_split(&path[5], ':');
	i = -1;
	printf("cmd - %s\n", cmd);
	cmd = ft_strjoin("/", cmd);
	while(buff[++i])
		buff[i] = ft_strjoin(buff[i],cmd);
	i = -1;
	while(buff[++i])
		printf("%s\n", buff[i]);
	return (buff);
}


void ext(char *str, t_pipex *pp)
{
	printf("%s\n", str);
	exit_pipe(pp);
	exit(1);
}

void check_comands(t_pipex *pp)
{
	pp->cmd1_args = ft_split(pp->cmd_set1, ' ');
	if (!pp->cmd1_args)
		ext("error with cmds", pp);
	pp->cmd2_args = ft_split(pp->cmd_set2, ' ');
	if (!pp->cmd2_args)
		ext("error with cmds", pp);
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



/* 
 char **	organize_env(char *path ,char *cmd)
{
	int i;
	i = -1;
	char **buff;
	char *temp;
	printf("%s\n", path);
	buff = ft_split_path(path, ':');
	if (!buff)
		return NULL;
	while(buff[++i])
		printf("%d - %s\n", i, buff[i]);
	if (!buff)
		printf("error on the alloc\n");
	i = -1;
	while(buff[++i])
	{	
		temp = ft_strjoin(buff[i], cmd);
		buff[i] = temp;
	} 
	return (buff);
} */