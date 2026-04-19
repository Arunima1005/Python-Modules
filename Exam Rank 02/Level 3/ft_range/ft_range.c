#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = 0;

    if (start <= end)
        len = end - start + 1;
    else
        len = start - end + 1;
    int *arr = malloc(sizeof (int) * len);
    if(!arr)
        return (NULL);
    
    i = 0;
    while (i < len)
    {
       arr[i] = start;
        if (start < end)
            start++;
        else
            start--;
        i++;
    }  
    return (arr);
}
int main(void)
{
    int start = -1;
    int end = 2;
    int len = (start <= end) ? (end - start + 1) : (start - end + 1);

     int *arr = ft_range(start, end);
    if (!arr)
        return 1;

    int i = 0;
    while (i < 5)
    {
        printf("%d\n", arr[i]);
        i++;
    }
}