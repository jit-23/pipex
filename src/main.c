/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:37:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/30 20:20:36 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void init_pipe(t_pipex *pipex, char **argv)
{
	ft_bzero(pipex, sizeof(t_pipex));
	pipex->file1 = argv[1];
	pipex->cmd_set1 = argv[2];
	pipex->cmd1 = ft_firstword(argv[2]);
	pipex->cmd_set2 = argv[3];
	pipex->cmd2 = ft_firstword(argv[3]);
	pipex->file2 = argv[4];
	pipex->cmd1_path = NULL;
	pipex->cmd2_path = NULL;
	pipex->cmd1_args = NULL;
	pipex->cmd2_args = NULL;
	pipex->path_arr1 = NULL;
	pipex->path_arr2 = NULL;
}


void	find_path(char ** env, t_pipex *pipex)
{
	char search[] = "PATH=";
	int i;

	i = -1;
	while(env[++i])
	{
		if (ft_strnstr(env[i], search, sizeof(search)) != NULL)
		{
			pipex->path = ft_strnstr(env[i], search, sizeof(search));
			break ;
		}
	}
	pipex->path_arr1 = organize_env(pipex->path, pipex->cmd1);
	pipex->path_arr2 = organize_env(pipex->path, pipex->cmd2);
	if (!pipex->path_arr1 || !pipex->path_arr2)
		ext("pipex path arr cant b found", pipex);	
	pipex->cmd1_path = get_access(pipex->cmd1_path,pipex->path_arr1);
	pipex->cmd2_path = get_access(pipex->cmd2_path, pipex->path_arr2);	
	if (!pipex->cmd1_path || !pipex->cmd2_path)
		ext("error finding exec1\n", pipex);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex pipex;

	if (argc != 5)
	{
		ft_printf("wrong number of argc\n");
		return(1);
	}
	init_pipe(&pipex, argv);
	check_files(&pipex);
	check_comands(&pipex);
	find_path(env, &pipex);
	pp(&pipex, env);
	exit_pipe(&pipex);
	return (0);
}
