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
