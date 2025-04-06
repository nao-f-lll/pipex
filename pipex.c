#include "pipex.h"

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
		while (wait(NULL) > 0);
	}
}

void	ft_pipex(char **argv)
{
	char	*file_in;
	char	*file_ou;
	int		fds[2];
	int		status;

	file_in = argv[1];
	file_ou = argv[4];
	fds[0] = -2;
	fds[1] = -2;
	if (ft_check_file(file_in, 4) == -1)
		ft_printf("%s: %s\n", file_in, strerror(errno));
	else
		fds[0] = open(file_in, O_RDONLY);
	status = ft_check_file(file_ou, 6);
	if (status == -2)
		ft_printf("%s: %s\n", file_ou, strerror(errno));
	else if (status == -1)
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
