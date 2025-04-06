#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

void	ft_pipex(char **argv);
void	ft_creat_pipe(int *fds, char *cmd1, char *cmd2);
void	ft_case_two(int pid, int *fds, int *pipefd);
void	ft_case_one(int pid, int *fds, int *pipefd);
void	ft_right_side(int mode, int *fds, int *pipefd);
void	ft_left_side(int *fds, int *pipefd);
void	ft_exec(char *path, char **args);
void	ft_close(int pipefd, int fd);
void	ft_dup2(int fd, int std1, int pipefd, int std2);
int		ft_check_file(char *file, int mode);
int		ft_printf(const char *format, ...);
#endif
