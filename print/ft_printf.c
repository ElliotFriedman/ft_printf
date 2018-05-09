/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:23:10 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:22:12 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find(char c, va_list list, t_data *curr)
{
	if (c == 'O' || c == 'o')
		return (print_octal(curr, list));
	else if (c == 'u' || c == 'U' || c == 'X' || c == 'x' || c == 'p')
		return (print_ints(c, curr, list));
	else if (c == 'd' || c == 'i' || c == 'D')
		return (print_int(c, curr, list));
	else if (c == 'c')
		return (print_char(c, curr, list));
	else if (c == 's')
		return (print_str(c, curr, list));
	return (0);
}

int		exception(const char *str, int *i)
{
	if ((ft_strlen(str) > 1) && (str[0] == '%' && str[1] == '%'))
	{
		*i += 1;
		return (1);
	}
	else
		return (0);
}

int		ft_putstr_until(const char *str, t_data *curr)
{
	int i;
	int flag;
	int	x;

	x = 100;
	flag = 0;
	i = 0;
	if (str[0] == '%' && !(exception(str, &x)))
		return (1);
	while ((str[i] && str[i] != '%') || (exception(&str[i], &i)))
	{
		curr->iter++;
		write(1, &str[i], 1);
		i++;
	}
	if (str[i] == 0)
		return (0);
	return (i);
}

void	init(t_data *curr)
{
	curr->exception = 0;
	curr->plus = 0;
	curr->precheck = 0;
	curr->precision = 0;
	curr->hash = 0;
	curr->upper = 0;
	curr->pad = 0;
	curr->chrfil = 0;
	curr->lr = 0;
	curr->len = 0;
	ft_bzero(curr->mod, 2);
}

int		ft_printf(const char *str, ...)
{
	va_list	list;
	t_data	*curr;
	int		tmp;

	curr = ft_memalloc(sizeof(t_data));
	curr->sum = 0;
	curr->iter = 0;
	va_start(list, str);
	while ((tmp = ft_putstr_until(&str[curr->sum], curr)))
	{
		curr->sum += tmp;
		if (!curr->exception)
		{
			find_flags(curr, &str[curr->sum]);
			while ((str[curr->sum])
					&& !(find(str[curr->sum], list, curr)))
				curr->sum++;
		}
		if (curr->sum == (int)ft_strlen(str))
			break;
		curr->sum++;
		init(curr);
	}
	tmp = curr->iter;
	free(curr);
	va_end(list);
	return (tmp);
}
