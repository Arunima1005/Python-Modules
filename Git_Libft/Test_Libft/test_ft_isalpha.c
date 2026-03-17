/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:08:22 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 15:02:21 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h> 
#include "libft.h"

void	test_char(int c)
{
	printf("Testing: ");
	if (c >= 32 && c <= 126)
		printf("'%c'", c);
	else
		printf("ASCII(%d)", c);

	printf(" | ft_isalpha: %d | isalpha: %d\n",
		ft_isalpha(c), isalpha(c));
}

int	main(void)
{
	// Lowercase letters
	for (int c = 'a'; c <= 'z'; c++)
		test_char(c);

	// Uppercase letters
	for (int c = 'A'; c <= 'Z'; c++)
		test_char(c);

	// Digits
	for (int c = '0'; c <= '9'; c++)
		test_char(c);

	// Special characters
	char specials[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
	for (int i = 0; i < 10; i++)
		test_char(specials[i]);

	// Edge ASCII values
	test_char(0);     // NULL
	test_char(127);   // DEL
	test_char(-1);    // EOF-like
	test_char(255);   // Extended ASCII

	return (0);
}