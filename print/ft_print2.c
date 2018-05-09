/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:03:32 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:22:57 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		outgen2(char *print, t_data *curr)
{
	char	*buf;
	//implement left right curr->lr
	if (curr->pad > (int)ft_strlen(print))
	{
		buf = ft_memalloc(curr->pad - ft_strlen(print));
		ft_memset(buf, curr->chrfil, curr->pad - ft_strlen(print));
		if (curr->lr)
		{
			ft_mputstr(print, curr);
			ft_mputstr(buf, curr);
		}
		else
		{
			ft_mputstr(buf, curr);
			ft_mputstr(print, curr);
		}
		free(buf);
	}
	else
		ft_mputstr(print, curr);
	free(print);
	return (1);
}

int		print_ints(char c, t_data *curr, va_list list)
{
	char	*tmp;
	char	*new;
	char	*print;
	int		i;

	i = -1;
	if (c == 'u')
		print = ft_uitoabase(uint_flags(curr, list), 10);
	else if (c == 'U')
		print = ft_uitoabase(uint_flags(curr, list), 10);
	else if (c == 'x' || c == 'X' || c == 'p')
		print = ft_uitoabase(uint_flags(curr, list), 16);
	if (c == 'X')
		while (print[++i])
			print[i] = ft_toupper(print[i]);
	if (curr->precheck && curr->precision > (int)ft_strlen(print))
	{
		tmp = print;
		new = ft_memalloc(curr->precision - ft_strlen(print));
		ft_memset(new, 48, curr->precision - ft_strlen(print));
		print = ft_strjoin(new, print);
		free(tmp);
	}
	if ((c == 'p' || c == 'x' || c == 'X') && curr->hash)
	{
		tmp = print;
		print = ft_strjoin("0x", print);
		free(tmp);
	}
	return (outgen2(print, curr));
}
