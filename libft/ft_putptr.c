/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:23:29 by nlyamani          #+#    #+#             */
/*   Updated: 2024/11/13 17:02:21 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_void_to_hex(size_t nbr)
{
	char	*base;
	int		cnt;

	base = "0123456789abcdef";
	cnt = 0;
	if (nbr >= 16)
	{
		cnt = cnt + ft_void_to_hex(nbr / 16);
	}
	write(1, &base[nbr % 16], 1);
	cnt++;
	return (cnt);
}

int	ft_putptr(void *ptr)
{
	int	cnt;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	cnt = 0;
	write(1, "0x", 2);
	cnt += 2;
	cnt += ft_void_to_hex((size_t) ptr);
	return (cnt);
}
