#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
# include "libft/libft.h"

# define HEX_UPPER_BASE "0123456789ABCDEF"
# define HEX_LOWER_BASE "0123456789abcdef"

int ft_printf_putchar(char c);
int ft_printf(const char *str, ...);
int ft_printf_putstr(char *s);
int ft_printf_putnbr(int c);
int ft_printf_puthex(unsigned int n, char *base);

#endif