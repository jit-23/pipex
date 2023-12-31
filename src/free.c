/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:53:51 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/30 20:13:32 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void exit_pipe(t_pipex *pp)
{
	int i;

	i = -1;
	if (pp->fd1)
		close(pp->fd1);
	if (pp->fd2)
		close(pp->fd2);
	if (pp->cmd1)
	{
		printf("deleted cmd1\n");
		free(pp->cmd1);
	}
	if (pp->cmd2)
		free(pp->cmd2);
	if (pp->cmd1_path)
		free(pp->cmd1_path);
	if (pp->cmd2_path)
		free(pp->cmd2_path);
	i = -1;
	if (pp->path_arr1) // find _path
	{
		printf("deleting1\n");
		while(pp->path_arr1[++i])
			free(pp->path_arr1[i]);	
		free(pp->path_arr1);
	}	
	i = -1;
	if (pp->path_arr2) // find _path
	{
		while(pp->path_arr2[++i])
			free(pp->path_arr2[i]);	
		free(pp->path_arr2);
	}

	i = -1;
	if (pp->cmd1_args) //check commands 
	{
		while(pp->cmd1_args[++i])
			free(pp->cmd1_args[i]);
		free(pp->cmd1_args);
	}
	i = -1;
	if (pp->cmd2_args) //check commands
	{
		while(pp->cmd2_args[++i])
			free(pp->cmd2_args[i]);
		free(pp->cmd2_args);
	}
	exit(1);
}

/* {
		buff = ft_strnstr(env[i], search, sizeof(search));
		if (buff != NULL)
		{
			pipex->path = ft_strnstr(env[i], search, sizeof(search));
			break ;
		}
		free(buff);
	} */


/* while(env[++i])
	{
		buff = ft_strnstr(env[i], search, sizeof(search));
		if (buff != NULL)
		{
			pipex->path = ft_strnstr(env[i], search, sizeof(search));
			break ;
		}
		free(buff);
	} */