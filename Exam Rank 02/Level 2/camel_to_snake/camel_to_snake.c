/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:57:50 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/17 16:10:45 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	char c;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				write (1, &argv[1][i], 1);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				write (1, "_", 1);
				c = argv[1][i]+32;
				write (1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}