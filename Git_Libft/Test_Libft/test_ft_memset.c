/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:44:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/11 13:54:02 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft.h"
// #include "../ft_memset.c"

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char b[20] = "abcd fffff abcd";
// 	ft_memset(b + 2,'*',5);
// 	printf("%s", b);
// 	printf("\n ----------------------- \n");
// 	char a[20] = "abcd fffff abcd";
// 	memset(a + 2,'*',5);
// 	printf("%s", a);
// }
#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_buffer(unsigned char *buf, size_t size)
{
    size_t i = 0;

    while (i < size)
    {
        printf("%02X ", buf[i]);
        i++;
    }
    printf("\n");
}

void run_test(const char *name, unsigned char *b1, unsigned char *b2, int c, size_t n)
{
    printf("Test: %s\n", name);

    memset(b1, c, n);
    ft_memset(b2, c, n);

    printf("memset:    ");
    print_buffer(b1, 20);

    printf("ft_memset: ");
    print_buffer(b2, 20);

    if (memcmp(b1, b2, 20) == 0)
        printf("Result: OK\n");
    else
        printf("Result: FAIL\n");

    printf("------------------------------\n");
}

int main(void)
{
    unsigned char buf1[20];
    unsigned char buf2[20];

    /* Initialize buffers */
    memset(buf1, 'A', 20);
    memset(buf2, 'A', 20);

    /* 1. Normal use */
    run_test("Fill first 10 bytes", buf1, buf2, 'B', 10);

    memset(buf1, 'A', 20);
    memset(buf2, 'A', 20);

    /* 2. Fill whole buffer */
    run_test("Fill full buffer", buf1, buf2, 'C', 20);

    memset(buf1, 'A', 20);
    memset(buf2, 'A', 20);

    /* 3. n = 0 */
    run_test("n = 0", buf1, buf2, 'D', 0);

    memset(buf1, 'A', 20);
    memset(buf2, 'A', 20);

    /* 4. Fill with zero */
    run_test("Fill with 0", buf1, buf2, 0, 15);

    memset(buf1, 'A', 20);
    memset(buf2, 'A', 20);

    /* 5. Value > 127 */
    run_test("Value > 127", buf1, buf2, 200, 8);

    memset(buf1, 'A', 20);
    memset(buf2, 'A', 20);

    /* 6. Offset pointer */
    printf("Test: Offset pointer\n");

    memset(buf1 + 5, 'E', 5);
    ft_memset(buf2 + 5, 'E', 5);

    printf("memset:    ");
    print_buffer(buf1, 20);

    printf("ft_memset: ");
    print_buffer(buf2, 20);

    if (memcmp(buf1, buf2, 20) == 0)
        printf("Result: OK\n");
    else
        printf("Result: FAIL\n");

    printf("------------------------------\n");

    /* 7. Large n smaller than buffer */
    memset(buf1, 'A', 20);
    memset(buf2, 'A', 20);

    run_test("Large n inside buffer", buf1, buf2, 'Z', 18);

    return 0;
}

//gcc test_ft_memset.c ../libft.a -I..



/*

| Case           | Why it's important             |
| -------------- | ------------------------------ |
| Normal use     | standard behavior              |
| Full buffer    | boundary case                  |
| `n = 0`        | function should do nothing     |
| Fill with `0`  | common use to clear memory     |
| `c > 127`      | verifies unsigned char casting |
| Offset pointer | pointer arithmetic             |
| Large `n`      | near boundary                  |


*/