/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:06:50 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 16:20:59 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						print_uint(t_data *curr, va_list list)
{
	unsigned  long long	nbr;
	char				*print;
	char				*buf;

	buf = 0;
	nbr = uint_flags(curr, list);
	if (curr->precheck)
		curr->chrfil = 32;
	if (!curr->precision && curr->precheck && !nbr && !curr->pad)
		return (1);
	if (curr->plus)
		curr->precision++;
	if (!curr->precision && curr->precheck && !nbr && curr->pad)
		return (hexgen(new_data("", curr), 0, curr));
	print = ft_uitoabase(nbr, 10);
	if (curr->precheck && curr->precision > (int)ft_strlen(print))
		print = make_pre(curr, print);
	if ((int)ft_strlen(print) < curr->pad)
		buf = new_data(print, curr);
	return (hexgen(print, buf, curr));
}

int						print_int(t_data *curr, va_list list)
{
	int long long		nbr;
	char				*print;
	char				*buf;

	buf = 0;
	nbr = nint_flags(curr, list);
	if (curr->lr)
		curr->chrfil = 32;
	if (curr->precheck)
		curr->chrfil = 32;
	if ((curr->plus && curr->lr) || (curr->plus && !curr->pad))
		curr->pad++;
	if (!curr->precision && curr->precheck && !nbr && !curr->pad)
		return (1);
	if (!nbr && curr->chrfil == 48 && curr->pad)
		curr->pad--;
	if (!curr->precheck && !nbr && curr->lr && curr->pad)
	{
		ft_mputstr("0", curr);
		curr->pad--;
		while (curr->pad)
		{
			ft_mputstr(" ", curr);
			curr->pad--;
		}
		return (1);
	}
	if (!curr->precision && curr->precheck && !nbr && curr->pad)
		return (hexgen(new_data("", curr), 0, curr));
	if (nbr < 0)
	{
		curr->plus = 0;
		curr->negative = 1;
		nbr *= -1;
		if ((curr->pad && curr->chrfil == 48) || (curr->chk && !curr->pad))
			curr->pad--;
	}
	print = ft_itoabase(nbr, 10);
	if (!nbr && curr->chk && curr->pad && curr->chrfil == 48)
	{
		curr->pad--;
		print = make_pad(curr, print);
		print = prep_x(print, " ");
		return (hexgen(print, buf, curr));
	}
	if (curr->precheck && curr->precision > (int)ft_strlen(print))
		print = make_pre(curr, print);
	if (curr->plus && !curr->negative && curr->chrfil == 32)
		print = prep_x(print, "+");
	else if (curr->negative && curr->chrfil != 48)
		print = prep_x(print, "-");
	if ((int)ft_strlen(print) < curr->pad)
		buf = new_data(print, curr);
	if (curr->chrfil == 48 && !curr->lr && curr->negative)
		buf = prep_x(buf, "-");
	if (curr->plus && curr->chrfil == 48)
		buf = prep_x(buf, "+");
	if (!curr->pad && !curr->precheck && curr->chk && !curr->plus)
		print = prep_x(print, " ");
	if (curr->pad && curr->precision && !curr->lr && curr->chk)
		buf = prep_x(buf, " ");
	return (hexgen(print, buf, curr));
}
