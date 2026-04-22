#include <unistd.h>
#include <stdlib.h>

void ft_print_word(char *str)
{
	int i = 0;

	while (str[i] && str[i] != 32)
	{
		write(1, &str[i],1 );
		i++;
	}
}


int main (int argc, char **argv)
{
	int len = 0;
	int i;
// int first = 1;

	if(argc == 2)
	{
		while(argv[1][len])
			len++;
		i = len - 1;
		while(i >=0 )
		{
			if(argv[1][i] == 32 || i == 0)
			{
				if(i == 0)
				// if (!first)
                //     write(1, " ", 1);
					ft_print_word(&argv[1][i]);
				else
				{
					// if (!first)
                    //     write(1, " ", 1);
					ft_print_word(&argv[1][i+1]);
					write(1, " ",1 );
				}
				//first = 0;
				i--;
			}
			else
				i--;
		}
		
	}
	write(1, "\n", 1);

}


/*


#include <unistd.h>

int main(int argc, char **argv)
{
    int i, end;

    if (argc == 2)
    {
        i = 0;
        while (argv[1][i])
            i++;

        while (i >= 0)
        {
            while (i >= 0 && argv[1][i] == ' ')
                i--;

            end = i;

            while (i >= 0 && argv[1][i] != ' ')
                i--;

            if (end >= 0)
            {
                write(1, &argv[1][i + 1], end - i);
                if (i > 0)
                    write(1, " ", 1);
            }
        }
    }
    write(1, "\n", 1);
}


*/