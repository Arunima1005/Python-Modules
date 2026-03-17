/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:09:59 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 16:13:40 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"
// #include "../ft_strlcat.c"
// #include "../ft_strlen.c"
// #include "../ft_strlcpy.c"
// #include "../ft_strjoin.c"

// #include <stdio.h>

// int main(void)
// {
// 	char s1[] = "Hello";
// 	char s2[] = " World Arunima Welcome";

// 	printf("%s\n", ft_strjoin(s1,s2));
// }

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void run_test(const char *desc, const char *s1, const char *s2)
{
    char *result;

    printf("Test: %s\n", desc);
    printf("Input: s1=\"%s\", s2=\"%s\"\n",
           s1 ? s1 : "NULL",
           s2 ? s2 : "NULL");

    result = ft_strjoin(s1, s2);

    if (result == NULL)
        printf("Result: NULL\n");
    else
    {
        printf("Result: \"%s\"\n", result);
        free(result);
    }

    printf("-----------------------------\n");
}

int main(void)
{
    /* 1. Normal strings */
    run_test("Normal join", "Hello", "World");

    /* 2. Join with space */
    run_test("Join with space", "Hello ", "World");

    /* 3. Empty first string */
    run_test("Empty s1", "", "World");

    /* 4. Empty second string */
    run_test("Empty s2", "Hello", "");

    /* 5. Both empty */
    run_test("Both empty", "", "");

    /* 6. Long strings */
    run_test("Long strings", "This is a long string ", "that continues here");

    /* 7. Single characters */
    run_test("Single characters", "A", "B");

    /* 8. Numbers as string */
    run_test("Numeric strings", "123", "456");

    /* 9. Special characters */
    run_test("Special characters", "@#$", "%^&");

    /* 10. NULL first string */
    run_test("NULL s1", NULL, "World");

    /* 11. NULL second string */
    run_test("NULL s2", "Hello", NULL);

    /* 12. Both NULL */
    run_test("Both NULL", NULL, NULL);

    return 0;
}

/*
| Case               | Example            | Expected Result     |
| ------------------ | ------------------ | ------------------- |
| Normal join        | `"Hello","World"`  | `"HelloWorld"`      |
| With space         | `"Hello ","World"` | `"Hello World"`     |
| Empty `s1`         | `"" ,"World"`      | `"World"`           |
| Empty `s2`         | `"Hello",""`       | `"Hello"`           |
| Both empty         | `"",""`            | `""`                |
| Long strings       | long + long        | concatenated string |
| Single characters  | `"A","B"`          | `"AB"`              |
| Special characters | `"@#$","%^&"`      | `"@#$%^&"`          |
| `s1 = NULL`        | `NULL,"World"`     | `NULL`              |
| `s2 = NULL`        | `"Hello",NULL`     | `NULL`              |
| Both `NULL`        | `NULL,NULL`        | `NULL`              |

gcc test_ft_strjoin.c ../libft.a -I.. -o test_strjoin


*/