/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:50:37 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/17 17:18:59 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc, char **argv)
{
	int a;
	int b;

	if (argc == 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		
		if (argv[2][0] == '*')
			printf("%i\n", a * b);
		else if (argv[2][0] == '-')
			printf("%i\n", a - b);
		else if (argv[2][0] == '+')
			printf("%i\n",a + b);
		else if (argv[2][0] == '/')
			printf("%i\n", a / b);
		else if (argv[2][0] == '%')
			printf("%i\n", a % b);
	}
	else
		write (1, "\n", 1);
}


/*

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	do_op(int a, char op, int b)
{
	int	result;

	result = 0;
	if (op == '*')
		result = a * b;
	else if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '/')
		result = a / b;
	else if (op == '%')
		result = a % b;
	return (result);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if (argc == 4)
		printf("%i", do_op(a, argv[2][0], b));
	printf("\n");
	return (0);
}



*/