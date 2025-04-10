#include "pipex.h"

char	*ft_get_shell(char **envp)
{
	int		i;
	int		size;
	char	*shell;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "SHELL", 5) == 0)
		{
			size = ft_strlen(envp[i]);
			shell = malloc(sizeof(char *) + size);
			ft_strlcpy(shell, ft_strrchr(envp[i], '/') + 1, size);
			return (shell);
		}
		i++;
	}
	return (NULL);
}

char	*ft_clean_path(char *o_path)
{
	char	*c_path;
	int		sp_size;

	sp_size = (ft_strlen(o_path) - 5);
	c_path = malloc(sizeof(char *) * (sp_size + 1));
	ft_strlcpy(c_path, o_path + 5, sp_size + 1);
	return (c_path);
}

char	*ft_extract_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (ft_clean_path(envp[i]));
		i++;
	}
	return (NULL);
}

char	**ft_get_paths(char **envp, char *exe)
{
	char	*env_path;
	char	**paths;

	env_path = ft_extract_path(envp);
	paths = ft_split_exe(env_path, ':', exe);
	free(env_path);
	return (paths);
}

int	ft_get_correct_path(char **paths, char *exe)
{
	char	*c_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		c_path = paths[i];
		ft_strlcat(c_path, "/", ft_strlen(c_path) + 2);
		ft_strlcat(c_path, exe, ft_strlen(c_path) + ft_strlen(exe) + 1);
		if (access(c_path, X_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}
