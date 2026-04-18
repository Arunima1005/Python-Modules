
#include <unistd.h>

int ft_match(char c, char *str, int i)
{
    int j = 0;
    while (j<i)
    {
        if (c == str[j])
            return (0);
        j++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (ft_match(argv[1][i], argv[1], i))
                write(1, &argv[1][i], 1); 
            i++;
        }

        while (argv[2][j])
        {
            if (ft_match(argv[2][j], argv[1], i) && ft_match(argv[2][j], argv[2], j))
                 write(1, &argv[2][j], 1);
            j++;
        }
    }
    write (1, "\n", 1);
}