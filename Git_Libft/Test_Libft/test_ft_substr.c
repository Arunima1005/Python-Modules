/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:28:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 16:54:01 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"
// #include "../ft_strlcpy.c"
// #include "../ft_strlen.c"
// #include "../ft_substr.c"
// #include "../ft_strdup.c"

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "ABCDEFGHIJK";
// 	printf("%s\n",ft_substr(s,19,10));
// }


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void run_test(const char *desc, char const *s, unsigned int start, size_t len)
{
	char *result;

	printf("Test: %s\n", desc);
	printf("Input: \"%s\", start=%u, len=%zu\n", s ? s : "NULL", start, len);

	result = ft_substr(s, start, len);

	if (!result)
		printf("Result: NULL\n");
	else
	{
		printf("Result: \"%s\"\n", result);
		free(result);
	}

	printf("----------------------------\n");
}

int main(void)
{
	/* 1. Normal case */
	run_test("Normal substring", "Hello World", 6, 5);

	/* 2. Start = 0 */
	run_test("Start at beginning", "Hello", 0, 3);

	/* 3. len smaller than remaining string */
	run_test("Partial substring", "abcdef", 2, 2);

	/* 4. len larger than remaining string */
	run_test("Length larger than string", "abcdef", 3, 50);

	/* 5. start beyond string length */
	run_test("Start beyond string", "abcdef", 20, 5);

	/* 6. start exactly at end */
	run_test("Start at string end", "abcdef", 6, 3);

	/* 7. empty string */
	run_test("Empty string", "", 0, 5);

	/* 8. len = 0 */
	run_test("Length zero", "Hello", 2, 0);

	/* 9. start inside but len = 1 */
	run_test("Single character", "Hello", 1, 1);

	/* 10. NULL input */
	run_test("NULL input", NULL, 2, 5);

	return 0;
}


/*
| Case                  | Example               | Expected Behavior |
| --------------------- | --------------------- | ----------------- |
| Normal substring      | `"Hello World", 6, 5` | `"World"`         |
| Start = 0             | `"Hello", 0, 3`       | `"Hel"`           |
| Partial substring     | `"abcdef", 2, 2`      | `"cd"`            |
| `len` > remaining     | `"abcdef", 3, 50`     | `"def"`           |
| `start` beyond string | `"abcdef", 20, 5`     | `""`              |
| `start` at end        | `"abcdef", 6, 3`      | `""`              |
| Empty string          | `""`                  | `""`              |
| `len = 0`             | `"Hello", 2, 0`       | `""`              |
| Single character      | `"Hello", 1, 1`       | `"e"`             |
| `NULL` input          | `NULL`                | `NULL`            |

gcc test_ft_substr.c ../libft.a -I.. -o test_substr

*/