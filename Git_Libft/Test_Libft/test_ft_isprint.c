/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:09:09 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 15:38:57 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	int i;

	printf("Testing ft_isprint vs isprint\n\n");

	// /* Test full range of signed char + extra */
	// for (i = -128; i <= 255; i++)
	// {
	// 	int ft = ft_isprint(i);
	// 	int std = isprint(i);

	// 	/* Normalize standard return (non-zero -> 1) */
	// 	std = (std != 0);

	// 	if (ft != std)
	// 	{
	// 		printf("Mismatch at %d: ft_isprint=%d, isprint=%d\n", i, ft, std);
	// 	}
	// }

	printf("\nBasic edge cases:\n");

	/* Explicit edge cases */
	int test_cases[] = {
		-1,        // EOF-like
		0,         // NULL
		31,        // just below printable
		32,        // space (printable start)
		126,       // '~' (printable end)
		127,       // DEL (non-printable)
		128,       // extended
		255        // max unsigned char
	};

	int size = sizeof(test_cases) / sizeof(test_cases[0]);

	for (int j = 0; j < size; j++)
	{
		int c = test_cases[j];
		printf("c=%d -> ft_isprint:%d | isprint:%d\n",
			c,
			ft_isprint(c),
			isprint(c) != 0);
	}

	return 0;
}