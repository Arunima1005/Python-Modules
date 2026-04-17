

char    *ft_strrev(char *str)
{
    int i = 0;
    char s;
    int j =0;
     
    while (str[i])
        i++;
    i--;
    while (j < i)
    {
        s = str[j];
        str[j] = str[i];
        str[i] = s;
        j++;
        i--;
    }
    return (str);
}
#include <stdio.h>
int main(void)
{
    char str[]="abcdef";
    printf("%s", ft_strrev(str));
}