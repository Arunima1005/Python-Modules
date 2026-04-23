#include <unistd.h>
#include <stdio.h>

int is_alph(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

int main(int argc, char **argv)
{
    int seen[26] = {0};
    int count[26] = {0};
    int first = 1;
    if (argc != 2)
	{
		write(1, "\n", 1);
          return (0);
	}
  

    int i = 0;
    while (argv[1][i])
    {
        if(is_alph(argv[1][i]))
        {
            count[to_lower(argv[1][i]) - 'a']++;
            seen[to_lower(argv[1][i]) - 'a'] = 1;
        }
        i++;
    }
    i = 0;
    while (argv[1][i])
    {
        if(is_alph(argv[1][i]) && seen[to_lower(argv[1][i]) - 'a'])
        {
            if(!first)
                printf(", ");
           printf("%d%c", count[to_lower(argv[1][i]) - 'a'], to_lower(argv[1][i]));
            seen[to_lower(argv[1][i]) - 'a'] = 0;
            first = 0;
        }
        i++;
    }
    printf("\n");
}