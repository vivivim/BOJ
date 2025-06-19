#include <stdio.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	tri[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			scanf("%d", &tri[i][j]);
	}

	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			tri[i-1][j] += max(tri[i][j], tri[i][j+1]);
	}
	printf("%d", tri[0][0]);
	return (0);
}
