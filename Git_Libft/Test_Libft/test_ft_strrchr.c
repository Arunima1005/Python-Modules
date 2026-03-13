/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:52:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 16:59:20 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include "../ft_strlen.c"

#include "../ft_strrchr.c"

#include <stdio.h>
int main(void)
{
	char s[] = "ABCDEFGHIJK";
	printf("%s\n",ft_strrchr(s,'F'));
}