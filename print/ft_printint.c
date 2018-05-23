/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:06:50 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 19:37:38 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						print_uint(char c, t_data *curr, va_list list)
{
	unsigned long long	nbr;
	char				*print;
	char				*buf;

	buf = 0;
	if (c == 'U')
		ft_strncpy(curr->mod, "ll", 2);
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

int						handle_0(t_data *curr)
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

/*
void					handle_neg(t_data *curr, long long *nbr)
{
	curr->plus = 0;
	curr->negative = 1;
	*nbr *= -1;
	if ((curr->pad && curr->chrfil == 48) || (curr->chk && !curr->pad))
		curr->pad--;
}
*/

int			edgec(t_data *curr, char *print)
{
	curr->pad--;
	print = make_pad(curr, print);
	print = prep_x(print, " ");
	return (1);
}

int			check(int long long *nbr, t_data *cur, char *buf, char *p)
{
	if (cur->precheck || cur->lr)
		cur->chrfil = 32;
	if ((cur->plus && cur->lr) || (cur->plus && !cur->pad))
		cur->pad++;
	if (!cur->precision && cur->precheck && !nbr && !cur->pad)
		return (1);
	if (!nbr && cur->chrfil == 48 && cur->pad)
		cur->pad--;
	if (!cur->precheck && !nbr && cur->lr && cur->pad)
		return (handle_0(cur));
	if (!cur->precision && cur->precheck && !nbr && cur->pad)
		return (hexgen(new_data("", cur), 0, cur));
	if (!nbr && cur->chk && cur->pad && cur->chrfil == 48 && edgec(cur, "0"))
		return (hexgen("0", buf, cur));
	if (*nbr < 0)
	{
		cur->plus = 0;
		cur->negative = 1;
		*nbr *= -1;
		if ((cur->pad && cur->chrfil == 48) || (cur->chk && !cur->pad))
			cur->pad--;
	}
	p = ft_itoabase(*nbr, 10);
	return (0);
}

int			print_int(t_data *cur, va_list list)
{
	int long long		nbr;
	char				*print;
	char				*buf;

	(buf = 0) ? print = 0 : (print = 0);
	print = 0;
	nbr = nint_flags(cur, list);
	if (check(&nbr, cur, buf, print))
		return (1);
	if (cur->precheck && cur->precision > (int)ft_strlen(print))
		print = make_pre(cur, print);
	if (cur->plus && !cur->negative && cur->chrfil == 32)
		print = prep_x(print, "+");
	else if (cur->negative && cur->chrfil != 48)
		print = prep_x(print, "-");
	if ((int)ft_strlen(print) < cur->pad)
		buf = new_data(print, cur);
	if (cur->chrfil == 48 && !cur->lr && cur->negative)
		buf = prep_x(buf, "-");
	if (cur->plus && cur->chrfil == 48)
		buf = prep_x(buf, "+");
	if (!cur->pad && !cur->precheck && cur->chk && !cur->plus)
		print = prep_x(print, " ");
	if (cur->pad && cur->precision && !cur->lr && cur->chk)
		buf = prep_x(buf, " ");
	return (hexgen(print, buf, cur));
}
