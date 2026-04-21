#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{

	if (argc == 2)
	{
		int num = atoi(argv[1]);

		if (num == 1)
			printf("1");

		else
		{
			int i = 2;
			while (i <= num)
			{
				if(num % i == 0)
				{
					if (num/i != 1)
						printf("%d*", i);
					else
						printf("%d", i);
					num = num/i;
				}
				else 
					i++;
			}
		}
	}
	printf("\n");
}