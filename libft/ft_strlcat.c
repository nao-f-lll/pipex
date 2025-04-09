/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:07:51 by nlyamani          #+#    #+#             */
/*   Updated: 2024/09/26 15:34:03 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_s;
	size_t	src_s;

	dest_s = ft_strlen(dest);
	src_s = ft_strlen(src);
	if (dest_s >= size)
		dest_s = size;
	if (dest_s == size)
		return (dest_s + src_s);
	if (size - dest_s > src_s)
		ft_memcpy(dest + dest_s, src, src_s + 1);
	else
	{
		ft_memcpy(dest + dest_s, src, size - dest_s - 1);
		dest[size - 1] = '\0';
	}
	return (dest_s + src_s);
}
