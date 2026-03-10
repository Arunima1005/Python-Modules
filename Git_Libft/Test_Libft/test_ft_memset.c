/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:44:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/10 17:28:45 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_memset.c"

#include <stdio.h>
int main(void)
{
	char b[20] = "abcd fffff abcd";
	ft_memset(b + 2,'*',5);
	printf("%s", b);
}