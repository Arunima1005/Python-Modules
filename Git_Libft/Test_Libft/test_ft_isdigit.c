/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:51:22 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 15:22:45 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ft_isdigit.c"
// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
// 	printf("%d", ft_isdigit(0));
// 	printf("\n");
// 	printf("%d", ft_isdigit('V'));
// 	printf("\n");
// 	printf("%d", ft_isdigit(49));
// 	printf("\n");
	
// 	printf("---------------------------------------------\n");

// 	printf("%d", ft_isdigit(0));
// 	printf("\n");
// 	printf("%d", ft_isdigit('V'));
// 	printf("\n");
// 	printf("%d", ft_isdigit(49));
// }

#include <stdio.h>
#include <ctype.h> // for isdigit
#include "libft.h"


// void	test(int c)
// {
// 	int my = ft_isdigit(c);
// 	int original = isdigit(c);

// 	printf("Input: %4d | char: '%c' | ft_isdigit: %d | isdigit: %d %s\n",
// 		c,
// 		(c >= 32 && c <= 126) ? c : '.',
// 		my,
// 		original,
// 		(my == (original != 0)) ? "Correct" : "Wrong");
// }

void	test(int c)
{
	int my = ft_isdigit(c);

	printf("Input: %4d | char: '%c' | ft_isdigit: %d\n",
		c,
		(c >= 32 && c <= 126) ? c : '.',
		my);
}

int	main(void)
{
	printf("=== DIGIT TESTS ===\n");

	// 1. Digits
	for (int i = '0'; i <= '9'; i++)
		test(i);

	// 2. Letters
	test('a');
	test('Z');

	// 3. Symbols
	test('!');
	test('@');
	test(' ');

	// 4. Boundary values
	test('0' - 1); // '/'
	test('9' + 1); // ':'

	// 5. Extended / edge cases
	test(-1);
	test(0);
	test(127);
	test(255);
	test(1000);

	return (0);
}