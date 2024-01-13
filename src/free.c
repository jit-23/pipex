/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:53:51 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/13 01:35:14 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_org_env(t_pipex *pp)
{
	int	i;

	i = -1;
	if (pp->cmd1)
		free(pp->cmd1);
	if (pp->cmd2)
		free(pp->cmd2);
	if (pp->path_arr1)
	{
		while (pp->path_arr1[++i])
			free(pp->path_arr1[i]);
		free(pp->path_arr1);
	}
	i = -1;
	if (pp->path_arr2)
	{
		while (pp->path_arr2[++i])
			free(pp->path_arr2[i]);
		free(pp->path_arr2);
	}
}

void	exit_pipe(t_pipex *pp)
{
	int	i;

	i = -1;
	free_org_env(pp);
	if (pp->cmd1_path)
		free(pp->cmd1_path);
	if (pp->cmd2_path)
		free(pp->cmd2_path);
	i = -1;
	if (pp->cmd1_args)
	{
		while (pp->cmd1_args[++i])
			free(pp->cmd1_args[i]);
		free(pp->cmd1_args);
	}
	i = -1;
	if (pp->cmd2_args)
	{
		while (pp->cmd2_args[++i])
			free(pp->cmd2_args[i]);
		free(pp->cmd2_args);
	}
}

void	ext(t_pipex *pp)
{
	exit_pipe(pp);
	exit(127);
}
