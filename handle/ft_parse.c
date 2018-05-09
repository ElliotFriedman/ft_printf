/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:46:02 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:20:20 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	find_mod(t_data *curr, const char *str)
{
	//these are characters.
	int	i;

	i = 0;
	while (str[i] && str[i] == 'l' && ++i)
		curr->mod[i - 1] = 'l';
	while (str[i] && str[i] == 'h' && ++i)
		curr->mod[i - 1] = 'h';;
	if (str[i] && str[i] == 'j' && ++i)
		curr->mod[i - 1] = 'j';
	if (str[i] && str[i] == 'z' && ++i)
		curr->mod[i - 1] = 'z';
}

void	find_width_precision(t_data *curr, const char *str)
{
	int	i;

	i = 0;
	curr->pad = ft_matoi(str);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && str[i] != '.' && str[i] != 'l' && str[i] != 'h' && str[i] != 'z'
			&& str[i] != 'j')
		i++;
	if (str[i] == '.')
	{
		//could be an error point. recheck your logic tomorrow
		i++;
		curr->precision = ft_matoi(&str[i]);
		curr->precheck = 1;
		/*
		 *	Logic right here is not right at all, but the idea is
		 *	ballpark
		 */
		while (ft_isdigit(str[i]))
			i++;
	}
	find_mod(curr, &str[i]);
}

void	find_flags(t_data *curr, const char *str)
{
	//str will be passed in here after %

	/*
	 * 
	 * can you have multiple flags?
	 * do flags have to be sequentially ordered?
	 *
	 */
	int	i;
	int	x;

	x = find_len(str);
	i = 0;
	curr->chrfil = str[0];
	if (curr->chrfil != 32 && curr->chrfil != 48)
		curr->chrfil = 32;
	while (i < x)	
	{
		if (str[i] == '#' && ++i)
			curr->hash = 1;
		if (str[i] == '-' && ++i)
			curr->lr = 1;
		if (str[i] == '+' && ++i)
			curr->plus = 1;
		if (str[i] == ' ' && ++i)
			curr->chrfil = 32;
		i++;
	}
	find_width_precision(curr, str);
}
