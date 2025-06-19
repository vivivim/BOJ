#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	dp[n][10];

	dp[0][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i-1][1];
			else if (j == 9)
				dp[i][j] = dp[i-1][8];
			else
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
		}
	}

	int	dst = 0;
	for (int i = 0; i < 10; i++)
	{
		dst += dp[n-1][i];
		dst = dst%1000000000;
	}
	printf("%d", dst);
}
