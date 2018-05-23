/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:25:02 by efriedma          #+#    #+#             */
/*   Updated: 2018/05/22 17:50:34 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int main()
{
	printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c\n", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c\n", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");

//	ft_printf("ft %%+04d 42 == %0+04d\n", 42);
//	   printf("og %%+04d 42 == %0+04d\n", 42);

	/*	
	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
*/
//	ft_printf("ft {%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//	   printf("og {%30ls}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

//	ft_printf("ft %C\n", L'ÁM-^L´');
//	   printf("og %C\n", L'ÁM-^L´');

//   ft_printf("ft %lc, %lc\n", L'Ê', L'ÿ');
//	   printf("og %lc, %lc\n", L'Ê', L'ÿ');


//	wchar_t a = L'\x89';
	
//	ft_printf("ft %C\n", a);
//	   printf("og %C\n", a);

//	ft_printf("ft %C\n", L'ø');
//	   printf("og %C\n", L'ø');

//	   printf("og %hhC, %hhC\n", 0, L'Á±≥');

//	ft_printf("ft %ls\n", 0);
//	   printf("og %ls\n", 0);

//	printf("og {% 03d}\n", 0);
//	ft_printf("ft {% 03d}\n", 0);

//	ft_printf("ft {%.*s}\n", -5, "42");
//	   printf("og {%.*s}\n", -5, "42");

//	ft_printf("ft %.4s\n", "42");
//	   printf("og %.4s\n", "42");

//	ft_printf("ft %-5.2s is a string\n", "");
//	   printf("og %-5.2s is a string\n", "");

//	ft_printf("ft %5.2s is a string\n", "");
//	   printf("og %5.2s is a string\n", "");

//	ft_printf("ft %5.2s is a string\n", "this");
//	   printf("og %5.2s is a string\n", "this");

//	ft_printf("ft%5.3sis a string\n", "");
//	   printf("og%5.3sis a string\n", "");

//	ft_printf("ft %5.2s is a string\n", "this");
//	   printf("og %5.2s is a string\n", "this");

//	   printf("og%15.4s\n", "42");
//	ft_printf("ft%15.4s\n", "42");

//	   printf("og {%+03d}\n", 0);
//	ft_printf("ft {%+03d}\n", 0);

//	   printf("og %-05o\n", 2500);
//	ft_printf("ft %-05o\n", 2500);

//	ft_printf("ft %0+5d\n", 42);
//	   printf("og %0+5d\n", 42);

//	   printf("og %+10.5d\n", 4242);
//	ft_printf("ft %+10.5d\n", 4242);

//	printf("og %#-08x\n", 42);
//	ft_printf("ft %#-08x\n", 42);

//	ft_printf("ft %+10.5d\n", 4242);
//	   printf("og %+10.5d\n", 4242);  

//	ft_printf("ft %-+10.5d\n", 4242);
//	printf("og %-+10.5d\n", 4242);
//	printf("{%*3d}\n", 0, 1);
//	ft_printf("{%*3d}\n", 0, 0);

//	printf("{%*d}\n", -5, 42);
//	ft_printf("{%*d}\n", -5, 42);

	//	ft_printf("ft {%-03d}\n", 0);
//	printf("og {%-03d}\n", 0);

//	printf("og {% 03d}\n", 0);
//	ft_printf("ft {% 03d}\n", 0);

//	ft_printf("ft %%      i 42 == |%      i|\n", 42);
//	ft_printf("ft %% i -42 == |% i|\n", -42);
//	ft_printf("ft %% 4i 42 == |% 4i|\n", 42);

//	printf("og %%      i 42 == |%      i|\n", 42);
//	printf("og %% i -42 == |% i|\n", -42);
//	printf("og %% 4i 42 == |% 4i|\n\n", 42);

//	ft_printf("ft {%010d}\n", -42);
//	printf("og {%010d}\n", -42);
//	ft_printf("ft {%10d}\n", -42);
//	printf("og {%10d}\n", -42);
/*
		printf("og %%+i 42 == %+i\n", 42);
	ft_printf("ft %%+i 42 == %+i\n\n", 42);
	
	
	   printf("og %%+d 42 == %+d\n", INT_MAX);
	ft_printf("ft %%+d 42 == %+d\n\n", INT_MAX);

	   printf("og %%+i -42 == %+i\n", -42);
	ft_printf("ft %%+i -42 == %+i\n\n", -42);
*/
//	   printf("og {% 03d}\n", 0);

//	   printf("og {%+d}\n", 42);
//	ft_printf("ft {%+d}\n", 42);

//	   printf("og %ld\n", 0L);
//	ft_printf("ft %D\n", 0L);
	
//	ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
//	   printf("%%04.5i 42 == |%04.5i|\n", 42);

/*	ft_printf("%% i -42 == |% i|\n", -42);
	ft_printf("%% 4i 42 == |% 4i|\n", 42);

	   printf("%% i -42 == |% i|\n", -42);
	   printf("%% 4i 42 == |% 4i|\n", 42);
	ft_printf("%% 4.5i 42 == |% 4.5i|\n", 42);
       printf("%% 4.5i 42 == |% 4.5i|\n", 42);
*/
//	   printf("og {%010d}\n", -42);
//	ft_printf("ft {%010d}\n", -42);
//	   printf("{%3*d}", 0, 0);

	return (0);
}
