unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char result = 0;

    int i = 8;

    while((i--) > 0)
    {
        result = (result * 2) + (octet % 2);
        octet = octet / 2;
    }
    return (result);
}




/*

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result |= ((octet >> i) & 1) << (7 - i);
		i++;
	}
	return (result);
}

*/

/*
#include<unistd.h>
void	print_bits(unsigned char octet)
{
	int i = 8;

	while (i--)
	{
		if ((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

int main(void)
{
	unsigned char x = 38; // 00100110
	unsigned char y;

	print_bits(x);
	write(1, "\n", 1);

	y = reverse_bits(x);

	print_bits(y);
	write(1, "\n", 1);

	return (0);
}
*/
/*
output
00100110
01100100

*/
