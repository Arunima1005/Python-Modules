/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:12:32 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/13 17:12:33 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/* Example function 1: convert to uppercase */
char to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* Example function 2: add index value to character */
char add_index(unsigned int i, char c)
{
	return (c + i);
}

/* Example function 3: replace characters with '*' */
char star(unsigned int i, char c)
{
	(void)i;
	(void)c;
	return ('*');
}

void run_test(const char *desc, const char *s, char (*f)(unsigned int, char))
{
	char *result;

	printf("Test: %s\n", desc);
	printf("Input: \"%s\"\n", s ? s : "NULL");

	result = ft_strmapi(s, f);

	if (!result)
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
	/* 1. Normal string with uppercase conversion */
	run_test("Uppercase conversion", "hello world", to_upper);

	/* 2. Add index to characters */
	run_test("Add index to characters", "abcdef", add_index);

	/* 3. Replace all characters */
	run_test("Replace with '*'", "hello", star);

	/* 4. Empty string */
	run_test("Empty string", "", to_upper);

	/* 5. Single character */
	run_test("Single character", "A", add_index);

	/* 6. Special characters */
	run_test("Special characters", "@#$%^", to_upper);

	/* 7. Numbers in string */
	run_test("Numbers in string", "12345", add_index);

	/* 8. NULL string input */
	run_test("NULL string", NULL, to_upper);

	return 0;
}

/*
| Case               | Example         | Expected Behavior             |
| ------------------ | --------------- | ----------------------------- |
| Normal string      | `"hello world"` | characters modified by `f`    |
| Index usage        | `"abcdef"`      | each char changed using index |
| Replace characters | `"hello"`       | `"*****"`                     |
| Empty string       | `""`            | returns empty string          |
| Single character   | `"A"`           | function applied once         |
| Special characters | `"@#$%^"`       | still processed               |
| Numbers in string  | `"12345"`       | still processed               |
| `s = NULL`         | `NULL`          | returns `NULL`                |

gcc test_ft_strmapi.c ../libft.a -I.. -o test_strmapi

*/