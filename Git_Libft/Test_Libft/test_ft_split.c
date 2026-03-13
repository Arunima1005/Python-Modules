/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:42:34 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 18:50:10 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include "../ft_split.c"

#include <stdio.h>
int main(void)
{
	char s[] = "arunima chowdhury welcome mam";
	char c = ' ';
	char **res;
	res = ft_split(s,c);
	int p = 0;
	while (p <ft_count_words(s, c) + 1)
	{
		printf("%s\n", res[p]);
		p++;
	}

}