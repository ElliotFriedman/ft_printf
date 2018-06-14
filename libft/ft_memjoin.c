/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:21:41 by efriedma          #+#    #+#             */
/*   Updated: 2018/06/14 13:07:41 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoin(void *a1, void *b1, size_t asize, size_t bsize)
{
	char	*n;

	n = ft_memalloc(asize + bsize);
	ft_memcpy(n, a1, asize);
	ft_memcpy(&n[bsize], b1, bsize);
	return ((void*)n);
}
