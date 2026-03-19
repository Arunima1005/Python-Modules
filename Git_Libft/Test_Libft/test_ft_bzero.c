/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:42:10 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/10 18:33:37 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"
#include "../ft_bzero.c"

#include <stdio.h>

int main(void)
{
	char s[20] = "abcdxsdf cddd";
	printf("Before = %s\n", s);
	ft_bzero(s,3);
	printf("After = %s", s);
}

