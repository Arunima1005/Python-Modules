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

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write(1,&c,1);
	return (1);
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
			//printf("print === %s\n", va_arg(args, char *));
			ft_putchar(va_arg(args, int));
		}
		else
		{
			write(1,&str[i],1);
			count ++;
		}
		
		i++;
	}
	return (0);

}


int main(void)
{
	ft_printf("Arunima %c Chowdhury", 'a');
}