/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:36:58 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 10:17:18 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_wstrlen(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_nwputstr(wchar_t *str, t_data *curr, int i)
{
	int	x;

	x = 0;
	while (str[x] && x < i)
	{
		write(1, &str[x], 1);
		curr->iter++;
		x++;
	}
}

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

int		print_wchar(t_data *curr, va_list list)
{
	char	*str;

	ft_bzero(curr->mod, 2);
	if (!curr->pad)
		ft_putwchar(va_arg(list, wchar_t));
	else
	{
		str = ft_memalloc(curr->pad - 1);
		ft_memset(str, curr->chrfil, curr->pad - 1);
		if (curr->lr)
		{
			ft_putwchar(va_arg(list, wchar_t));
			ft_mputstr(str, curr);
		}
		else
		{
			ft_mputstr(str, curr);
			ft_putwchar(va_arg(list, wchar_t));
		}
		ft_memdel((void*)&str);
	}
	curr->iter++;
	return (1);
}


void	ft_wprints(t_data *curr)
{
	if (curr->chrfil == 32)
		while (curr->pad > 0)
		{	
			ft_mputstr(" ", curr);
			curr->pad--;
		}
	else
	{
		while (curr->pad > 0)
		{
			ft_mputstr("0", curr);
			curr->pad--;
		}
	}
}

void    ft_wputstr(wchar_t *str, t_data *curr)
{
		int i;

		i = 0;
		while (str[i])
		{
			ft_putwchar(str[i]);
			curr->iter++;
			i++;
		}
}

void	handle_woutput(t_data *curr, wchar_t *print)
{
	if (curr->lr)
	{
		ft_wputstr(print, curr);
		ft_wprints(curr);
	}
	else
	{
		ft_wprints(curr);
		ft_wputstr(print, curr);
	}
}

wchar_t	*ft_wstrdup(const char *str)
{
	int		i;
	wchar_t	*new;

	i = ft_strlen(str);
	new = ft_memalloc(sizeof(wchar_t) * i + 1);
	if (!i)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

int		print_wstr(t_data *curr, va_list list)
{
	wchar_t *str;

	ft_bzero(curr->mod, 2);
	str = va_arg(list, wchar_t *);
	if (!str)
		str = ft_wstrdup("(null)");
	if (!curr->precheck)
		curr->pad -= (int)ft_wstrlen(str);
	else
	{
		if ((int)ft_wstrlen(str) > curr->precision)
			curr->pad -= curr->precision;
		else
			curr->pad -= (int)ft_wstrlen(str);
	}
	if (curr->lr && curr->precheck)
	{
		ft_nwputstr(str, curr, curr->precision);
		ft_wprints(curr);
	}
	else if (!curr->lr && curr->precheck)
	{
		ft_wprints(curr);
		ft_nwputstr(str, curr, curr->precision);
	}
	else if ((!curr->lr && !curr->precheck) || (curr->lr && !curr->precheck))
		handle_woutput(curr, str);
	return (1);
}
