/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:43:02 by nlyamani          #+#    #+#             */
/*   Updated: 2024/11/13 18:27:18 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsnbr(unsigned int n)
{
	long	nl;
	int		i;
	char	str[10];
	int		c;

	i = 0;
	nl = n;
	c = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nl > 0)
	{
		str[i++] = (nl % 10) + 48;
		nl /= 10;
		c++;
	}
	while (i-- > 0)
		write(1, &str[i], 1);
	return (c);
}
