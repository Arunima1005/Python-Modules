/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:14:35 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 20:45:26 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"
// #include "../ft_strlcat.c"
// #include "../ft_strlen.c"

// #include <stdio.h>
// int main(void)
// {
// 	char dst[10] = "hello";
// 	printf("%zu\n",ft_strlcat(dst, "world", sizeof(dst)));
// 	printf("%s\n", dst);
// 	char dst1[18] = "hello";
// 	printf("%zu\n",ft_strlcat(dst1, "world", sizeof(dst1)));
// 	printf("%s\n", dst1);
// }


#include <stdio.h>
#include <string.h>
#include <bsd/string.h> // for original strlcat (Linux: -lbsd)
#include "libft.h"

void	run_test(char *desc, char *dst1, char *dst2, const char *src, size_t size)
{
	size_t	ret1;
	size_t	ret2;

	printf("=== %s ===\n", desc);

	ret1 = ft_strlcat(dst1, src, size);
	ret2 = strlcat(dst2, src, size);

	printf("ft_strlcat -> dst: \"%s\", ret: %zu\n", dst1, ret1);
	printf("strlcat    -> dst: \"%s\", ret: %zu\n", dst2, ret2);

	if (ret1 == ret2 && strcmp(dst1, dst2) == 0)
		printf("OK\n\n");
	else
		printf("MISMATCH\n\n");
}

int	main(void)
{
	// 1. Normal case
	char d1[20] = "Hello ";
	char d2[20] = "Hello ";
	run_test("Normal append", d1, d2, "World", 20);

	// 2. Exact fit
	char d3[12] = "Hello ";
	char d4[12] = "Hello ";
	run_test("Exact fit", d3, d4, "World", 12);

	// 3. Buffer too small (truncate)
	char d5[10] = "Hello ";
	char d6[10] = "Hello ";
	run_test("Truncation", d5, d6, "World!!!", 10);

	// 4. size < dstlen
	char d7[20] = "HelloWorld";
	char d8[20] = "HelloWorld";
	run_test("size < dstlen", d7, d8, "!!!", 5);

	// 5. size == 0
	char d9[20] = "Hello";
	char d10[20] = "Hello";
	run_test("size = 0", d9, d10, "World", 0);

	// 6. Empty src
	char d11[20] = "Hello";
	char d12[20] = "Hello";
	run_test("Empty src", d11, d12, "", 20);

	// 7. Empty dst
	char d13[20] = "";
	char d14[20] = "";
	run_test("Empty dst", d13, d14, "World", 20);

	// 8. size == dstlen + 1 (only null terminator fits)
	char d15[7] = "Hello";
	char d16[7] = "Hello";
	run_test("Only null fits", d15, d16, "World", 6);

	return (0);
}