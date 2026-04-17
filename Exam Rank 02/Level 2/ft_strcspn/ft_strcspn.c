/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:29:51 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/17 17:42:51 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
#include <stdio.h>
int main( void)
{
	printf("%lu\n" , ft_strcspn("hello", "l"));
	printf("%lu\n" , ft_strcspn("abcde", "xyz"));
	printf("%lu\n" , ft_strcspn("42network", "0"));

}

