/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:40:30 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 17:31:20 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		hexgen2(char *print, char *snew, t_data *curr)
{
	if (curr->lr && snew)
	{
		ft_mputstr(print, curr);
		ft_mputstr(snew, curr);
		ft_memdel((void*)&print);
		ft_memdel((void*)&snew);
	}
	else if (snew)
	{
		ft_mputstr(snew, curr);
		ft_mputstr(print, curr);
		ft_memdel((void*)&print);
		ft_memdel((void*)&snew);
	}
	else
	{
		ft_mputstr(print, curr);
		ft_memdel((void*)&print);
	}
	return (1);
}

/*
 *
 *	Don't handle + sign
 *
 */

int		print_octal(char c, t_data *curr, va_list list)
{
	char				*print;
	char				*snew;
	unsigned long long	stor;
	int					i;

	i = 0;
	snew = 0;
	if (c == 'O')
		ft_strncpy(curr->mod, "l", 1);
	stor = uint_flags(curr, list);
	if (curr->lr && curr->chrfil == 48)
		curr->chrfil = 32;
	if (!curr->precision && curr->precheck && !stor && !curr->pad && !curr->hash)
		return (1);
	if (!curr->precision && curr->precheck && !stor && curr->pad && !curr->hash)
		return (hexgen2(new_data("", curr), 0, curr));
	print = ft_uitoabase(stor, 8);
	if ((curr->hash) && stor)
		print = prep_x(print, "0");
	if (curr->precheck && curr->precision > (int)ft_strlen(print))
		print = make_pre(curr, print);
	if ((int)ft_strlen(print) < curr->pad && curr->chrfil == 48)
		print = make_pad(curr, print);
	if ((int)ft_strlen(print) < curr->pad && curr->chrfil != 48)
		snew = new_data(print, curr);
	return (hexgen2(print, snew, curr));
}
