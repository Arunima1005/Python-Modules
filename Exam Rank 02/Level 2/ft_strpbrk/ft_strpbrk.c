/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:56:34 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/17 17:56:58 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i =0;
    int j = 0;

    while (s1[i])
    {
        j=0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ((char *)&s1[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

#include <stdio.h>

//char	*ft_strpbrk(const char *s1, const char *s2);

int	main(void)
{
    char *s1 = "hello world";
    char *s2 = "od";

    char *result = ft_strpbrk(s1, s2);

    if (result)
        printf("Match found: %s\n", result);
    else
        printf("No match found\n");


    printf("Test 1: %s\n", ft_strpbrk("abcdef", "xdy")); // def
    printf("Test 2: %s\n", ft_strpbrk("12345", "9"));    // (null)
    printf("Test 3: %s\n", ft_strpbrk("", "abc"));       // (null)
    printf("Test 4: %s\n", ft_strpbrk("test", ""));      // (null)

    return 0;
}