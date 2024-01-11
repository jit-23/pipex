/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:21:22 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/11 23:12:15 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void proccess_child(t_pipex *pp, int *fd, char **env)
{
	close(fd[0]);
	
	if (dup2(pp->fd1, STDIN_FILENO) < 0 || dup2( fd[1], STDOUT_FILENO) < 0)
		ext("error managing child Process STDIN/STDOUT:", pp);	

	if (execve(pp->cmd1_path, pp->cmd1_args, env) == -1)
		ext("error on execve1\n", pp);
}

void	proccess_child2(t_pipex *pp, int *fd,  char **env)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(pp->fd2, STDOUT_FILENO) ==-1)
		ext("error managing child Process STDIN/STDOUT:", pp);
	if (execve(pp->cmd2_path, pp->cmd2_args, env) == -1)
		ext("error executing second command:", pp);
}

void pp(t_pipex *pipex, char **env)
{
	pid_t	id1;
	pid_t	id2;
	//int wstatus = 0;
	int fd[2];
	pipe(fd);
	id1 = fork();
	if (id1 == 0)
		proccess_child(pipex, fd, env);
	else
	{
		id2 = fork();
		if (id2 == 0)
			proccess_child2(pipex, fd, env);
	}
	close(fd[0]);
	close(fd[1]);
	//waitpid(-1, &wstatus,0);
	//waitpid(-1, &wstatus,0);
	return ;
}
