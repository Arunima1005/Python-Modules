/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:30:03 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 16:58:28 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
// #include "../ft_memcpy.c"

// int main(void)
// {
// 	char src[] =  "hello world";
// 	char dest[20];
// 	char dest1[20];

// 	ft_memcpy(dest,src,strlen(src));
// 	memcpy(dest1,src,strlen(src));

// 	printf("source = %s\n", src);
// 	printf("own function = %s\n", dest);
// 	printf("original one = %s\n", dest1);
// }


#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_bytes(unsigned char *buf, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		printf("%02X ", buf[i]);
		i++;
	}
	printf("\n");
}

void run_test(const char *desc, void *dst1, void *dst2, const void *src, size_t n)
{
	memcpy(dst1, src, n);
	ft_memcpy(dst2, src, n);

	printf("Test: %s\n", desc);

	printf("memcpy:    ");
	print_bytes(dst1, 20);

	printf("ft_memcpy: ");
	print_bytes(dst2, 20);

	if (memcmp(dst1, dst2, 20) == 0)
		printf("Result: OK\n");
	else
		printf("Result: FAIL\n");

	printf("-----------------------------\n");
}

int main(void)
{
	unsigned char dest1[20];
	unsigned char dest2[20];
	unsigned char src[20];

	size_t i = 0;

	/* initialize source */
	while (i < 20)
	{
		src[i] = i + 1;
		dest1[i] = 0;
		dest2[i] = 0;
		i++;
	}

	/* 1. Normal copy */
	run_test("Normal copy", dest1, dest2, src, 10);

	/* reset */
	memset(dest1, 0, 20);
	memset(dest2, 0, 20);

	/* 2. Copy full buffer */
	run_test("Full buffer copy", dest1, dest2, src, 20);

	memset(dest1, 0, 20);
	memset(dest2, 0, 20);

	/* 3. n = 0 */
	run_test("n = 0", dest1, dest2, src, 0);

	memset(dest1, 0, 20);
	memset(dest2, 0, 20);

	/* Overlapping memory (undefined behavior for memcpy) */
	// char overlap1[] = "123456789";
	// char overlap2[] = "123456789";

	// memcpy(overlap1 + 2, overlap1, 5);
	// ft_memcpy(overlap2 + 2, overlap2, 5);

	// printf("Test: Overlap memory (undefined behavior)\n");
	// printf("memcpy:    %s\n", overlap1);
	// printf("ft_memcpy: %s\n", overlap2);
	// printf("-----------------------------\n");

	return 0;
}

/*

| Test               | What it checks       |
| ------------------ | -------------------- |
| Normal copy        | basic functionality  |
| Full buffer        | boundary size        |
| `n = 0`            | should do nothing    |
| Overlapping memory | undefined behavior   |
gcc test_ft_memcpy.c ../libft.a -I.. -o test_memcpy

*/