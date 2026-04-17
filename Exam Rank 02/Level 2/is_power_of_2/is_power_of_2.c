
int	    is_power_of_2(unsigned int n)
{
    unsigned int s = 1;

    while (s <= n)
    {        
        if (s == n)
            return (1);
        s = s * 2;
    }
    return (0);
}






#include <stdio.h>
int main (void)
{
    printf("%d\n", is_power_of_2(23));
    printf("%d\n", is_power_of_2(16));

}