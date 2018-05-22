/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 22:49:16 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/17 00:19:54 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


/*
 *
 * Should be able to handle any base
 * only needs to work for 8 and 16
 *	
 *			ctr		binary representation
 *  4/2		 1
 *  2/2		 2
 *  1/2		 3			100
 *	
 *					base 10 rep
 *  100/10	 1
 *  10/10	 2
 *  1/10	 3			100
 *
 *					base 16 rep
 *  100/16	 1
 *  6.25/16	 2			64
 */


/*
 * figure this out in base form
 * how many bytes need to be allocated for a base x string
 * with number y
 */

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

char 	*ft_itoabase(long long nbr, int base)
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
	{
		//check this logic
//		str[i] = '-';
		stand = nbr * -1;
//		x++;
	}
	while (stand)
	{
		str[x] = set(stand % base);
		stand /= base;
		x--;
	}
	return (str);
}
