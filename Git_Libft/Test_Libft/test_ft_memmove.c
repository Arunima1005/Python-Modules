/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:06:14 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/11 17:55:31 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_memmove.c"

int main(void)
{
	char src[] =  "ABCDEF";
	char src1[] =  "ABCDEFGHIJ";
	char dest[20];
	char dest1[20];

	ft_memmove(src+3,src,strlen(src));
	memmove(src+3,src,strlen(src));

	printf("source = %s\n", src);

	ft_memmove(dest,src1,8);
	memmove(dest1,src1,8);
	printf("own function = %s\n", dest);
	printf("original one = %s\n", dest1);
}
