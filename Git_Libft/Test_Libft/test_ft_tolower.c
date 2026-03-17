/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:14:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 17:44:19 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	int i;

	printf("Testing ft_tolower vs tolower\n\n");

	/* Explicit edge cases */
	int tests[] = {
		'A', 'Z',     // uppercase boundaries
		'a', 'z',     // lowercase
		'0',          // digit
		'$',          // symbol
		'\n',         // control char
		127,          // DEL
		128,          // extended
		255           // max unsigned char
	};

	int size = sizeof(tests) / sizeof(tests[0]);

	printf("Edge cases:\n");

	for (int j = 0; j < size; j++)
	{
		int c = tests[j];

		printf("c=%d ('%c') -> ft_tolower:%d ('%c') | original:%d ('%c')\n",
			c,
			(c >= 32 && c <= 126) ? c : '.',
			ft_tolower(c),
			(ft_tolower(c) >= 32 && ft_tolower(c) <= 126) ? ft_tolower(c) : '.',
			tolower((unsigned char)c),
			(tolower((unsigned char)c) >= 32 && tolower((unsigned char)c) <= 126) ? tolower((unsigned char)c) : '.'
		);
	}

	return 0;
}