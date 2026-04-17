/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:45:02 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/17 17:55:21 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int len = ft_strlen(src);
	int i = 0;

	char *str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);

	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strdup(argv[1]));
	return (0);
} 