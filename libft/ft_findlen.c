/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:29:01 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/24 12:50:03 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'd' || s[i] == 'D' || s[i] == 'x' || s[i] == 'X'
				|| s[i] == 's' || s[i] == 'S' || s[i] == 'c' || s[i] == 'C'
				|| s[i] == 'p' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o'
				|| s[i] == 'u' || s[i] == 'U' || s[i] == 'b')
			return (i);
		i++;
	}
	return (0);
}
