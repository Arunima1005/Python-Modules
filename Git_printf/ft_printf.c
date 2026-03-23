/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:48:24 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/21 18:38:06 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


static int input_process(char c, va_list *args)
{
	if (c == 'c')
		return ft_printf_putchar(va_arg(*args, int));
	else if (c == 's')
		return ft_printf_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		return ft_printf_putnbr(va_arg(*args, int));
	else if (c == 'x')
		return ft_printf_puthex(va_arg(*args, unsigned int), HEX_LOWER_BASE);
	else if (c == 'X')
		return ft_printf_puthex(va_arg(*args, unsigned int), HEX_UPPER_BASE);
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		
		//printf("Hello\n");
		if (str[i] == '%' && str[i + 1])
		{
			//printf("while before i++ = %c\n", str[i]);
			i++;
			//printf("print === %s\n", va_arg(args, char *));
			count += input_process(str[i], &args);
			//printf("while after i++ = %c\n", str[i]);
		}
		else
			count += ft_printf_putchar(str[i]);
		//printf("while = %c\n", str[i]);
		i++;
	}
	va_end(args);
	return (count);

}
int main(void)
{
	ft_printf("Welcome %c. %s in Codam. %i is your login time %x and %X hexadecimal of logtime\n", 'A', "Chowdhury", 400, 255, 255);
	//ft_printf("Welcome %x in Codam\n", 255);
	//ft_printf("Welcome %c. in Codam\n", 'A');
}