#include <unistd.h>

int is_sep(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
	int len = 0;

	int i  = 0;
	int start;
	int end;
	int printed = 0;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	while (argv[1][len])
		len++;
	

	while (argv[1][i] && is_sep(argv[1][i]))
            i++;

    start = i;
	
	while (argv[1][i] && !is_sep(argv[1][i]))
		i++;
	end = i;
	
	while (argv[1][i] && is_sep(argv[1][i]))
        i++;
	
	while (argv[1][i])
    {
		while (argv[1][i] && is_sep(argv[1][i]))
			i++;
		int j = i;
		while(argv[1][j] && !is_sep(argv[1][j]))
			j++;
		if (i < j)
        {
            write(1, &argv[1][i], j - i);
            write(1, " ", 1);
            printed = 1;
        }
		i = j;
	}
	if(printed)
		write(1, " ", 1);
	
	write(1, &argv[1][start], end - start);
	 write(1, "\n", 1);
	
}