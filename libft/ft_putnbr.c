/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:32:49 by nlyamani          #+#    #+#             */
/*   Updated: 2024/11/13 17:00:44 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_int(int i, char*str)
{
	while (i-- > 0)
		write(1, &str[i], 1);
}

int	ft_putnbr(int n)
{
	int		i;
	char	str[10];
	int		c;

	i = 0;
	c = 0;
	if (n == 0)
		return (write(1, "0", 1), 1);
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == INT_MIN)
			return (write(1, "2147483648", 10), c = 11, c);
		n = -n;
		c++;
	}
	while (n > 0)
	{
		str[i++] = (n % 10) + 48;
		n /= 10;
		c++;
	}
	return (write_int(i, str), c);
}
