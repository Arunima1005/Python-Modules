/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:51:21 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 12:25:34 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble_fd(double num, int fd)
{
	int	integer;
	int	frac;

	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	integer = (int)num;
	frac = (int)((num - integer) * 100 + 0.5);
	if (frac == 100)
	{
		integer += 1;
		frac = 0;
	}
	ft_putnbr_fd(integer, fd);
	ft_putchar_fd('.', fd);
	if (frac < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(frac, fd);
}
