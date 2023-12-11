#include "pipex.h"

void    find_path(int argc, char ** argv, char ** env)
{
	char path[] = "PATH=";
	int i = -1;
	while(env[++i])
	{
		if (strnstr(env[i], path,ft_strlen(path) != NULL))
			
			break;	
	}
	
}

int main(int argc, char *argv[], char *env[])
{
    if (argc != 5)
    {
        ft_printf("wrong number of argc\n");
        return(1);
    }
    
    find_path(argc, argv, env);    
    return 0;
}
