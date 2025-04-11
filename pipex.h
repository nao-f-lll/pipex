#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_pipex(char **argv, char **envp);
int		ft_creat_pipe(int *fds, char **argv, char **envp);
void	ft_right_side(int *fds, int *pipefd, char *cmd, char **envp);
void	ft_case_two(int pid, int *fds, int *pipefd, char ***main_args);
void	ft_left_side(int *fds, int *pipefd, char *cmd, char **envp);
void	ft_exec(char *path, char **args, char **envp);
void	ft_close(int pipefd, int fd);
void	ft_dup2(int fd, int std1, int pipefd, int std2);
void	ft_case_one(int pid, int *fds, int *pipefd, char ***main_args);
char	**ft_get_paths(char **envp, char *exe);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	**ft_split_exe(const char *s, char c, char *exe);
char	**ft_split(const char *s, char c);
char	*ft_get_shell(char **envp);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_free(char **str);
void	ft_handle_cnf(char *shell, char *cmd);
int		ft_get_correct_path(char **paths, char *exe);
int		ft_check_file(char *file, int mode);
int		ft_printf(const char *format, ...);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_get_status(int pid);
#endif
