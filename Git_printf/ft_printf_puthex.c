#include "ft_printf.h"

int ft_printf_puthex(unsigned int n, char *base)
{
	//char *s;
    int count;

    count = 0;
    if (n >= 16)
        count += ft_printf_puthex(n / 16, base);
    count += ft_printf_putchar(base[n % 16]);    
	return (count);
}
// #include <stdio.h>
// int main(void)
// {
//     int count = 0;
//     printf("\nHexa count = %d\n", ft_printf_puthex(255,"0123456789ABCDEF"));
//     //ft_printf_puthex(48879,"0123456789ABCDEF");
// }