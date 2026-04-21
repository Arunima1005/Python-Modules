#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return(num);
}

void ft_putnbr(int num)
{
	char c;
	if (num > 9)
		ft_putnbr(num/10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i = 1;
	int num;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(i * num);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}