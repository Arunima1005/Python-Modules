/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:33:55 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 15:41:49 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"
// #include "../ft_strlen.c"

// #include <stdio.h>

// int main(void)
// {
// 	printf("%lu", ft_strlen("abcdxsdf cddd"));
// }

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	const char *tests[] = {
		"",                         // empty string
		"a",                        // single char
		"Hello",                    // normal string
		"Hello\0World",             // embedded null (should stop at \0)
		"   ",                      // spaces
		"\n\t",                     // escape characters
		"1234567890",               // numbers
		"!@#$%^&*()",               // symbols
		"My name is Arunima Chowdhury", // long string
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);

	printf("Testing ft_strlen vs strlen\n\n");

	for (int i = 0; i < num_tests; i++)
	{
		size_t ft = ft_strlen(tests[i]);
		size_t std = strlen(tests[i]);

		printf("Test %d:\n", i + 1);
		printf("String: \"%s\"\n", tests[i]);
		printf("ft_strlen: %zu | strlen: %zu\n", ft, std);

		if (ft != std)
			printf("Mismatch!\n");
		else
			printf("OK\n");

		printf("\n");
	}

	/* Additional stress test */
	printf("Stress test (large string):\n");

	char big[10000];
	for (int i = 0; i < 9999; i++)
		big[i] = 'a';
	big[9999] = '\0';

	printf("ft_strlen: %zu | strlen: %zu\n",
		ft_strlen(big), strlen(big));

	return 0;
}