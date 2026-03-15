/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:46:19 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 14:18:57 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "../ft_atoi.c"
// #include "../ft_isdigit.c"
 #include "../libft.h"

// int main(void)
// {
// 	printf("%d\n", ft_atoi("1234"));
// 	printf("%d\n", atoi("1234"));
// 	printf("%d\n", ft_atoi("-1234"));
// 	printf("%d\n", atoi("-1234"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", atoi("-214748348"));

// }

int main(void)
{
	char *tests[] = {
		"42",
		"-42",
		"+42",
		"0",
		"000123",
		"   123",
		"\t\n\v\f\r 456",
		"   -789",
		"   +789",
		"123abc",
		"abc123",
		"--123",
		"++123",
		"+-123",
		"-+123",
		"",
		"    ",
		"2147483647",
		"-2147483648",
		"00123abc456",
		NULL
	};

	int i = 0;

	while (tests[i])
	{
		printf("Input: \"%s\"\n", tests[i]);
		printf("ft_atoi: %d\n", ft_atoi(tests[i]));
		printf("atoi   : %d\n", atoi(tests[i]));
		printf("-------------------------\n");
		i++;
	}

	return 0;
}