
#include <unistd.h>

int ft_prime(int num)
{
    int n = 2;
    if (num < 2)
        return (0);
    while (n < num)
    {
        if (num%n == 0)
            return (0);
        n++;
    }
    return (1);
}

int ft_atoi(char *s)
{
    int num = 0;
    int i = 0;

     if (!s[0])
        return (0);

    while(s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (0);
        num = (num * 10) + s[i] - '0';
        i++;
    }
    return (num); 
}
void ft_putnbr(int num)
{
    char c;

    if (num > 9)
        ft_putnbr(num/10);
    c = (num%10) + '0';
    write (1, &c, 1);
}

int main(int argc, char **argv)
{
    int result = 0;
    int i = 2;
    int num;
  
    if (argc == 2)
    {
        num =   ft_atoi(argv[1]);

        while (i <= num)
        {
            if (ft_prime(i))
                result = result + i;
            i++;
        }
        ft_putnbr(result);
    }
    else 
        write (1, "0", 1);
    write (1,"\n", 1);
}