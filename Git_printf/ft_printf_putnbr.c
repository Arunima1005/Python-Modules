#include "ft_printf.h"

int ft_printf_putnbr(int n)
{
	char    *str;
    int count;

    str = ft_itoa(n);
    if (!str)
        return (0);
    count = ft_printf_putstr(str);
	return (count);
}