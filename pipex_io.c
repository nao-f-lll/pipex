#include "pipex.h"

void	ft_handle_cnf(char *shell, char *cmd)
{
	char	*prefix;
	char	*mid;
	char	*msg;

	prefix = ft_strjoin(shell, ": ");
	mid = ft_strjoin(prefix, cmd);
	free(prefix);
	msg = ft_strjoin(mid, ": command not found...\n");
	free(mid);
	write(2, msg, ft_strlen(msg));
	free(msg);
}

int	ft_get_status(int pid)
{
	int		status;
	pid_t	ended;

	status = 0;
	ended = wait(&status);
	if (ended == -1)
		return (1);
	if (ended == pid)
		return ((status >> 8) & 0xFF);
	if (wait(&status) != -1)
		return ((status >> 8) & 0xFF);
	return (1);
}

int	ft_get_exit_code(char **argv, char **envp)
{
	int		exe_in;
	int		status;
	char	**paths;
	char	**args;

	status = ft_check_file(argv[4], 6);
	if (status == -2)
		return (1);
	if (ft_strlen(argv[3]) != 0)
	{
		args = ft_split(argv[3], ' ');
		paths = ft_get_paths(envp, args[0]);
		exe_in = ft_get_correct_path(paths, args[0]);
		if (exe_in == -1)
			exe_in = 0;
		if (access(paths[exe_in], X_OK) != 0)
		{
			ft_free(paths);
			ft_free(args);
			return (127);
		}
		ft_free(paths);
		ft_free(args);
	}
	return (0);
}
