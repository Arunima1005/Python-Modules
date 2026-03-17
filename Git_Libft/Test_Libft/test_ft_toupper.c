/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:14:33 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 17:40:04 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	int i;

	printf("Testing ft_toupper vs toupper\n\n");

	/* Explicit edge cases */
	int tests[] = {
		'a', 'z',     // lowercase boundaries
		'A', 'Z',     // uppercase
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

		printf("c=%d ('%c') -> ft_touuper:%d ('%c') | original:%d ('%c')\n",
			c,
			(c >= 32 && c <= 126) ? c : '.',
			ft_toupper(c),
			(ft_toupper(c) >= 32 && ft_toupper(c) <= 126) ? ft_toupper(c) : '.',
			toupper((unsigned char)c),
			(toupper((unsigned char)c) >= 32 && toupper((unsigned char)c) <= 126) ? toupper((unsigned char)c) : '.'
		);
	}

	return 0;
}