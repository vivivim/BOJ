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

	int	dp[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dp[i][j] = 0;
	}
	dp[0][0] = tri[0][0];
	dp[1][0] = dp[0][0] + tri[1][0];
	dp[1][1] = dp[0][0] + tri[1][1];

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i-1][j] + tri[i][j];
			else if (j == i)
				dp[i][j] = dp[i-1][j-1] + tri[i][j];
			else
				dp[i][j] = max(dp[i-1][j-1] + tri[i][j], dp[i-1][j] + tri[i][j]);
		}
	}

	int	dst = dp[n-1][0];

	for (int i = 1; i < n; i++)
	{
		if (dst < dp[n-1][i])
			dst = dp[n-1][i];
	}
	printf("%d", dst);
	return (0);
}
