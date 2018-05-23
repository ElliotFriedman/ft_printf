/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:59:59 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 17:28:02 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pad(char *print, t_data *curr)
{
	char	*snew;
	int		len;
	
	if ((int)ft_strlen(print) < curr->pad)
	{
		len = (curr->pad - (int)ft_strlen(print)) + 2;
		snew = ft_memalloc(len);
		ft_memset(snew, curr->chrfil, len - 2);
	}
	else
		snew = 0;
	return (snew);
}

int		print_addy(t_data *curr, va_list list)
{
	char				*tmp;
	char				*snew;
	char				*print;
	unsigned long long	stor;

	ft_strncpy(curr->mod, "ll", 2);
	stor = uint_flags(curr, list);
	if (!stor && curr->precheck && !curr->pad && !curr->precision)
		return (hexgen("0x", 0, curr));
	print = ft_uitoabase(stor, 16);
	if (curr->precision > ((int)ft_strlen(print) + 2))
	{
		tmp = print;
		snew = ft_memalloc(curr->precision - (ft_strlen(print + 1)));
		ft_memset(snew, 48, curr->precision - (int)ft_strlen(print));
		print = ft_strjoin(snew, print);
		ft_memdel((void*)&tmp);
		ft_memdel((void*)&snew);
	}
	tmp = print;
	print = ft_strjoin("0x", print);
	ft_memdel((void*)&tmp);
	snew = pad(print, curr);
	return (hexgen(print, snew, curr));
}
