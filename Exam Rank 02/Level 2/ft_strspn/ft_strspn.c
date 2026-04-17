#include <stddef.h>
size_t	ft_strspn(const char *s, const char *accept)
{
    int i = 0;
    int j = 0;
    int found;

    while (s[i])
    {
        j = 0;
        found = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
            {
               found = 1;
               break;
            }
            j++;
        }
        if(!found)
            return (i);
        i++;
    }
    return (i);
}

#include <stdio.h>

int main(void)
{
    printf("%zu\n", ft_strspn("abcdef1234", "abcd"));
    printf("%zu\n", ft_strspn("", "abc"));            // 0
printf("%zu\n", ft_strspn("abc", ""));            // 0
printf("%zu\n", ft_strspn("xyz", "abc"));         // 0
printf("%zu\n", ft_strspn("abc123", "abc"));      // 3
printf("%zu\n", ft_strspn("aaaaaa", "a"));        // 6
printf("%zu\n", ft_strspn("ABC", "abc"));         // 0
printf("%zu\n", ft_strspn("123-456", "0123456789")); // 3
}