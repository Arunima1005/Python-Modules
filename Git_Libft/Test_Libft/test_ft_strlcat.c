/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:14:35 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 13:16:31 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_strlcat.c"
#include "../ft_strlen.c"

#include <stdio.h>
int main(void)
{
	char dst[10] = "hello";
	printf("%zu\n",ft_strlcat(dst, "world", sizeof(dst)));
	printf("%s\n", dst);
	char dst1[18] = "hello";
	printf("%zu\n",ft_strlcat(dst1, "world", sizeof(dst1)));
	printf("%s\n", dst1);
}