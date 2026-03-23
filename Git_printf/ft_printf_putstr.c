#include "ft_printf.h"

int ft_printf_putstr(char *s)
{
	//write(1,&c,1);
    int i;
     
    i = 0;
    while (s[i])
    {
        ft_putchar_fd(s[i],1);
        i++;
    }
	return (i);
}