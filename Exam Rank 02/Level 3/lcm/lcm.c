

/*


unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	div;

	if (a == 0 || b == 0)
		return (0);
	div = 2;
	while (1)
	{
		if (a % div == 0 && b % div == 0)
			return (div);
		else if (div > a || div > b)
			return (1);
		div++;
	}
}



*/



unsigned int	gcd(unsigned int a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a * b) / gcd(a, b));
}


#include <stdio.h>

int main(void)
{
    printf("lcm(12,24) = %d\n", lcm(12,24));
}