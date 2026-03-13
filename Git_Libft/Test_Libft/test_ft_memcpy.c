/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:30:03 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/11 15:02:38 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_memcpy.c"

int main(void)
{
	char src[] =  "hello world";
	char dest[20];
	char dest1[20];

	ft_memcpy(dest,src,strlen(src));
	memcpy(dest1,src,strlen(src));

	printf("source = %s\n", src);
	printf("own function = %s\n", dest);
	printf("original one = %s\n", dest1);
}