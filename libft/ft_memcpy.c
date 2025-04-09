/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:54:00 by nlyamani          #+#    #+#             */
/*   Updated: 2024/10/05 12:41:41 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (src == dest)
		return (dest);
	index = 0;
	while (index < n)
	{
		((char *)dest)[index] = ((char *)src)[index];
		index++;
	}
	return (dest);
}
