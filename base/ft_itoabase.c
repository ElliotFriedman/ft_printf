/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 22:49:16 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 19:03:21 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	set(int nbr)
{
	if (nbr >= 10)
		return ('a' - 10 + nbr);
	else if (nbr < 0)
		return (-nbr + '0');
	else
		return (nbr + '0');
}

int		numlen(long long nbr, int base)
{
	int	len;

	len = 0;
	if (!nbr)
		return (2);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_itoabase(long long nbr, int base)
{
	char		*str;
	long long	stand;
	int			x;

	x = numlen(nbr, base) - 1;
	str = ft_memalloc(x + 2);
	if (!nbr)
		str[0] = '0';
	stand = nbr;
	if (nbr < 0)
		stand = nbr * -1;
	while (stand)
	{
		str[x] = set(stand % base);
		stand /= base;
		x--;
	}
	return (str);
}
