/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:26:40 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 10:40:52 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		hexgen(char *print, char *snew, t_data *curr)
{
	if (curr->lr && snew)
	{
		ft_mputstr(print, curr);
		ft_mputstr(snew, curr);
	}
	else if (snew)
	{
		ft_mputstr(snew, curr);
		ft_mputstr(print, curr);
	}
	else
		ft_mputstr(print, curr);
	return (1);
}
/*
char	*make_pre(t_data *curr, char *print)
{
	char	*tmp;
	char	*snew;

	tmp = print;
	snew = ft_memalloc(curr->precision - ft_strlen(print) + 1);
	ft_memset(snew, 48, curr->precision - ft_strlen(print));
	print = ft_strjoin(snew, print);
	ft_memdel((void**)&snew);
	ft_memdel((void**)&tmp);
	return (print);
}

char	*make_pad(t_data *curr, char *print)
{
	char	*snew;
	char	*tmp;

	tmp = print;
	snew = ft_memalloc(1 + curr->pad - ft_strlen(print));
	if (curr->hash)
		ft_memset(snew, curr->chrfil, (curr->pad - 2 ) - ft_strlen(print));
	else
		ft_memset(snew, curr->chrfil, curr->pad - ft_strlen(print));
	print = ft_strjoin(snew, print);
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&snew);
	return (print);
}
*/

/*
char	*prep_x(char *print, char *prep)
{
	char	*tmp;

	tmp = print;
	print = ft_strjoin(prep, print);
	ft_memdel((void**)&tmp);
	return (print);
}
*/

int		empty(t_data *curr)
{
	char 	*snew;
	int		x;

	if (curr->precision > curr->pad)
		x = curr->precision;
	else
		x = curr->pad;
	snew = ft_memalloc(x + 1);
	ft_memset(snew, 32, x);
	hexgen(snew, 0, curr);
	ft_memdel((void*)&snew);
	return (1);
}
/*
char	*upper(char *print)
{
	int	i;

	i = 0;
	while (print[i])
	{
		print[i] = ft_toupper(print[i]);
		i++;
	}
	return (print);
}
*/

char	*new_data(char *print, t_data *curr)
{
	char	*snew;

	snew = ft_memalloc(1 + curr->pad - ft_strlen(print));
	ft_memset(snew, curr->chrfil, curr->pad - ft_strlen(print));
	return (snew);
}

int		print_hex(char c, t_data *curr, va_list list)
{
	char				*snew;
	char				*print;
	unsigned long long	stor;

	snew = 0;
	stor = uint_flags(curr, list);
	if (curr->chrfil == 48 && curr->lr)
		curr->chrfil = 32;
	if (!curr->precision && curr->precheck && !stor && !curr->pad)
		return (1);
	if ((curr->precheck || curr->pad) && !stor)
		return (empty(curr));
	print = ft_uitoabase(stor, 16);
	if (curr->precheck && curr->precision > (int)ft_strlen(print))
		print = make_pre(curr, print);
	if ((int)ft_strlen(print) < curr->pad && curr->chrfil == 48)
		print = make_pad(curr, print);
	if (curr->hash && stor)
		print = prep_x(print, "0x");
	if ((int)ft_strlen(print) < curr->pad && curr->chrfil != 48)
		snew = new_data(print, curr);
	if (c == 'X')
		print = upper(print);
	return (hexgen(print, snew, curr));
}