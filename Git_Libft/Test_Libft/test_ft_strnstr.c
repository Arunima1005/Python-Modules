/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:13:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 18:57:48 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>   
#include <bsd/string.h> 
#include "libft.h"

void	test_case(const char *big, const char *little, size_t len)
{
	char	*orig;
	char	*ft;

	orig = strnstr(big, little, len);
	ft = ft_strnstr(big, little, len);

	printf("big: \"%s\", little: \"%s\", len: %zu\n", big, little, len);
	printf("strnstr: %s\n", orig ? orig : "NULL");
	printf("ft_strnstr: %s\n", ft ? ft : "NULL");

	if ((orig == NULL && ft == NULL) || (orig && ft && strcmp(orig, ft) == 0))
		printf(" OK\n");
	else
		printf(" MISMATCH\n");

	printf("----------------------------------------\n");
}

int	main(void)
{
	// 1. Basic match
	test_case("hello world", "world", 11);

	// 2. Not found
	test_case("hello world", "abc", 11);

	// 3. Empty little
	test_case("hello", "", 5);

	// 4. len = 0
	test_case("hello", "he", 0);

	// 5. Partial match within len
	test_case("hello world", "world", 8);

	// 6. Exact boundary match
	test_case("hello world", "world", 11);

	// 7. Match at start
	test_case("abcdef", "abc", 6);

	// 8. Match at end
	test_case("abcdef", "def", 6);

	// 9. little longer than big
	test_case("abc", "abcdef", 6);

	// 10. big empty
	test_case("", "abc", 3);

	// 11. both empty
	test_case("", "", 3);

	// 12. repeated pattern
	test_case("aaaaaa", "aaa", 6);

	// 13. match but exceeds len
	test_case("abcdef", "def", 5);

	// 14. match exactly at len boundary
	test_case("abcdef", "def", 6);

	// 15. overlapping patterns
	test_case("abababab", "abab", 8);

	// 16. single char match
	test_case("abc", "b", 3);

	// 17. single char not found
	test_case("abc", "z", 3);


	return (0);
}