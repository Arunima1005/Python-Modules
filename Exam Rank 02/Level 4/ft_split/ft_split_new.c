#include <stdlib.h>

int is_sep(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {
        while (str[i] && is_sep(str[i]))
            i++;
        if (str[i])
            count++;
        while (str[i] && !is_sep(str[i]))
            i++;
    }
    return count;
}

char *word_dup(char *str, int start, int end)
{
    char *word;
    int i = 0;

    word = malloc(sizeof(char) * (end - start + 1));
    if (!word)
        return NULL;

    while (start < end)
        word[i++] = str[start++];
    word[i] = '\0';
    return word;
}

char **ft_split(char *str)
{
    char **res;
    int i = 0, j = 0, start;

    res = malloc(sizeof(char *) * (count_words(str) + 1));
    if (!res)
        return NULL;

    while (str[i])
    {
        while (str[i] && is_sep(str[i]))
            i++;
        start = i;
        while (str[i] && !is_sep(str[i]))
            i++;
        if (i > start)
            res[j++] = word_dup(str, start, i);
    }
    res[j] = NULL;
    return res;
}


#include <stdio.h>
int main(void)
{
    char **arr;
    int i = 0;

    char *phrase = "   Hello,   Flavio\t Wuensche!  ";
    arr = ft_split(phrase);

    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
	printf("%s\n", arr[i]);
}