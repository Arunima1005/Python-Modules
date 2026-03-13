/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:44:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/11 13:54:02 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_memset.c"

#include <stdio.h>
#include <string.h>
int main(void)
{
	char b[20] = "abcd fffff abcd";
	ft_memset(b + 2,'*',5);
	printf("%s", b);
	printf("\n ----------------------- \n");
	char a[20] = "abcd fffff abcd";
	memset(a + 2,'*',5);
	printf("%s", a);
}
