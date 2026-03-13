/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:28:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 16:54:01 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_strlcpy.c"
#include "../ft_strlen.c"
#include "../ft_substr.c"
#include "../ft_strdup.c"

#include <stdio.h>
int main(void)
{
	char s[] = "ABCDEFGHIJK";
	printf("%s\n",ft_substr(s,19,10));
}