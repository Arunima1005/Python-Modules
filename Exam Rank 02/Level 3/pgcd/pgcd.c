#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int result = 0;
    int div = 1;
    if (argc == 3)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        while (div <= a && div <= b)
        {
            if (a%div == 0 && b%div == 0)
                result = div;
            div++;
        }
        printf("%d", result);
    }
    printf("\n");

}

/*

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int a;
	int b;
	int temp;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);

		while (b != 0)
		{
			temp = b;
			b = a % b;
			a = temp;
		}
		printf("%d", a);
	}
	printf("\n");
	return (0);
}


*/