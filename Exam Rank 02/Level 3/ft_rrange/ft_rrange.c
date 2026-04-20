#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int *arr;
    int len = (start < end) ? end - start + 1 : start - end + 1;
    arr = malloc(sizeof(int) *  len);
    if(!arr)
        return (NULL);
    int i = 0;
    while (i < len)
    {
        arr[i] = end;
        if (start < end)
            end--;
        else
            end++;
        i++;
    }
    return (arr);
}


#include <stdio.h>

int main(void)
{
    int *arr;
    int start = 0;
    int end = -3;

    int i = 0;
    int len = (start < end) ? end - start + 1 : start - end + 1;
    arr = ft_rrange(start,end);
    while (i < len)
    {
        printf("%d ", arr[i]);
        i++;
    }
}