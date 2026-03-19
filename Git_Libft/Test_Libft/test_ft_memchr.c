/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:09:36 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/13 17:09:37 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
 #include "../libft.h"

int main(void)
{
	char str1[] = "Hello World";
	char str2[] = "abc\0def";
	char str3[] = "";
	char str4[] = "aaaaaa";

	void *ft;
	void *orig;

	printf("TEST 1: Normal search\n");
	ft = ft_memchr(str1, 'o', 11);
	orig = memchr(str1, 'o', 11);
	printf("ft_memchr: %s\n", ft ? (char *)ft : "NULL");
	printf("memchr   : %s\n\n", orig ? (char *)orig : "NULL");

	printf("TEST 2: Character not found\n");
	ft = ft_memchr(str1, 'z', 11);
	orig = memchr(str1, 'z', 11);
	printf("ft_memchr: %p\n", ft);
	printf("memchr   : %p\n\n", orig);

	printf("TEST 3: Search with n smaller than position\n");
	ft = ft_memchr(str1, 'W', 5);
	orig = memchr(str1, 'W', 5);
	printf("ft_memchr: %p\n", ft);
	printf("memchr   : %p\n\n", orig);

	printf("TEST 4: Search NULL terminator\n");
	ft = ft_memchr(str1, '\0', 12);
	orig = memchr(str1, '\0', 12);
	printf("ft_memchr: %p\n", ft);
	printf("memchr   : %p\n\n", orig);

	printf("TEST 5: String with internal NULL\n");
	ft = ft_memchr(str2, 'd', 7);
	orig = memchr(str2, 'd', 7);
	printf("ft_memchr: %p\n", ft);
	printf("memchr   : %p\n\n", orig);

	printf("TEST 6: n = 0\n");
	ft = ft_memchr(str1, 'H', 0);
	orig = memchr(str1, 'H', 0);
	printf("ft_memchr: %p\n", ft);
	printf("memchr   : %p\n\n", orig);

	printf("TEST 7: Empty string\n");
	ft = ft_memchr(str3, 'a', 1);
	orig = memchr(str3, 'a', 1);
	printf("ft_memchr: %p\n", ft);
	printf("memchr   : %p\n\n", orig);

	printf("TEST 8: Multiple matches\n");
	ft = ft_memchr(str4, 'a', 6);
	orig = memchr(str4, 'a', 6);
	printf("ft_memchr: %s\n", ft ? (char *)ft : "NULL");
	printf("memchr   : %s\n\n", orig ? (char *)orig : "NULL");

	printf("TEST 9: Search using integer value\n");
	ft = ft_memchr(str1, 111, 11); // ASCII 'o'
	orig = memchr(str1, 111, 11);
	printf("ft_memchr: %s\n", ft ? (char *)ft : "NULL");
	printf("memchr   : %s\n\n", orig ? (char *)orig : "NULL");

	return 0;
}*/

#include <stdio.h>
#include <string.h>
#include "libft.h"

void test_case(const void *s, int c, size_t n, const char *description)
{
    void *std;
    void *ft;

    std = memchr(s, c, n);
    ft = ft_memchr(s, c, n);

    printf("Test: %s\n", description);
    printf("memchr:    %p\n", std);
    printf("ft_memchr: %p\n", ft);

    if (std == ft)
        printf("Result: OK\n");
    else
        printf("Result: FAIL\n");

    printf("-------------------------\n");
}

int main(void)
{
    char str[] = "Hello World";
    char empty[] = "";

    /* 1. Character present */
    test_case(str, 'o', strlen(str), "Character exists");

    /* 2. Character not present */
    test_case(str, 'z', strlen(str), "Character not present");

    /* 3. Search first character */
    test_case(str, 'H', strlen(str), "First character");

    /* 4. Search last character */
    test_case(str, 'd', strlen(str), "Last character");

    /* 5. n smaller than location */
    test_case(str, 'o', 4, "Character outside n");

    /* 6. n = 0 */
    test_case(str, 'H', 0, "n = 0");

    /* 7. Empty string */
    test_case(empty, 'a', 1, "Empty string");

    /* 8. Searching for '\\0' */
    test_case(str, '\0', strlen(str) + 1, "Search null terminator");

    /* 9. Binary data */
    unsigned char data[] = {1, 2, 3, 4, 5};
    test_case(data, 3, 5, "Binary data");

    /* 10. Large n */
    test_case(str, 'W', 100, "Large n");

    return 0;
}

/*
| Case                  | Example              |
| --------------------- | -------------------- |
| Character exists      | `'o'`                |
| Character not present | `'z'`                |
| First byte            | `'H'`                |
| Last byte             | `'d'`                |
| `n` too small         | `'o', 4`             |
| `n = 0`               | should return `NULL` |
| Empty string          | `""`                 |
| Searching `'\0'`      | valid case           |
| Binary data           | `{1,2,3}`            |
| Large `n`             | bigger than string   |

gcc test_ft_memchr.c ../libft.a -I.. -o test_memchr

*/