/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:44:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 16:18:02 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft.h"
// #include "../ft_memset.c"

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char b[20] = "abcd fffff abcd";
// 	ft_memset(b + 2,'*',5);
// 	printf("%s", b);
// 	printf("\n ----------------------- \n");
// 	char a[20] = "abcd fffff abcd";
// 	memset(a + 2,'*',5);
// 	printf("%s", a);
// }
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

/* Helper to compare memory */
int compare_buffers(unsigned char *a, unsigned char *b, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			return (0);
	}
	return (1);
}

/* Helper to print memory */
void print_buffer(unsigned char *buf, size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%c ", buf[i]);
	printf("\n");
}

int	main(void)
{
	printf("Testing ft_memset vs memset\n\n");

	/* Test 1: Basic */
	{
		unsigned char a[10];
		unsigned char b[10];

		ft_memset(a, 'A', 10);
		memset(b, 'A', 10);

		printf("Test 1 (fill with 'A'):\n");
		print_buffer(a, 10);
		printf(compare_buffers(a, b, 10) ? "OK\n\n" : "Mismatch\n\n");
	}

	/* Test 2: Zero fill */
	{
		unsigned char a[10];
		unsigned char b[10];

		ft_memset(a, 0, 10);
		memset(b, 0, 10);

		printf("Test 2 (fill with 0):\n");
		for (size_t i = 0; i < 10; i++)
		printf("%d ", a[i]);
        printf("\n");
		printf(compare_buffers(a, b, 10) ? "OK\n\n" : "Mismatch\n\n");
	}

	/* Test 3: Partial fill */
	{
		unsigned char a[10] = "abcdefghi";
		unsigned char b[10] = "abcdefghi";

		ft_memset(a, 'X', 5);
		memset(b, 'X', 5);

		printf("Test 3 (partial overwrite):\n");
		print_buffer(a, 10);
		printf(compare_buffers(a, b, 10) ? "OK\n\n" : "Mismatch\n\n");
	}

	/* Test 4: n = 0 (should do nothing) */
	{
		unsigned char a[5] = "test";
		unsigned char b[5] = "test";
        size_t n = 0;
		ft_memset(a, 'Z', n);
		memset(b, 'Z', n);

		printf("Test 4 (n = 0):\n");
		print_buffer(a, 5);
		printf(compare_buffers(a, b, 5) ? "OK\n\n" : "Mismatch\n\n");
	}
	return 0;
}