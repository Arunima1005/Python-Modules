/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:25:49 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 19:28:17 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"

// #include "../ft_itoa.c"
// #include "../ft_strdup.c"
// #include "../ft_strlen.c"
// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_itoa(-373737));
// 	printf("%s\n", ft_itoa(3737));
// 	printf("%s\n", ft_itoa(0));
// }

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void run_test(const char *desc, int n)
{
	char *result;

	printf("Test: %s\n", desc);
	printf("Input: %d\n", n);

	result = ft_itoa(n);

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
	/* 1. Zero */
	run_test("Zero", 0);

	/* 2. Positive number */
	run_test("Positive number", 12345);

	/* 3. Negative number */
	run_test("Negative number", -12345);

	/* 4. Single digit */
	run_test("Single digit", 7);

	/* 5. Negative single digit */
	run_test("Negative single digit", -7);

	/* 6. Large positive number */
	run_test("Large positive", 2147483647);

	/* 7. INT_MIN */
	run_test("INT_MIN", INT_MIN);

	/* 8. INT_MAX */
	run_test("INT_MAX", INT_MAX);

	/* 9. Number ending in zero */
	run_test("Ends with zero", 12000);

	/* 10. Negative number ending in zero */
	run_test("Negative ending in zero", -12000);

	return 0;
}

/*

| Case                    | Example       | Expected Result |
| ----------------------- | ------------- | --------------- |
| Zero                    | `0`           | `"0"`           |
| Positive number         | `12345`       | `"12345"`       |
| Negative number         | `-12345`      | `"-12345"`      |
| Single digit            | `7`           | `"7"`           |
| Negative single digit   | `-7`          | `"-7"`          |
| Large positive          | `2147483647`  | `"2147483647"`  |
| `INT_MIN`               | `-2147483648` | `"-2147483648"` |
| `INT_MAX`               | `2147483647`  | `"2147483647"`  |
| Trailing zeros          | `12000`       | `"12000"`       |
| Negative trailing zeros | `-12000`      | `"-12000"`      |

gcc test_ft_itoa.c ../libft.a -I.. -o test_itoa

*/