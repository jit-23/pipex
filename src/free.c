/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:53:51 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/28 03:04:27 by fde-jesu         ###   ########.fr       */
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
	while(pp->cmd1_args[++i])
		free(pp->cmd1_args[i]);
	i = -1;
	while(pp->cmd2_args[++i])
		free(pp->cmd2_args[i]);
	i = -1;
	while(pp->path_arr1[++i])
		free(pp->path_arr1[i]);
	i = -1;
	while(pp->path_arr2[++i])
		free(pp->path_arr2[i]);
}
