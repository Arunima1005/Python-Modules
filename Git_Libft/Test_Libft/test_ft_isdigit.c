/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:51:22 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/10 17:28:26 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_isdigit.c"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("%d", ft_isdigit(0));
	printf("\n");
	printf("%d", ft_isdigit('V'));
	printf("\n");
	printf("%d", ft_isdigit(49));
	printf("\n");
	printf("%d", ft_isdigit(65));
	printf("\n");
	
	printf("---------------------------------------------\n");

	printf("%d", ft_isdigit(0));
	printf("\n");
	printf("%d", ft_isdigit('V'));
	printf("\n");
	printf("%d", ft_isdigit(49));
	printf("\n");
	printf("%d", ft_isdigit(65));
	printf("\n");
}