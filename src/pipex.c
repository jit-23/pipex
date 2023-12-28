/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:21:22 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/28 03:42:09 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/* e a partir do file1 que vamos tirar informacao para o comando
e a informacao vai ser direcionada para o pipe no fd[1] = R, dps ira sair fd[0] - w para o outro CP.
resumindo , o input agr em vez de vir do "user", vem do file e em vez de ir para o terminal,
 vai para um dos cantos do pipe, */

void proccess_child(t_pipex *pp, int *fd, char **env) // file1 cmd1//...
{
	printf("------PC------\n");
	/* printf("cmd1_path - %s\n", pp->cmd1_path);
	for (int i = 0; pp->cmd1_args[i] != NULL ; i++)
		printf("cmd1_args[%d] - %s\n",i,pp->cmd1_args[i]);
	 */
	close(fd[0]);
	
	if (dup2(pp->fd1, STDIN_FILENO) < 0 || dup2( fd[1], STDOUT_FILENO) < 0)
		ext("problem with dup2(pp->fd, 0)", pp);	

	if (execve(pp->cmd1_path, pp->cmd1_args, env) == -1)
		ext("error on execve1\n", pp);
}

void	proccess_parent(t_pipex *pp, int *fd,  char **env)// cmd2 file2//...
{
	printf("------PP------\n");
/* 	printf("cmd1_path - %s\n", pp->cmd1_path);
	for (int i = 0; pp->cmd2_args[i] ; i++)
		printf("cmd2_args[%d] - %s\n",i,pp->cmd2_args[i]); */
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		ext("error on dup1\n", pp);
	if (dup2(pp->fd2, STDOUT_FILENO) ==-1)
		printf("pp->fd2\n");
	if (execve(pp->cmd2_path, pp->cmd2_args, env) == -1)
		ext("error on execve2\n", pp);
}

void pp(t_pipex *pipex, char **env)
{
	pid_t	id1;
	pid_t	id2;
	int wstatus = 0;
	int fd[2];
	pipe(fd);
	id1 = fork();
	if (id1 == 0)
		proccess_child(pipex, fd, env);
	else
	{
		id2 = fork();
		if (id2 == 0)
			proccess_parent(pipex, fd, env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &wstatus,0);
	waitpid(-1, &wstatus,0);
	return ;
}


 /* id2  =fork();
		if (id2  == 0)
		{
			waitpid(id1, &wstatus, 0);
			proccess_parent(pipex, fd, env);
		}	 */




/* void proccess_child(t_pipex *pp, int *fd, char **env) // file1 cmd1//...
{
	printf("PC\n");
	printf("cmd1 - %s\n",pp->cmd1_args[0]);
	for (int i = 1; pp->cmd1_args[i] ; i++)
		printf("args2 - %s\n",pp->cmd1_args[i]);
	close(fd[0]);
	if (dup2(pp->fd1, STDIN_FILENO) < 0)
		ext("problem with dup2(pp->fd1, 0)");
	if (dup2( fd[1], STDOUT_FILENO) < 0)
		ext("problem with dup2(fd[1], 1)");
	//char *a[] = {"grep" , "a", NULL};
	if (execve(pp->cmd1_args[0], pp->cmd1_args, env) == -1)
		ext("error on execve1");
}

void	proccess_parent(t_pipex *pp, int *fd, char **env)// cmd2 file2//...
{
	printf("PP\n");
	printf("cmd2 - %s\n",pp->cmd2_args[0]);
	for (int i = 1; pp->cmd2_args[i] ; i++)
		printf("args2 - %s\n",pp->cmd2_args[i]);
	char str[1000];
	close(fd[1]);
	int bytes = read(fd[0],&str,1000);
	printf("bytes - %d", bytes);
	if (bytes < 0)
	{
		ext("error with pipe fd[0] on PP");
	}
	write(STDOUT_FILENO, &str, bytes);

	dup2(pp->fd2, STDOUT_FILENO);
	dup2( fd[0], STDIN_FILENO);
	printf("info2\n");
	if (execve(pp->cmd2_args[0], pp->cmd2_args, env) == -1)
		ext("error on execve2");
}
void pp(t_pipex *pipex, char **env)
{
	pid_t	id1;
	//pid_t	id2;
	//int wstatus;
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	id1  = fork();
	if (id1 == 0)
	{
		proccess_child(pipex, fd1, env);
	}
	else 
	{
		wait(NULL);
		//waitpid(id1,&wstatus,0);
		proccess_parent(pipex, fd2, env);
	}
		
	return ;
} */