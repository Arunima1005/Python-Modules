/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:42:34 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 18:50:10 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"

// #include "../ft_split.c"

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "arunima chowdhury welcome mam";
// 	char c = ' ';
// 	char **res;
// 	res = ft_split(s,c);
// 	int p = 0;
// 	while (p <ft_count_words(s, c) + 1)
// 	{
// 		printf("%s\n", res[p]);
// 		p++;
// 	}

// }


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	print_result(char **arr)
{
	int	i = 0;

	if (!arr)
	{
		printf("Result: NULL\n");
		return;
	}
	while (arr[i])
	{
		printf("[%d]: \"%s\"\n", i, arr[i]);
		i++;
	}
	printf("---- END ----\n");
}

void	free_result(char **arr)
{
	int	i = 0;

	if (!arr)
		return;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	run_test(const char *desc, char const *s, char c)
{
	char	**res;

	printf("Test: %s\n", desc);
	printf("Input: \"%s\"  Delim: '%c'\n", s ? s : "NULL", c);

	res = ft_split(s, c);
	print_result(res);
	free_result(res);

	printf("-------------------------\n");
}

int	main(void)
{
	/* 1. Normal case */
	run_test("Normal sentence", "Hello world split test", ' ');

	/* 2. Single word */
	run_test("Single word", "Hello", ' ');

	/* 3. Multiple delimiters */
	run_test("Multiple delimiters", "Hello,,,world,,test", ',');

	/* 4. Delimiter at beginning */
	run_test("Delimiter at start", ",Hello,world", ',');

	/* 5. Delimiter at end */
	run_test("Delimiter at end", "Hello,world,", ',');

	/* 6. Only delimiters */
	run_test("Only delimiters", ",,,,", ',');

	/* 7. Empty string */
	run_test("Empty string", "", ',');

	/* 8. No delimiter present */
	run_test("No delimiter", "abcdef", ',');

	/* 9. Space delimiter */
	run_test("Spaces", "   Hello   world   ", ' ');

	/* 10. NULL input (should return NULL safely) */
	run_test("NULL input", NULL, ',');

	return (0);
}

/*

| Case                | Example              | Why important             |
| ------------------- | -------------------- | ------------------------- |
| Normal sentence     | `"Hello world test"` | typical usage             |
| Single word         | `"Hello"`            | only one token            |
| Multiple delimiters | `"Hello,,,world"`    | skip repeated delimiters  |
| Delimiter at start  | `",Hello"`           | ignore empty tokens       |
| Delimiter at end    | `"Hello,"`           | avoid extra word          |
| Only delimiters     | `",,,,"`             | result should be empty    |
| Empty string        | `""`                 | must return empty array   |
| No delimiter        | `"abcdef"`           | full string returned      |
| Spaces              | `"   Hello   world"` | common real case          |
| NULL input          | `NULL`               | should return NULL safely |


gcc test_ft_split.c ../libft.a -I.. -o test_split

*/