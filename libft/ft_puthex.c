/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:42:17 by nlyamani          #+#    #+#             */
/*   Updated: 2024/11/13 17:00:54 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_unsig_coversion(unsigned int nbr, char *base, char *nbrs)
{
	int	i;

	i = 0;
	while (nbr >= 16)
	{
		nbrs[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	nbrs[i] = base[nbr % 16];
	i++;
	nbrs[i] = '\0';
	return (i);
}

static int	ft_convert_dec_hex(char*nbrs, int nbr, int is_upper)
{
	char			*base;
	unsigned int	u_nbr;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	u_nbr = (unsigned int) nbr;
	return (handle_unsig_coversion(u_nbr, base, nbrs));
}

int	ft_puthex(int nbr, int is_upper)
{
	char	nbrs[9];
	int		i;
	int		counter;

	counter = 0;
	i = ft_convert_dec_hex(nbrs, nbr, is_upper);
	while (i-- > 0)
	{
		write(1, &nbrs[i], 1);
		counter++;
	}
	return (counter);
}
