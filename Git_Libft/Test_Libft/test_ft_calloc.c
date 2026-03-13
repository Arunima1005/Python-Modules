/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:25:15 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/13 12:42:42 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_calloc.c"
#include "../ft_bzero.c"
#include "../ft_memset.c"
#include <stdio.h>

int main(void)
{
	void *ptr;
    int *arr;
    size_t i;

    printf("---- Normal allocation ----\n");
    arr = ft_calloc(5, sizeof(int));
    if (!arr)
        printf("Allocation failed\n");
    else
    {
        for (i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }

    printf("\n---- nmemb = 0 ----\n");
    ptr = ft_calloc(0, 10);
    if (ptr)
    {
        printf("Pointer returned: %p\n", ptr);
        free(ptr);
    }
    else
        printf("Returned NULL\n");

    printf("\n---- size = 0 ----\n");
    ptr = ft_calloc(10, 0);
    if (ptr)
    {
        printf("Pointer returned: %p\n", ptr);
        free(ptr);
    }
    else
        printf("Returned NULL\n");

    printf("\n---- nmemb = 0 AND size = 0 ----\n");
    ptr = ft_calloc(0, 0);
    if (ptr)
    {
        printf("Pointer returned: %p\n", ptr);
        free(ptr);
    }
    else
        printf("Returned NULL\n");

    printf("\n---- Overflow test ----\n");
    ptr = ft_calloc((size_t)-1, 2);
    if (!ptr)
        printf("Overflow correctly detected (NULL returned)\n");
    else
    {
        printf("Overflow NOT detected\n");
        free(ptr);
    }

    printf("\n---- Large allocation test ----\n");
    ptr = ft_calloc(1000000000, 1000000000);
    if (!ptr)
        printf("Large allocation failed (expected)\n");
    else
    {
        printf("Large allocation succeeded\n");
        free(ptr);
    }
	/*

	We convert -1 into an unsigned type.

	In unsigned integers, negative numbers wrap to the maximum value.
	
	*/
	printf("\n (size_t)-1 = %zu", (size_t)-1);

    return 0;
}
