#include <stdio.h>

int	main(void)
{
	int	n, j, ct = 0;
	scanf("%d", &n);
	while (n)
	{
		for (int i = n+1; i <= 2*n; i++)
		{
			j = 2;
			while (j * j <= i)
			{
				if (i % j == 0)
					break ;
				j++;
			}
			if (i == 1)
				;
			else if (j * j > i)
				ct++;
		}
		printf("%d\n", ct);
		ct = 0;
		scanf("%d", &n);
	}
	return (0);
}
