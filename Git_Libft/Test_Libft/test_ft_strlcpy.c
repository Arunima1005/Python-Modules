/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:12:06 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 17:35:44 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>

#include "libft.h"


/* Helper to print buffer safely */
void	print_result(const char *label, char *dst, size_t ret)
{
	printf("%s\n", label);
	printf("dst: \"%s\"\n", dst);
	printf("return: %zu\n\n", ret);
}

int	main(void)
{
	printf("Testing ft_strlcpy vs strlcpy\n\n");

	/* Test 1: Normal copy */
	{
		char a[20];
		char b[20];

		size_t r1 = ft_strlcpy(a, "Hello", sizeof(a));
		size_t r2 = strlcpy(b, "Hello", sizeof(b));

		print_result("Test 1 (normal)", a, r1);
		printf("%s\n\n", (strcmp(a, b) == 0 && r1 == r2) ? "OK" : "Mismatch");
	}

	/* Test 2: size = 0 */
	{
		char a[20] = "XXXX";
		char b[20] = "XXXX";

		size_t r1 = ft_strlcpy(a, "Hello", 0);
		size_t r2 = strlcpy(b, "Hello", 0);

		print_result("Test 2 (size = 0)", a, r1);
		printf("%s\n\n", (strcmp(a, b) == 0 && r1 == r2) ? "OK" : "Mismatch");
	}

	/* Test 3: size = 1 */
	{
		char a[20];
		char b[20];

		size_t r1 = ft_strlcpy(a, "Hello", 1);
		size_t r2 = strlcpy(b, "Hello", 1);

		print_result("Test 3 (size = 1)", a, r1);
		printf("%s\n\n", (strcmp(a, b) == 0 && r1 == r2) ? "OK" : "Mismatch");
	}

	/* Test 4: truncation */
	{
		char a[5];
		char b[5];

		size_t r1 = ft_strlcpy(a, "HelloWorld", sizeof(a));
		size_t r2 = strlcpy(b, "HelloWorld", sizeof(b));

		print_result("Test 4 (truncation)", a, r1);
		printf("%s\n\n", (strcmp(a, b) == 0 && r1 == r2) ? "OK" : "Mismatch");
	}

	/* Test 5: exact fit */
	{
		char a[6];
		char b[6];

		size_t r1 = ft_strlcpy(a, "Hello", sizeof(a));
		size_t r2 = strlcpy(b, "Hello", sizeof(b));

		print_result("Test 5 (exact fit)", a, r1);
		printf("%s\n\n", (strcmp(a, b) == 0 && r1 == r2) ? "OK" : "Mismatch");
	}

	/* Test 6: empty src */
	{
		char a[10];
		char b[10];

		size_t r1 = ft_strlcpy(a, "", sizeof(a));
		size_t r2 = strlcpy(b, "", sizeof(b));

		print_result("Test 6 (empty src)", a, r1);
		printf("%s\n\n", (strcmp(a, b) == 0 && r1 == r2) ? "OK" : "Mismatch");
	}

	return 0;
}