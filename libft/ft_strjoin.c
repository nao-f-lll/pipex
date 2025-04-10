/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:05:32 by nlyamani          #+#    #+#             */
/*   Updated: 2024/10/05 13:52:44 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_s;
	int		s2_s;

	if (!s1 || !s2)
		return (NULL);
	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	str = (char *) malloc((s1_s + s2_s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_s);
	ft_memcpy(str + s1_s, s2, s2_s);
	str[s1_s + s2_s] = '\0';
	return (str);
}
