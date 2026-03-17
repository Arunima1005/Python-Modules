/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:12:55 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 18:32:08 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>    
#include "libft.h"      

void	test_case(const char *s1, const char *s2, size_t n)
{
	int	orig;
	int	ft;

	orig = strncmp(s1, s2, n);
	ft = ft_strncmp(s1, s2, n);

	printf("s1: \"%s\", s2: \"%s\", n: %zu\n", s1, s2, n);
	printf("strncmp: %d | ft_strncmp: %d", orig, ft);

	if ((orig == 0 && ft == 0) || (orig < 0 && ft < 0) || (orig > 0 && ft > 0))
		printf(" Correct \n");
	else
		printf(" Wrong \n");

	printf("----------------------------------------\n");
}

int	main(void)
{
	// Basic equal strings
	test_case("hello", "hello", 5);

	// Different strings
	test_case("hello", "world", 5);

	// Partial compare
	test_case("hello", "heyyy", 2);

	// n = 0
	test_case("hello", "world", 0);

	// One string shorter
	test_case("hello", "he", 5);
	test_case("he", "hello", 5);

	// Compare with null terminator boundary
	test_case("abc", "abc\0def", 7);

	// First char different
	test_case("abc", "xbc", 3);

	// Last char different within n
	test_case("abcd", "abce", 4);

	// n smaller than difference
	test_case("abcd", "abce", 3);

	// Empty strings
	test_case("", "", 5);

	// One empty string
	test_case("", "abc", 3);
	test_case("abc", "", 3);

	// Large n
	test_case("abc", "abc", 100);

	// Signed char edge case
	test_case("\200", "\0", 1);

	// Difference after several chars
	test_case("abcdef", "abcdez", 6);

	return (0);
}