#include <unistd.h>

int ft_atoi(char *str)
{
    int num = 0;
    int i = 0;

    while (str[i])
    {
        num =  (num * 10) + (str[i] - '0');
        i++;
    }
    return (num);
}

void ft_print_hex(int n)
{
    char *base = "0123456789abcdef";
    if(n >= 16)
        ft_print_hex(n/16);
    write(1, &base[n%16], 1);
}


int main(int argc, char **argv)
{
    if (argc == 2)
        ft_print_hex(ft_atoi(argv[1]));
    write (1, "\n", 1);
    
}

