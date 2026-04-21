#include <unistd.h>

void ft_lowercase(char *str)
{
	int i = 0;
	 
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;

		i++;
	}
}

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	if(argc == 1)
		write (1, "\n", 1);

	while (i < argc)
	{
		ft_lowercase(argv[i]);
		j = 0;
		while(argv[i][j])
		{
			if ((j == 0 || argv[i][j-1] == ' ' || argv[i][j-1] == '\t')
			&& (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
				argv[i][j] -= 32;
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}