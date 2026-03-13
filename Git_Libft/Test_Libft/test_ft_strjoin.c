/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:09:59 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 16:13:40 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_strlcat.c"
#include "../ft_strlen.c"
#include "../ft_strlcpy.c"
#include "../ft_strjoin.c"

#include <stdio.h>

int main(void)
{
	char s1[] = "Hello";
	char s2[] = " World Arunima Welcome";

	printf("%s\n", ft_strjoin(s1,s2));
}