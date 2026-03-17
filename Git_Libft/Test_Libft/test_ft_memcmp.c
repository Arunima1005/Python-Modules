/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:09:55 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/13 17:09:56 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void run_test(const char *desc, const void *s1, const void *s2, size_t n)
{
	int std;
	int ft;

	std = memcmp(s1, s2, n);
	ft = ft_memcmp(s1, s2, n);

	printf("Test: %s\n", desc);
	printf("memcmp:    %d\n", std);
	printf("ft_memcmp: %d\n", ft);

	if ((std == 0 && ft == 0) || (std < 0 && ft < 0) || (std > 0 && ft > 0))
		printf("Result: OK\n");
	else
		printf("Result: FAIL\n");

	printf("-----------------------------\n");
}

int main(void)
{
	char a1[] = "Hello";
	char a2[] = "Hello";
	char b1[] = "Hello";
	char b2[] = "Hella";
	char c1[] = "abc";
	char c2[] = "abd";

	unsigned char bin1[] = {1,2,3,4,5};
	unsigned char bin2[] = {1,2,3,4,6};

	/* 1. identical strings */
	run_test("Identical strings", a1, a2, 5);

	/* 2. difference at last char */
	run_test("Last character different", b1, b2, 5);

	/* 3. difference in middle */
	run_test("Middle difference", c1, c2, 3);

	/* 4. n = 0 */
	run_test("n = 0", a1, b1, 0);

	/* 5. compare only first bytes */
	run_test("Compare first 2 bytes", b1, b2, 2);

	/* 6. binary data */
	run_test("Binary data", bin1, bin2, 5);

	/* 7. binary equal partial */
	run_test("Binary equal first 4", bin1, bin2, 4);

	/* 8. empty strings */
	run_test("Empty strings", "", "", 1);

	/* 9. compare with '\\0' inside */
	char d1[] = {'A','B','\0','C'};
	char d2[] = {'A','B','\0','D'};
	run_test("Null inside memory", d1, d2, 4);

	return 0;
}

/*

| Test                 | What it checks             |
| -------------------- | -------------------------- |
| identical memory     | return `0`                 |
| difference at end    | positive/negative result   |
| difference in middle | correct early stop         |
| `n = 0`              | must return `0`            |
| partial comparison   | stops before difference    |
| binary data          | works for non-strings      |
| equal prefix         | correct behavior           |
| empty strings        | valid memory               |
| `'\0'` inside        | memcmp is not string-based |

gcc test_ft_memcmp.c ../libft.a -I.. -o test_memcmp

*/