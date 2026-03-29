/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:48:24 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/24 18:50:59 by archowdh         ###   ########.fr       */
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
		return ft_printf_puthex((unsigned long)va_arg(*args, unsigned int), HEX_LOWER_BASE);
	else if (c == 'X')
		return ft_printf_puthex((unsigned long)va_arg(*args, unsigned int), HEX_UPPER_BASE);
	else if (c == 'p')
		return ft_printf_putptr((unsigned long *)va_arg(*args, void *), HEX_LOWER_BASE);
	else if (c == 'u')
		return ft_printf_putunsign(va_arg(*args, unsigned int));
	else if (c == '%')
		return ft_printf_putchar('%');
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
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += input_process(str[i], &args);
		}
		else
			count += ft_printf_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);

}
 //int main(void)
 //{
// 	// int a = 10;
// 	// printf("Addess of a = %p\n", &a);
// 	// ft_printf("\nWelcome %c. %s in Codam. %i is your login time %x and %X hexadecimal of logtime\n", 'A', "Chowdhury", 400, 255, 255);
// 	// ft_printf("\n My own addess of a = %p\n", &a);
// 	// ft_printf("\n %u",-1);
// 	// ft_printf("\n %%100 is my efforr");
// 	// ft_printf("\n %%%u my pass");
// 	//printf("\n %s my pass original", );
// 	//ft_printf("Welcome %x in Codam\n", 255);
// 	//ft_printf("Welcome %c. in Codam\n", 'A');

// 	printf(" ft_printf(NULL) = %d\n", ft_printf(" %p ", NULL));
// 	printf("\n");
// 	printf("\n ft_printf((void *)42, NULL) = %d\n", ft_printf(" %p %p ", (void *)42, NULL));
// 	printf("\n=============================\n");

// 	printf(" printf(NULL) = %d\n", printf(" %p ", NULL));
// 	printf("\n");
// 	printf("\n printf((void *)42, NULL) = %d\n", printf(" %p %p ", (void *)42, NULL));
//printf(" %p ", NULL);
// 	printf("\n");
// 	//printf(" %p %p ", (void *)42, NULL);


 //}