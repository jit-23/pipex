/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:21:22 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/13 06:47:57 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	proccess_child(t_pipex *pp, int *fd, char **env)
{
	close(fd[0]);
	dup2(pp->fd1, STDIN_FILENO); 
	dup2(fd[1], STDOUT_FILENO);
	if (execve(pp->cmd1_path, pp->cmd1_args, env) == -1)
		ext(pp);
}

void	proccess_child2(t_pipex *pp, int *fd, char **env)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(pp->fd2, STDOUT_FILENO);
	if (execve(pp->cmd2_path, pp->cmd2_args, env) == -1)
		ext(pp);
}

void	pp(t_pipex *pipex, char **env)
{
	pid_t	id1;
	pid_t	id2;
	int		fd[2];

	pipe(fd);
	id1 = fork();
	if (id1 == 0)
		proccess_child(pipex, fd, env);
	id2 = fork();
	if (id2 == 0)
		proccess_child2(pipex, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1,0,0);
	waitpid(-1,0,0);
	return ;
}
