/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:25:49 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/12 19:28:17 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include "../ft_itoa.c"
#include "../ft_strdup.c"
#include "../ft_strlen.c"
#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_itoa(-373737));
	printf("%s\n", ft_itoa(3737));
	printf("%s\n", ft_itoa(0));
}