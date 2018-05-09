/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:25:02 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/08 22:27:16 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main()
{
	   printf("%d\n", 42);
	ft_printf("%d\n", 42);

	   printf("This is a %s", "string\n");
	ft_printf("This is a %s", "string\n");
	
	return (0);
}
