/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:29 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:19:59 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <wchar.h>

typedef struct	s_data
{
	int			exception;
	
	
	//String
	//how many bytes to print
	int			precision;
	int			precheck;	

	//Numbers
	//Precision can be applied here.
	//It is for how many spaces to print ' '.
	int			plus;
	//hash ? 1 : 0
	int			hash;
	//current index
	int			sum;
	//uppercase ? 1 : 0, for octal and hex
	int			upper;
	//the character you will fill with
	int         chrfil;

	/*
	  		All of these variables are global

	   right justified is global
	   left or right justified padding 1 is left, 0 is right
	 */
	int			lr;
	//modifier
	char		mod[2];
	//length of current item when displayed. this is to help with padding
	int			len;
	//iterator, to keep track of current position in the string with
	//regards to the iterator. for atoi'ing precision and width
	int         iter;
	//how many bytes to pad
	int			pad;

}				t_data;

int					ft_printf(const char *str, ...);
char				*ft_itoabase(long long nbr, int base);
char				*ft_uitoabase(unsigned long long nbr, int base);
int					ft_matoi(const char *str);
int					print_int(char c, t_data *curr, va_list list);
void				find_flags(t_data *curr, const char *str);
long long			nint_flags(t_data *curr, va_list list);
unsigned long long	uint_flags(t_data *curr, va_list list);
char				char_flags(t_data *curr, va_list list);
char				*str_flags(t_data *curr, va_list list);
int					print_char(char c, t_data *curr, va_list list);
int					print_str(char c, t_data *curr, va_list list);
int					print_octal(t_data *curr, va_list list);
int					print_int(char c, t_data *curr, va_list list);
int					print_ints(char c, t_data *curr, va_list list);
int					find_len(const char *str);
void				ft_mputstr(char *str, t_data *curr);


#endif
