/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:54:57 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/13 14:56:18 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include "../ft_putstr_fd.c"
#include "../ft_putnbr_fd.c"
#include "../ft_putchar_fd.c"
#include "../ft_strlen.c"

#include <limits.h>
#include <fcntl.h>
int main(void)
{
	int	fd;

	/* writing to a file */
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putstr_fd("File Test: ", fd);
		ft_putnbr_fd(987654321, fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("Test 1: Zero -> ", fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd("Test 2: Positive -> ", fd);
	ft_putnbr_fd(12345, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd("Test 3: Negative -> ", fd);
	ft_putnbr_fd(-12345, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd("Test 4: Single digit -> ", fd);
	ft_putnbr_fd(7, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd("Test 5: Negative single digit -> ", fd);
	ft_putnbr_fd(-7, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd("Test 6: INT_MAX -> ", fd);
	ft_putnbr_fd(INT_MAX, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd("Test 7: INT_MIN -> ", fd);
	ft_putnbr_fd(INT_MIN, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd("Test 8: Write to stderr -> ", fd);
	ft_putnbr_fd(42, fd);
	ft_putchar_fd('\n', fd);

		close(fd);
	}

	return (0);
}