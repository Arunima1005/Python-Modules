/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:07:07 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 15:26:23 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h> // isalnum
#include "libft.h"


void	test(int c)
{
	int my = ft_isalnum(c);
	
	printf("Input: %4d | char: '%c' | ft: %d \n",
		c,
		(c >= 32 && c <= 126) ? c : '.',
		my);
}

int	main(void)
{
	printf("=== ALNUM TESTS ===\n\n");

	// 1. Digits
	for (int i = '0'; i <= '9'; i++)
		test(i);

	// 2. Lowercase letters
	for (int i = 'a'; i <= 'z'; i++)
		test(i);

	// 3. Uppercase letters
	for (int i = 'A'; i <= 'Z'; i++)
		test(i);

	// 4. Symbols (should be false)
	test('!');
	test('@');
	test('#');
	test(' ');
	test('\n');

	// 5. Boundary characters
	test('0' - 1); // '/'
	test('9' + 1); // ':'
	test('A' - 1); // '@'
	test('Z' + 1); // '['
	test('a' - 1); // '`'
	test('z' + 1); // '{'

	// 6. Edge / extreme values
	test(-1);
	test(0);
	test(127);
	test(255);
	test(1000);

	return (0);
}