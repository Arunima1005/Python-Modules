

int		max(int* tab, unsigned int len)
{
    unsigned int i = 1;
    int max;

    if (len == 0)
        return (0);
    max = tab[0];

    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];

        i++;
    }
    return (max);
}


#include <stdio.h>

int main(void)
{
    int arr[] = {12, 13, 54, 4, 60, 24, 90};
    printf("%d\n", max(arr, 7));
}