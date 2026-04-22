

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    unsigned int j;
    int swapped;
    int tmp;

    while (i < size - 1)
    {
        swapped = 0;
        j = 0;

        while (j < size - i - 1)
        {
            if (tab[j] > tab[j + 1]) 
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
                swapped = 1;
            }
            j++;
        }

        if (swapped == 0)
            break;

        i++;
    }
}

#include<stdio.h>
int main(void)
{
	//int arr[6] = {12, 14, -67, 13 ,19, 100};
	int arr[] = {5, 1, 4, 2, 3};
	sort_int_tab(arr,6);
	for (int i = 0;i<6;i++)
		printf("%d ", arr[i]);
}