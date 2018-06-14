#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	wchar_t wz [3] = L"@@";

	ft_printf("%S\n", wz);

	return 0;
}
