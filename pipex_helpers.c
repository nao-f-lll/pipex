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
	if (fd > 0)
		close(fd);
}

void	ft_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_exec(char *exe, char **args, char **envp)
{
	char	**paths;
	char	*shell;
	int		exe_in;

	paths = ft_get_paths(envp, exe);
	exe_in = ft_get_correct_path(paths, exe);
	shell = ft_get_shell(envp);
	if (exe_in == -1)
		exe_in = 0;
	if (access(paths[exe_in], X_OK) != 0)
	{
		ft_handle_cnf(shell, args[0]);
		ft_free(args);
		ft_free(paths);
		free(shell);
		exit(127);
	}
	if (execve(paths[exe_in], args, envp) == -1)
	{
		ft_free(args);
		exit(127);
	}
	ft_free(paths);
	exit(0);
}
