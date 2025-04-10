#include "pipex.h"

void	ft_left_side(int *fds, int *pipefd, char *cmd, char **envp)
{
	char	**args;

	args = ft_split(cmd, ' ');
	ft_dup2(fds[0], 0, pipefd[1], 1);
	ft_close(pipefd[0], fds[1]);
	ft_exec(args[0], args, envp);
}

void	ft_right_side(int *fds, int *pipefd, char *cmd, char **envp)
{
	/*
	char	**args;

	args = ft_split(cmd, ' ');
	if (fds[1] != -2)
		ft_dup2(fds[1], 1, pipefd[0], 0);
	else
		ft_dup2(open("/dev/null", O_WRONLY), 1, pipefd[0], 0);
	ft_close(pipefd[1], fds[0]);
	ft_exec(args[0], args, envp);
	*/
	
	char	**args;

	if (fds[1] != -2)
	{
		args = ft_split(cmd, ' ');
		ft_dup2(fds[1], 1, pipefd[0], 0);
		ft_close(pipefd[1], fds[0]);
		ft_exec(args[0], args, envp);
	}
	else
	{
		ft_dup2(open("/dev/null", O_WRONLY), 1, pipefd[0], 0);
		ft_close(pipefd[1], fds[0]);
	}
}

void	ft_case_one(int pid, int *fds, int *pipefd, char ***main_args)
{
	char	**argv;
	char	**envp;
	char	*cmds[2];

	argv = main_args[0];
	envp = main_args[1];
	cmds[0] = argv[2];
	cmds[1] = argv[3];
	if (pid == 0)
	{
		if (ft_strlen(cmds[0]) != 0)
			ft_left_side(fds, pipefd, cmds[0], envp);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (ft_strlen(cmds[0]) != 0)
				ft_right_side(fds, pipefd, cmds[1], envp);
		}
	}
}

void	ft_case_two(int pid, int *fds, int *pipefd, char ***main_args)
{
	char	**argv;
	char	**envp;
	
	argv = main_args[0];
	envp = main_args[1];
	if (pid == 0)
	{
		if (ft_strlen(argv[3]) != 0)
			ft_right_side(fds, pipefd, argv[3], envp);
	}
}
