#include <stdlib.h>

int is_sep(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
int ft_count_word(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		// if(!is_sep(str[i]))
		// {
		// 	count++;
		// 	while(str[i] && !is_sep(str[i]))
		// 		i++;
		// }
		// else
		// 	i++;

		
		while (str[i] && is_sep(str[i]))
            i++;
        if (str[i])
            count++;
        while (str[i] && !is_sep(str[i]))
            i++;
		
	}
	return (count);
}

char *ft_word(char *str)
{
	char *word;
	int i = 0;

	while (str[i] && !is_sep(str[i]))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
    return (NULL);
	i = 0;
	while(str[i]&& !is_sep(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);

}

char    **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	char **word = malloc(sizeof(char *) * (ft_count_word(str)+1));
	if(!word)
		return (NULL);
	while(str[i])
	{
		if(!is_sep(str[i]))
		{
			word[j] = ft_word(&str[i]);
			while(str[i] && !is_sep(str[i]))
				i++;
			j++;
		}
		else
			i++;
	}
	word[j] = NULL;
	return(word);
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