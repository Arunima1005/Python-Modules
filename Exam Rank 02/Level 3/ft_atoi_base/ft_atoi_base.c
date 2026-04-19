
int ft_getvalue(char c)
{
    if (c >= '0' && c<= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c -'A' + 10;
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int i = 0;
    int sign = 1;
    int value = 0;

    if (str[i] == '-'){
        sign = -1;
        i++;
    }

    while (str[i])
    {
        value = ft_getvalue(str[i]);
        if (value < 0 || value >= str_base)
            break;
        result = result * str_base + value;
        i++;
    }
    return (sign * result);
}

#include <stdio.h>
int main(void)
{
int result = ft_atoi_base("1A3F",16);
        printf("%d\n", result);
}