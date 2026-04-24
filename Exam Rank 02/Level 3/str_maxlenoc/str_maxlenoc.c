#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int match(char *str, char *sub, int len)
{
	int i, j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < len && str[i + j] && str[i + j] == sub[j])
			j++;
		if (j == len)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i, len, k;
	int best_len = 0;
	int best_start = 0;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return 0;
	}

	char *s = argv[1];
	int s_len = ft_strlen(s);

	i = 0;
	while (i < s_len)
	{
		len = s_len - i; // start with longest possible

		while (len > 0)
		{
			int valid = 1;
			k = 2;

			while (k < argc)
			{
				if (!match(argv[k], &s[i], len))
				{
					valid = 0;
					break;
				}
				k++;
			}

			if (valid)
			{
				if (len > best_len)
				{
					best_len = len;
					best_start = i;
				}
				break; // IMPORTANT: stop shrinking at this i
			}
			len--;
		}
		i++;
	}

	if (best_len > 0)
		write(1, &s[best_start], best_len);

	write(1, "\n", 1);
	return 0;
}