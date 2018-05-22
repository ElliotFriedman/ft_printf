/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:02:29 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/17 20:31:20 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

	/*
	 *			mATOI
	 *
	 *	modified atoi. we clear all 
	 *	non-int '.' & '\n' chars and then
	 *	find any int. This will help us find
	 *	precision and width
	 *
	 */

static char	*ft_clr_whitespace(const char *str)
{
	int x;

	x = find_len(str);
	while ((!ft_isdigit(*str) || *str == '0') && *str != '.' && *str != '\n' && *str && x)
	{
		x--;
		str++;
	}
	return ((char *)str);
}

int			ft_matoi(const char *str)
{
	int					i;
	int					isneg;
	int long long		nbr;
	
	i = 0;
	nbr = 0;
	isneg = 0;
	str = ft_clr_whitespace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg++;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	if (isneg)
		return (-nbr);
	return (nbr);
}

/*
int main()
{
	t_data *curr = malloc(sizeof(t_data));
	ft_printf("matoi returned %d\n", ft_matoi("%20d", curr));
	ft_printf("matoi returned %d\n", ft_matoi("%660d", curr));

	return (0);
}*/
