/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 21:20:23 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:23:12 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_rputstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}
/*
   int		ft_mputstr(wchar_t *str)
   {
   int	i;

   i = 0;
   while (str[i])
   {
   write(1, &str[i], sizeof(wchar_t));
   i++;
   }
   return (i);
   }

   void	ft_wideputchar(wchar_t c)
   {
   write(1, c, sizeof(wchar_t));
   }
   */
int		coutgen(t_data *curr, char print)
{
	char	*snew;
	int		tmp;

	tmp = 1;
	if (!curr->pad)
	{
		ft_mputstr(&print, curr);
	}
	else
	{
		snew = ft_memalloc(curr->pad - 1);
		ft_memset(snew, curr->chrfil, curr->pad - 1);
		if (curr->lr)
		{
			ft_mputstr(&print, curr);
			ft_mputstr(snew, curr);
		}
		else
		{
			ft_mputstr(snew, curr);
			ft_mputstr(&print, curr);
		}
		tmp = ft_strlen(snew) + 1;
		free(snew);
	}
	return (tmp);
}

void	ft_nputstr(char *str, t_data *curr, int i)
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

int		print_char(char c, t_data *curr, va_list list)
{
	char	*str;

	if (c == 'c')
	{
		//coutgen(curr, char_flags(curr, list));
		if (!curr->pad)
		{
			curr->iter++;
			ft_putchar(char_flags(curr, list));
		}
		else
		{
			str = ft_memalloc(curr->pad - 1);
			ft_memset(str, curr->chrfil, curr->pad - 1);
			if (curr->lr)
			{
				ft_putchar(char_flags(curr, list));
				ft_mputstr(str, curr);
			}
			else
			{
				ft_mputstr(str, curr);
				ft_putchar(char_flags(curr, list));
			}
		}
	}
	return (1);
}

int		print_str(char c, t_data *curr, va_list list)
{
	char *str;
	char *pad;
	
	if (c == 's')
	{
		str = str_flags(curr, list);
		if (!str)
			ft_mputstr("(null)", curr);
		else if (!curr->pad && !curr->precheck)
			ft_mputstr(str, curr);
		else if (curr->precheck && curr->precision < (int)ft_strlen(str) && curr->precision < curr->pad)
		{
			/*
			 *
			 *	if there is precision, precheck lets us know if there is precision
			 *	precision is less than the length of the string
			 *	and precision is less than the padding meaning we have to print out padding
			 *
			 */
			pad = ft_memalloc(curr->pad - curr->precision);
			ft_memset(pad, curr->chrfil, curr->pad - curr->precision);
			ft_mputstr(pad, curr);
			ft_nputstr(str, curr, curr->precision);
			free(pad);
		}
		else if (!curr->precheck && curr->precision < (int)ft_strlen(str))
			ft_nputstr(str, curr, curr->precision);
		else //if (curr->precision < (int)ft_strlen(str) && curr->precision > curr->pad)
			ft_mputstr(str, curr);
	}
	return (1);
}
