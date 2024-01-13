/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:37:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/13 00:43:00 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_pipe(t_pipex *pipex, char **argv)
{
	ft_bzero(pipex, sizeof(t_pipex));
	pipex->file1 = argv[1];
	pipex->cmd_set1 = argv[2];
	pipex->cmd1 = ft_firstword(argv[2]);
	pipex->cmd_set2 = argv[3];
	pipex->cmd2 = ft_firstword(argv[3]);
	pipex->file2 = argv[4];
}

void	find_path(char **env, t_pipex *pipex)
{
	char	*path;
	int		i;

	i = -1;
	while (env[++i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path)
			break ;
		else
			continue ;
	}
	pipex->path = &path[5];
	pipex->path_arr1 = organize_env(pipex->path, pipex->cmd1, pipex);
	pipex->path_arr2 = organize_env(pipex->path, pipex->cmd2, pipex);
	if (!pipex->path_arr1 || !pipex->path_arr2)
		ext(pipex);
	pipex->cmd1_path = get_access(pipex->cmd1_path, pipex->path_arr1);
	pipex->cmd2_path = get_access(pipex->cmd2_path, pipex->path_arr2);
	if (!pipex->cmd1_path || !pipex->cmd2_path)
		ext(pipex);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (perror("wrong number of arguments:"), 1);
	init_pipe(&pipex, argv);
	check_files(&pipex);
	check_comands(&pipex);
	find_path(env, &pipex);
	pp(&pipex, env);
	exit_pipe(&pipex);
	return (0);
}
