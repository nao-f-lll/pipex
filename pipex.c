// JUST FOR TETSING 
//
//
//
#include <stdio.h>


// NOT SURE YET
//
//
#include <errno.h>


// PIRMETED
//
//
//
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int	ft_check_file(char *file, int mode)
{
	if (mode == 4)
	{
		if (access(file, R_OK) == 0)
			return (1);
	}
	else
	{
		if (access(file, F_OK) == 0)
		{
			if (access(file, W_OK) == 0)
				return (1);
			else
				return (-2);
		}
	}
	return (0);
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
	char *env[2];
	env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin";
	env[1] = NULL;
	execve(path, args, env);
}

void	ft_left_side(int *fds, int *pipefd)
{
	ft_dup2(fds[0], 0, pipefd[1], 1);
	ft_close(pipefd[0], fds[1]);
	char *args[] = {"grep", "world", NULL};
	ft_exec("/bin/grep", args);
}

void	ft_right_side(int mode, int *fds, int *pipefd)
{
	if (mode == 0)
		ft_dup2(fds[1], 1, pipefd[0], 0);
	else
		ft_dup2(open("/dev/null", O_WRONLY), 1, pipefd[0], 0);
	ft_close(pipefd[1], fds[0]);
	char *args[] = {"cat", NULL};
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

void	ft_creat_pipe(int *fds, char *cmd1, char *cmd2)
{
	int	pipefd[2];
	int	pid;
	
	pipe(pipefd);
	pid = fork();
	if (fds[0] != -2)
		ft_case_one(pid, fds, pipefd);
	else
	{
		ft_case_two(pid, fds, pipefd);
	}
	if (pid != 0)
	{
		ft_close(pipefd[1], fds[1]);
		ft_close(pipefd[0], fds[0]);
		while(wait(NULL) > 0);
	}
}

void	ft_pipex(char **argv)
{
	char 	*file_in;
	char 	*file_ou;
	int	fds[2];
	int	status;

	file_in = argv[1];
	file_ou = argv[4];
	fds[0] = -2;
	fds[1] = -2;
	if (ft_check_file(file_in, 4) == 0)
	{
		//substitute by your ft_printf
		printf("%s: %s\n", file_in, strerror(errno));
	}
	else
		fds[0] = open(file_in, O_RDONLY);
	status = ft_check_file(file_ou, 6);
	if (status == -2)
	{
		//substitute by your ft_printf
		printf("%s: %s\n", file_ou, strerror(errno));
	}
	else if (status == 0)
		fds[1] = open(file_ou, O_CREAT | O_WRONLY, 0644);
	else
		fds[1] = open(file_ou, O_WRONLY);
	ft_creat_pipe(fds, argv[2], argv[3]);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
		return (-1);
	ft_pipex(argv);
	return (0);
}
