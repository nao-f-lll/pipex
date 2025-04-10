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
