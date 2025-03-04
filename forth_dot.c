#include <stdio.h>

int	main(void)
{
	int x[3], y[3];
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);

	int	xx, yy;
	for (int i = 0; i < 2; i++)
	{
		for (int j = i+1; j < 3; j++)
			if (x[i] == x[j])
			{
				x[i] = 0;
				x[j] = 0;
				break ;
			}
		if (!x[i])
			break ;
	}
	for (int i = 0; i < 3; i++)
	{
		if (x[i])
			xx = x[i];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = i+1; j < 3; j++)
			if (y[i] == y[j])
			{
				y[i] = 0;
				y[j] = 0;
				break ;
			}
		if (!y[i])
			break ;
	}
	for (int i = 0; i < 3; i++)
	{
		if (y[i])
			yy = y[i];
	}
	printf("%d %d", xx, yy);
	return (0);
}

int	main(void) //비트 연산 활용
{
	int	x[3], y[3];
	for (int i = 0; i < 3; i++)
		scanf("%d %d", x[i], x[j]);
	
	printf("%d %d", x[0]^x[1]^x[2], y[0]^y[1]^y[2]);
	return (0);
}
