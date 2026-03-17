/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:11:40 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/13 17:11:41 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/* Example 1: convert to uppercase */
void to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

/* Example 2: add index to character */
void add_index(unsigned int i, char *c)
{
	*c = *c + i;
}

/* Example 3: replace characters with '*' */
void make_star(unsigned int i, char *c)
{
	(void)i;
	*c = '*';
}

void run_test(const char *desc, char *str, void (*f)(unsigned int, char *))
{
	printf("Test: %s\n", desc);

	if (!str)
	{
		printf("Input: NULL\n");
		ft_striteri(str, f);
		printf("Result: NULL\n");
	}
	else
	{
		printf("Before: \"%s\"\n", str);
		ft_striteri(str, f);
		printf("After : \"%s\"\n", str);
	}

	printf("-----------------------------\n");
}

int main(void)
{
	char s1[] = "hello world";
	char s2[] = "abcdef";
	char s3[] = "test";
	char s4[] = "";
	char *s5 = NULL;

	/* 1. Uppercase conversion */
	run_test("Uppercase conversion", s1, to_upper);

	/* 2. Add index to characters */
	run_test("Add index to characters", s2, add_index);

	/* 3. Replace characters */
	run_test("Replace with '*'", s3, make_star);

	/* 4. Empty string */
	run_test("Empty string", s4, to_upper);

	/* 5. NULL string (should not crash if handled) */
	run_test("NULL string", s5, to_upper);

	return 0;
}

/*
| Case               | Example    | Expected Behavior             |
| ------------------ | ---------- | ----------------------------- |
| Normal string      | `"hello"`  | characters modified           |
| Index usage        | `"abcdef"` | each char changed using index |
| Replace characters | `"test"`   | `"****"`                      |
| Empty string       | `""`       | remains empty                 |
| `NULL` input       | `NULL`     | should not crash              |



*/