#include <unistd.h>
int ft_space(char c)
{
    // if (c == 32 || (c>= 9 && c <= 13))
    //     return (1);
    // else
    //     return (0);

    //return ((c == 32 || (c>= 9 && c <= 13))? 1 : 0);

    return (c == 32 || (c>= 9 && c <= 13));// above are 2 options also to write
}

int main(int argc, char **argv)
{
    int i = 0;
    int found = 0;

    if (argc == 2)
    {
        while (argv[1][i])
        {

            while (ft_space(argv[1][i]) && argv[1][i])
                i++;
            if (found && argv[1][i])
                write(1, " ", 1);

            while (!ft_space(argv[1][i]) && argv[1][i])
            {
                found = 1;
                write (1, &argv[1][i], 1);
                i++;
            }
        }
    }
    write (1, "\n", 1);
}