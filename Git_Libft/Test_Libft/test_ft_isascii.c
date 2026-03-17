/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:08:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 15:32:14 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h> 
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

void	test(int c)
{
	int my = ft_isascii(c);
	int original = isascii(c);

	printf("Input: %4d | char: '%c' | ft_isascii: %d | original: %d %s\n",
		c,
		(c >= 32 && c <= 126) ? c : '.',
		my,
		original,
		(my == original) ? "Correct" : "Wrong");
}

int	main(void)
{
	printf("=== ASCII TESTS ===\n\n");

	// 1. Valid ASCII range
	for (int i = 0; i <= 127; i++)
		test(i);

	// 2. Just outside boundaries
	test(-1);
	test(128);
	test(129);

	// 3. Large values
	test(255);
	test(1000);
	test(-1000);

	return (0);
}