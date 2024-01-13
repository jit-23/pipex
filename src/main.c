/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:37:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/13 06:41:09 by fde-jesu         ###   ########.fr       */
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

static void	command_not_found(t_pipex *pipex)
{
	if (!pipex->cmd1_path && !pipex->cmd2_path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(pipex->cmd1, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(pipex->cmd2, 2);
		ft_putchar_fd('\n', 2);
		ext(pipex);
	}
	if (!pipex->cmd1_path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(pipex->cmd1, 2);
		ft_putchar_fd('\n', 2);
		ext(pipex);
	}
	if (!pipex->cmd2_path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(pipex->cmd2, 2);
		ft_putchar_fd('\n', 2);
		ext(pipex);
	}
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
	command_not_found(pipex);
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
