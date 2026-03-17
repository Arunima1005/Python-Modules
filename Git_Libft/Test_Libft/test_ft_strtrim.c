/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:49 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 17:35:22 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"
// #include "../ft_strchr.c"
// #include "../ft_strlen.c"
// #include "../ft_substr.c"
// #include "../ft_strdup.c"
// #include "../ft_strtrim.c"
// #include "../ft_strlcpy.c"

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = " hello ";
// 	printf("%s\n",ft_strtrim(s," "));
// 	printf("%s\n",ft_strtrim("xxHello Worldxx", "x"));
// 	printf("%s\n",ft_strtrim("abcd", "x"));
// 	printf("%s\n",ft_strtrim("abcdef", "ab"));
// 	printf("%s\n",ft_strtrim("abcdef", "abf"));
// 	printf("%s\n",ft_strtrim("abcdef", "ab"));
// 	printf("%s\n",ft_strtrim("abcdef", "abd"));
// 	printf("%s\n",ft_strtrim("abcdefghijk", "e"));
// 	printf("%s\n",ft_strtrim("abcdefghijk", "ae"));
// }


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void run_test(const char *desc, const char *s1, const char *set)
{
	char *result;

	printf("Test: %s\n", desc);
	printf("Input: s1=\"%s\", set=\"%s\"\n",
		s1 ? s1 : "NULL",
		set ? set : "NULL");

	result = ft_strtrim(s1, set);

	if (!result)
		printf("Result: NULL\n");
	else
	{
		printf("Result: \"%s\"\n", result);
		free(result);
	}

	printf("------------------------------\n");
}

int main(void)
{
	/* 1. Normal trimming */
	run_test("Normal trim", "xxHello Worldxx", "x");

	/* 2. Trim spaces */
	run_test("Trim spaces", "   Hello World   ", " ");

	/* 3. Multiple trim characters */
	run_test("Multiple characters", "abcHelloabc", "abc");

	/* 4. Trim only beginning */
	run_test("Trim beginning only", "xxxHello", "x");

	/* 5. Trim only end */
	run_test("Trim end only", "Helloxxx", "x");

	/* 6. No characters to trim */
	run_test("No trim needed", "Hello", "xyz");

	/* 7. Entire string trimmed */
	run_test("All characters trimmed", "aaaaaa", "a");

	/* 8. Empty string */
	run_test("Empty string", "", "a");

	/* 9. Empty set */
	run_test("Empty set", "Hello", "");

	/* 10. Special characters */
	run_test("Special characters", "***Hello***", "*");

	/* 11. NULL s1 */
	run_test("NULL s1", NULL, "x");

	/* 12. NULL set */
	run_test("NULL set", "Hello", NULL);

	return 0;
}

/*

| Case                  | Example                 | Expected Result |
| --------------------- | ----------------------- | --------------- |
| Normal trimming       | `"xxHello Worldxx","x"` | `"Hello World"` |
| Trim spaces           | `"   Hello World   "`   | `"Hello World"` |
| Multiple characters   | `"abcHelloabc","abc"`   | `"Hello"`       |
| Trim only start       | `"xxxHello","x"`        | `"Hello"`       |
| Trim only end         | `"Helloxxx","x"`        | `"Hello"`       |
| No trimming needed    | `"Hello","xyz"`         | `"Hello"`       |
| Entire string removed | `"aaaaaa","a"`          | `""`            |
| Empty string          | `""`                    | `""`            |
| Empty set             | `"Hello",""`            | `"Hello"`       |
| Special characters    | `"***Hello***","*"`     | `"Hello"`       |
| `s1 = NULL`           | `NULL`                  | `NULL`          |
| `set = NULL`          | `NULL`                  | `NULL`          |

gcc test_ft_strtrim.c ../libft.a -I.. -o test_strtrim

*/