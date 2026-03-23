#include "ft_printf.h"

int ft_printf_putchar(char c)
{
	//write(1,&c,1);
    ft_putchar_fd(c,1);
	return (1);
}