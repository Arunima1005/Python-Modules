/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:06:14 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/17 17:03:44 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
// #include "../ft_memmove.c"

// int main(void)
// {
// 	char src[] =  "ABCDEF";
// 	char src1[] =  "ABCDEFGHIJ";
// 	char dest[20];
// 	char dest1[20];

// 	ft_memmove(src+3,src,strlen(src));
// 	memmove(src+3,src,strlen(src));

// 	printf("source = %s\n", src);

// 	ft_memmove(dest,src1,8);
// 	memmove(dest1,src1,8);
// 	printf("own function = %s\n", dest);
// 	printf("original one = %s\n", dest1);
// }

#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_buffer(unsigned char *buf, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		printf("%02X ", buf[i]);
		i++;
	}
	printf("\n");
}

void run_test(const char *desc, void *dst1, void *dst2, const void *src1, const void *src2, size_t n)
{
	memmove(dst1, src1, n);
	ft_memmove(dst2, src2, n);

	printf("Test: %s\n", desc);

	printf("memmove:    ");
	print_buffer(dst1, 20);

	printf("ft_memmove: ");
	print_buffer(dst2, 20);

	if (memcmp(dst1, dst2, 20) == 0)
		printf("Result: OK\n");
	else
		printf("Result: FAIL\n");

	printf("------------------------------\n");
}

int main(void)
{
	unsigned char src[20];
	unsigned char dest1[20];
	unsigned char dest2[20];

	size_t i = 0;

	/* initialize memory */
	while (i < 20)
	{
		src[i] = i + 1;
		dest1[i] = 0;
		dest2[i] = 0;
		i++;
	}

	/* 1. Normal copy */
	run_test("Normal copy", dest1, dest2, src, src, 10);

	/* reset */
	memset(dest1, 0, 20);
	memset(dest2, 0, 20);

	/* 2. Full buffer */
	run_test("Full buffer copy", dest1, dest2, src, src, 20);

	memset(dest1, 0, 20);
	memset(dest2, 0, 20);

	/* 3. n = 0 */
	run_test("n = 0", dest1, dest2, src, src, 0);

	memset(dest1, 0, 20);
	memset(dest2, 0, 20);

	/* 4. overlap forward */
	char str1[20] = "Hello World";
	char str2[20] = "Hello World";

	memmove(str1 + 6, str1, 5);
	ft_memmove(str2 + 6, str2, 5);

	printf("Test: Overlap forward\n");
	printf("memmove:    %s\n", str1);
	printf("ft_memmove: %s\n", str2);
	printf("------------------------------\n");

	/* 6. Overlap backward */
	char str3[20] = "ABCDEFGHIJ";
	char str4[20] = "ABCDEFGHIJ";

	memmove(str3, str3 + 2, 5);
	ft_memmove(str4, str4 + 2, 5);

	printf("Test: Overlap backward\n");
	printf("memmove:    %s\n", str3);
	printf("ft_memmove: %s\n", str4);
	printf("------------------------------\n");

	/* 7. Same pointer */
	char same1[] = "SameMemory";
	char same2[] = "SameMemory";

	memmove(same1, same1, 5);
	ft_memmove(same2, same2, 5);

	printf("Test: Same pointer\n");
	printf("memmove:    %s\n", same1);
	printf("ft_memmove: %s\n", same2);
	printf("------------------------------\n");

	return 0;
}

/*

| Test             | Why it matters          |
| ---------------- | ----------------------- |
| Normal copy      | standard behavior       |
| Full buffer      | boundary condition      |
| `n = 0`          | should do nothing       |
| Binary data      | works on raw memory     |
| Overlap forward  | critical `memmove` case |
| Overlap backward | reverse copying         |
| Same pointer     | should remain unchanged |

gcc test_ft_memmove.c ../libft.a -I.. -o test_memmove
*/
