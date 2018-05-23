/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:42:19 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/23 15:18:00 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		dispatch(va_list list, const char *str)
{
	t_data	*curr;
	int		tmp;

	curr = ft_memalloc(sizeof(t_data));
	while ((tmp = ft_putstr_until(&str[curr->sum], curr)))
	{
		find_flags(curr, &str[curr->sum]);
		while ((str[curr->sum])
				&& !(find(str[curr->sum], list, curr)))
		{
			curr->sum++;
			if (str[curr->sum] == '%')
				print_per(curr);
		}
		if (curr->sum == (int)ft_strlen(str))
			break ;
		curr->sum++;
		init(curr);
	}
	tmp = curr->iter;
	free(curr);
	va_end(list);
	return (tmp);
}

int		ft_fprintf(FILE *s, const char *str, ...)
{
	int		tmp;
	va_list	list;

	va_start(list, str);
	tmp = dispatch(list, str);
	return (tmp);
}
