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

#include "../libft.h"
#include "../ft_strchr.c"
#include "../ft_strlen.c"
#include "../ft_substr.c"
#include "../ft_strdup.c"
#include "../ft_strtrim.c"
#include "../ft_strlcpy.c"

#include <stdio.h>
int main(void)
{
	char s[] = " hello ";
	printf("%s\n",ft_strtrim(s," "));
	printf("%s\n",ft_strtrim("xxHello Worldxx", "x"));
	printf("%s\n",ft_strtrim("abcd", "x"));
	printf("%s\n",ft_strtrim("abcdef", "ab"));
	printf("%s\n",ft_strtrim("abcdef", "abf"));
	printf("%s\n",ft_strtrim("abcdef", "ab"));
	printf("%s\n",ft_strtrim("abcdef", "abd"));
	printf("%s\n",ft_strtrim("abcdefghijk", "e"));
	printf("%s\n",ft_strtrim("abcdefghijk", "ae"));
}