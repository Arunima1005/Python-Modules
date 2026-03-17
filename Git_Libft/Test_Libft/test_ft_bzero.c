/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:42:10 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 16:50:09 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "../libft.h"
// #include "../ft_bzero.c"

// #include <stdio.h>

// int main(void)
// {
// 	char s[20] = "abcdxsdf cddd";
// 	printf("Before = %s\n", s);
// 	ft_bzero(s,3);
// 	printf("After = %s", s);
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

/* Helper: compare memory */
int compare_buffers(unsigned char *a, unsigned char *b, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			return (0);
	}
	return (1);
}

/* Helper: print memory */
void print_buffer(unsigned char *buf, size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%02X ", buf[i]);
	printf("\n");
}

int	main(void)
{
	printf("Testing ft_bzero vs bzero\n\n");

	/* Test 1: Basic */
	{
		unsigned char a[10] = "abcdefghi";
		unsigned char b[10] = "abcdefghi";

		ft_bzero(a, 10);
		bzero(b, 10);

		printf("Test 1 (full zero):\n");
		print_buffer(a, 10);
		printf(compare_buffers(a, b, 10) ? "OK\n\n" : "Mismatch\n\n");
	}

	/* Test 2: Partial zero */
	{
		unsigned char a[10] = "abcdefghi";
		unsigned char b[10] = "abcdefghi";

		ft_bzero(a, 5);
		bzero(b, 5);

		printf("Test 2 (partial zero):\n");
		print_buffer(a, 10);
		printf(compare_buffers(a, b, 10) ? "OK\n\n" : "Mismatch\n\n");
	}

	/* Test 3: n = 0 */
	{
		unsigned char a[5] = "test";
		unsigned char b[5] = "test";

		ft_bzero(a, 0);
		bzero(b, (0));

		printf("Test 3 (n = 0):\n");
		print_buffer(a, 5);
		printf(compare_buffers(a, b, 5) ? "OK\n\n" : "Mismatch\n\n");
	}

	return 0;
}