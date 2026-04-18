#include <unistd.h>

int main(int argc, char **argv)
{
    int len = 0;
    int i = 0;
    int j = 0;
    int found = 0;

    
    if (argc == 3)
    {
        while (argv[1][len])
        len++;

        while (argv[1][i])
        {
            found = 0;
            while (argv[2][j])
            {
                if (argv[2][j] == argv[1][i])
                {
                    found = 1;
                    j++;
                    break;
                }
                j++;
            }
            if (found == 1)
                i++;
            else
                break;
        }
        if (i == len)
            write(1, argv[1], len);
    }
    write (1,"\n", 1);
}

