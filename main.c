#include "stdio.h"
#include "includes/ft_printf.h"
#include <limits.h>
int main()
{
	ft_printf("ft %%+i 42 == %+i\n", 42);
	   printf("og %%+i 42 == %+i\n", 42);
	
	ft_printf("ft %%+d 42 == %+d\n", INT_MAX);
	   printf("og %%+d 42 == %+d\n", INT_MAX);

	ft_printf("ft %%+i -42 == %+i\n", -42);
	   printf("og %%+i -42 == %+i\n", -42);

	ft_printf("ft %%+04d 42 == %0+04d\n", 42);
	   printf("og %%+04d 42 == %0+04d\n\n", 42);

	ft_printf("ft %%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	   printf("og %%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	
	ft_printf("ft %% 4.5i 42 == |% 4.5i|\n", 42);
	   printf("og %% 4.5i 42 == |% 4.5i|\n", 42);

	ft_printf("ft %%04.5i 42 == |%04.5i|\n", 42);
	   printf("og %%04.5i 42 == |%04.5i|\n", 42);

	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	   printf("%%04.3i 42 == |%04.3i|\n", 42);

	ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	   printf("%%04.2i 42 == |%04.2i|\n", 42);


	return (0);
}
