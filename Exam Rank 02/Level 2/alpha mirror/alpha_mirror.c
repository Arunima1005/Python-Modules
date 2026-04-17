/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:38:34 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/17 15:56:35 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int main(int argc, char **argv)
{
	if (argc == 2)
	{	
		while (*argv[1])
		{
			if (*argv[1] >= 'a' && *argv[1] <= 'z')
				*argv[1] = 'z' - (*argv[1] - 'a');
			else if (*argv[1] >= 'A' && *argv[1] <= 'Z')
				*argv[1] = 'Z' - (*argv[1] - 'A');
			write(1,&*argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
}