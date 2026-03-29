/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:30:20 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/24 13:13:11 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_puthex(unsigned long n, char *base)
{
    int count;

    count = 0;
    if (n >= 16)
        count += ft_printf_puthex(n / 16, base);
    count += ft_printf_putchar(base[n % 16]);    
	return (count);
}
