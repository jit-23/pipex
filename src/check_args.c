/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:56:45 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/13 03:31:02 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_files(t_pipex *pipex)
{
	pipex->fd1 = open(pipex->file1, O_RDONLY);
	if (pipex->fd1 == -1)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(pipex->file1, 2);
		ft_putchar_fd('\n', 2);
		ext(pipex);
	}
	pipex->fd2 = open(pipex->file2, O_RDWR | O_TRUNC, 0777);
	if (pipex->fd2 == -1)
	{
		pipex->fd2 = open(pipex->file2, O_CREAT | O_WRONLY, 0777);
		if (pipex->fd2 == -1)
			ext(pipex);
	}
}

static void	clean_mem(char **path_array, char **buff, char *cmd)
{
	int	i;

	i = -1;
	if (buff)
	{
		while (buff[++i])
			free(buff[i]);
		free(buff);
	}
	i = -1;
	if (path_array)
	{
		while (path_array[++i])
			free(path_array[i]);
		free(path_array);
	}
	if (cmd)
		free(cmd);
}

char	**organize_env(char *path, char *cmd, t_pipex *pp)
{
	int		i;
	char	**buff;
	char	**path_array;

	i = -1;
	buff = ft_split(path, ':');
	if (!buff)
	{
		clean_mem(0, buff, cmd);
		ext(pp);
	}
	cmd = ft_strjoin("/", cmd);
	path_array = (char **)malloc(sizeof(char *) * (ft_count(path, ':') + 1));
	if (!path_array)
	{
		clean_mem(path_array, buff, cmd);
		ext(pp);
	}
	while (buff[++i])
		path_array[i] = ft_strjoin(buff[i], cmd);
	path_array[i] = 0;
	clean_mem(0, buff, cmd);
	return (path_array);
}

void	check_comands(t_pipex *pp)
{
	pp->cmd1_args = ft_split(pp->cmd_set1, ' ');
	if (!pp->cmd1_args)
		ext(pp);
	pp->cmd2_args = ft_split(pp->cmd_set2, ' ');
	if (!pp->cmd2_args)
		ext(pp);
}

char	*get_access(char *cmd_path, char **path_exec)
{
	int	i;

	i = 0;
	if (!cmd_path)
		cmd_path = "";
	while (path_exec[i])
	{
		if (access(path_exec[i], X_OK) == 0)
		{
			cmd_path = ft_strdup(path_exec[i]);
			return (cmd_path);
		}
		i++;
	}
	return (0);
}
