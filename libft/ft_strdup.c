/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:12:02 by nlyamani          #+#    #+#             */
/*   Updated: 2024/10/05 13:30:55 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_dup;
	int		s1_s;
	int		i;

	i = 0;
	s1_s = ft_strlen(s1);
	s1_dup = (char *) malloc((s1_s + 1) * sizeof(char));
	if (!s1_dup)
		return (NULL);
	while (i < s1_s)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}
