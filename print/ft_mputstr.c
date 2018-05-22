/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:10:16 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:22:41 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_mputstr(char *str, t_data *curr)
{
	size_t	i;

	i = 0;
	if (str)
	{
		i = 0;
		while (str[i])
		{
			curr->iter++;
			write(1, &str[i], 1);
			i++;
		}
	}
}
