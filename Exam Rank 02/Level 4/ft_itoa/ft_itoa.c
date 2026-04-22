#include <stdlib.h>
int ft_len(long n)
{
  //  int sign = 1;
    int len = 0;
    
    if (n <= 0)
    {
        len ++;
       // n = -n;
    }
    while (n != 0){
        len++;
        n = n/10;
    }
    return (len);
}

char	*ft_itoa(int nbr)
{
    char *str;
    int len;
    int i = 0;
    long n = nbr;

        len = ft_len(n);
    str = malloc((len+1) * sizeof(char));
    if(!str)
        return (NULL);
    str[len --]='\0';
    if (n == 0)
        str[0] = '0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    while(n > 0)
    {
        str[len--] = n%10 + '0';
        n = n/10;
    }
    return (str);
}

#include <stdio.h>

int main (void)
{
   // printf("%d", ft_len(-123456));
   printf("%s", ft_itoa(-123456));
}