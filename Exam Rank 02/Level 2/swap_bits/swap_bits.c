unsigned char	swap_bits(unsigned char octet)
{
    return (octet << 4 | octet >> 4);
}


// #include <unistd.h>
// void	print_bits(unsigned char octet)
// {
// 	int	i;

// 	i = 8;
// 	while (i--)
// 	{
// 		if ((octet >> i) & 1)
// 			write(1, "1", 1);
// 		else
// 			write(1, "0", 1);
// 	}
// }

// int	main(void)
// {
// 	unsigned char x = 65; // 01000001
// 	unsigned char y;

// 	print_bits(x);
// 	write(1, "\n", 1);

// 	y = swap_bits(x);

// 	print_bits(y);
// 	write(1, "\n", 1);

// 	return (0);
// }