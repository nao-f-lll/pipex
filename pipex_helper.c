#include "pipex.h"

int	ft_check_file(char *file, int mode)
{
	if (mode == 4)
	{
		if (access(file, R_OK) == 0)
			return (0);
	}
	else
	{
		if (access(file, F_OK) == 0)
		{
			if (access(file, W_OK) == 0)
				return (0);
			else
				return (-2);
		}
	}
	return (-1);
}

void	ft_dup2(int fd, int std1, int pipefd, int std2)
{
	dup2(fd, std1);
	dup2(pipefd, std2);
}

void	ft_close(int pipefd, int fd)
{
	close(pipefd);
	close(fd);
}

void	ft_exec(char *path, char **args)
{
	char	*env[2];

	env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin";
	env[1] = NULL;
	execve(path, args, env);
}
