#include <unistd.h>

int main(int argc, char **argv)
{
    int len = 0;
    int end;

    if (argc == 2)
    {
        while (argv[1][len])
            len++;
        len --;
        while (len>=0 && (argv[1][len] == 32 || 
            (argv[1][len] >= 9 && argv[1][len] <= 13)))
            len --;
        
        end = len;
            
        // find start of last word
        while (argv[1][len] != 32 && len > 0)
            len --;

          len ++; //move to the 1st letter

        while (len <= end)
        {
            write (1, &argv[1][len], 1);
            len ++;
        }
    }
    write (1, "\n", 1);
}