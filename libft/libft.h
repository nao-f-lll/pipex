/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:20:23 by nlyamani          #+#    #+#             */
/*   Updated: 2024/10/03 15:17:44 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# define INT_MIN -2147483648
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putunsnbr(unsigned int n);
int		ft_putnbr(int n);
int		ft_puthex(int n, int fd);
int		ft_putptr(void *ptr);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_substr_e(char const *s, unsigned int start, size_t len, char *exe);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split_exe(const char *s, char c, char *exe);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
