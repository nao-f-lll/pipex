#include "pipex.h"

void	ft_left_side(int *fds, int *pipefd)
{
	char	*args[] = {"grep", "world", NULL};

	ft_dup2(fds[0], 0, pipefd[1], 1);
	ft_close(pipefd[0], fds[1]);
	ft_exec("/bin/grep", args);
}

void	ft_right_side(int mode, int *fds, int *pipefd)
{
	char	*args[] = {"cat", NULL};

	if (mode == 0)
		ft_dup2(fds[1], 1, pipefd[0], 0);
	else
		ft_dup2(open("/dev/null", O_WRONLY), 1, pipefd[0], 0);
	ft_close(pipefd[1], fds[0]);
	ft_exec("/bin/cat", args);
}

void	ft_case_one(int pid, int *fds, int *pipefd)
{
	if (pid == 0)
		ft_left_side(fds, pipefd);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (fds[1] == -2)
				ft_right_side(-1, fds, pipefd);
			else
				ft_right_side(0, fds, pipefd);
		}
	}
}

void	ft_case_two(int pid, int *fds, int *pipefd)
{
	if (pid == 0)
	{
		if (fds[1] == -2)
			ft_right_side(-1, fds, pipefd);
		else
			ft_right_side(0, fds, pipefd);
	}
}
