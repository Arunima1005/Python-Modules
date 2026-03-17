/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:52:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 18:25:45 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"

// #include "../ft_strlen.c"

// #include "../ft_strrchr.c"

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "ABCDEFGHIJK";
// 	printf("%s\n",ft_strrchr(s,'F'));
// }

#include <stdio.h>
#include <string.h>
#include "libft.h"

/* Helper to print result */
void	print_result(const char *s, int c, char *ft, char *std)
{
	printf("Searching '%c' (%d) in \"%s\"\n",
		(c >= 32 && c <= 126) ? c : '.',
		c, s);

	printf("ft_strrchr: %s\n", ft ? ft : "NULL");
	printf("strrchr:    %s\n", std ? std : "NULL");

	if (ft == std)
		printf("OK\n\n");
	else
		printf("Mismatch\n\n");
}

int	main(void)
{
	printf("Testing ft_strrchr vs strrchr\n\n");

	/* Test 1: Normal case */
	print_result("Hello World", 'o',
		ft_strrchr("Hello World", 'o'),
		strrchr("Hello World", 'o'));

	/* Test 2: First character */
	print_result("Hello", 'H',
		ft_strrchr("Hello", 'H'),
		strrchr("Hello", 'H'));

	/* Test 3: Last character */
	print_result("Hello", 'o',
		ft_strrchr("Hello", 'o'),
		strrchr("Hello", 'o'));

	/* Test 4: Multiple occurrences */
	print_result("banana", 'a',
		ft_strrchr("banana", 'a'),
		strrchr("banana", 'a'));

	/* Test 5: Not found */
	print_result("Hello", 'x',
		ft_strrchr("Hello", 'x'),
		strrchr("Hello", 'x'));

	/* Test 6: Search for '\0' */
	print_result("Hello", '\0',
		ft_strrchr("Hello", '\0'),
		strrchr("Hello", '\0'));

	/* Test 7: Empty string */
	print_result("", 'a',
		ft_strrchr("", 'a'),
		strrchr("", 'a'));

	/* Test 8: Empty string + '\0' */
	print_result("", '\0',
		ft_strrchr("", '\0'),
		strrchr("", '\0'));

	return 0;
}