#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		t;
	long	n, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%ld", &n);
		for (long i = n; i <= 4000000007; i++)
		{
			j = 2;
			while (j*j <= i)
			{
				if (i % j == 0)
					break;
				j++;
			}
			if (i == 1 || !i)
				;
			else if (j * j > i)
			{
				printf("%ld\n", i);
				break ;
			}
		}
	}
	return (0);
}
