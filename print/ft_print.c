/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:40:30 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:22:26 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'd' || str[i] == 'D' || str[i] == 'x' || str[i] == 'X'
				|| str[i] == 's' || str[i] == 'S' || str[i] == 'c' || str[i] == 'C'
				|| str[i] == 'p' || str[i] == 'i' || str[i] == 'O' || str[i] == 'o'
				|| str[i] == 'u' || str[i] == 'U')
			return (i);
		i++;
	}
	return (0);
}

int		outgen(t_data *curr, char *print)
{
	char	*snew;
	int		tmp;
	int		pad;

	tmp = 0;
	if (curr->pad > curr->precision)
		pad = curr->precision;
	else
		pad = curr->pad;
	if (!curr->pad && !curr->precision)
	{
		tmp = ft_strlen(print);
		ft_mputstr(print, curr);
	}
	else
	{
		snew = ft_memalloc(pad);
		if (curr->precision)
			ft_memset(snew, '0', pad - ft_strlen(print));
		else
			ft_memset(snew, curr->chrfil, pad - ft_strlen(print));
		if (curr->lr)
		{
			ft_mputstr(print, curr);
			ft_mputstr(snew, curr);
		}
		else
		{
			ft_mputstr(snew, curr);
			ft_mputstr(print, curr);
		}
		tmp = ft_strlen(snew) + ft_strlen(print);
		free(snew);
	}
	free(print);
	return (tmp);
}

/*
 *
 *	Account for all precision padding here
 *	then when we get to outgen we only worry about padding if it still applies
 *
 *
 */

int		print_octal(t_data *curr, va_list list)
{
	char	*print;
	char	*tmp;
	int		i;

	i = 0;
	print = ft_uitoabase(uint_flags(curr, list), 8);
	if ((curr->hash) && ft_strcmp("0", print))
	{
		tmp = print;
		print = ft_strjoin("0", print);
		free(tmp);
	}
	return (outgen(curr, print));
}
 
int		print_int(char c, t_data *curr, va_list list)
{
	char			*print;
	char			*tmp;
	int				i;

	i = -1;
	if (c == 'D')
	{
		curr->mod[0] = 'l';
		print = ft_itoabase(nint_flags(curr, list), 10);
	}
	if (c == 'd' || c == 'i')
	{
		print = ft_itoabase(nint_flags(curr, list), 10);
		if (curr->precheck && !curr->precision)
		{
			//double check this. this doesn't seem solid
			//hmmmm
			ft_memdel((void**)&print);
			return (1);
		}
	}
	if (curr->plus && c != 'o' && print[0] != '-' && c != 'O')
	{
		tmp = print;
		print = ft_strjoin("+", print);
		free(tmp);
	}
	return (outgen(curr, print));
} 
