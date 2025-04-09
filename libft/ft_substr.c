/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:14:57 by nlyamani          #+#    #+#             */
/*   Updated: 2024/10/05 13:45:14 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	s_s;

	i = 0;
	if (!s)
		return (NULL);
	s_s = ft_strlen(s);
	if (s_s < start)
		return (ft_strdup("\0"));
	if (s_s - start < len)
		len = s_s - start;
	subs = (char *) malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = *(s + (start + i));
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
