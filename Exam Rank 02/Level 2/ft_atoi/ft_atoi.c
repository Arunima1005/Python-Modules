/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:12:45 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/17 17:22:21 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi("1234"));
	printf("%d\n", ft_atoi("-1234"));
	printf("%d\n", ft_atoi("123444444"));
	printf("%d\n", ft_atoi("0"));
}