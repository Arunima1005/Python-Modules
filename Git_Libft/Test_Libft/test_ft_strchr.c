/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:58:21 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 18:03:10 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libft.h"

/* Helper to print result */
void	print_result(const char *s, int c, char *ft, char *std)
{
	printf("Searching '%c' (%d) in \"%s\"\n",
		(c >= 32 && c <= 126) ? c : '.',
		c, s);

	printf("ft_strchr:  %s\n", ft ? ft : "NULL");
	printf("strchr:     %s\n", std ? std : "NULL");

	if (ft == std)
		printf(" OK\n\n");
	else
		printf(" Mismatch\n\n");
}

int	main(void)
{
	printf("Testing ft_strchr vs strchr\n\n");

	/* Test 1: Normal case */
	print_result("Hello World", 'o',
		ft_strchr("Hello World", 'o'),
		strchr("Hello World", 'o'));

	/* Test 2: First character */
	print_result("Hello", 'H',
		ft_strchr("Hello", 'H'),
		strchr("Hello", 'H'));

	/* Test 3: Last character */
	print_result("Hello", 'o',
		ft_strchr("Hello", 'o'),
		strchr("Hello", 'o'));

	/* Test 4: Not found */
	print_result("Hello", 'x',
		ft_strchr("Hello", 'x'),
		strchr("Hello", 'x'));

	/* Test 5: Search for '\0' */
	print_result("Hello", '\0',
		ft_strchr("Hello", '\0'),
		strchr("Hello", '\0'));

	/* Test 6: Empty string */
	print_result("", 'a',
		ft_strchr("", 'a'),
		strchr("", 'a'));

	/* Test 7: Empty string + '\0' */
	print_result("", '\0',
		ft_strchr("", '\0'),
		strchr("", '\0'));

	/* Test 8: Multiple occurrences */
	print_result("banana", 'a',
		ft_strchr("banana", 'a'),
		strchr("banana", 'a'));

	return 0;
}