

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    char c;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == '_' && argv[1][i + 1])
            {
                c = argv[1][i + 1];
                if (c >= 'a' && c <= 'z')
                    c -= 32;
                write(1, &c, 1);
                i++;
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}