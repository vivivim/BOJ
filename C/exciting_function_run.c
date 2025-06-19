#include <stdio.h>

int	w(int a, int b, int c)
{
	int dp[51][51][51];

	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			for (int k = 0; k < 51; k++)
				dp[i][j][k] = 1;
		}
	}

	if (a > 20 || b > 20 || c > 20)
	{
		a = 20;
		b = 20;
		c = 20;
	}

	if (a < b && b < c)
	{
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				for (int k = 1; k <= c; k++)
					dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
			}
		}
	}
	else
	{
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				for (int k = 1; k <= c; k++)
					dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
			}
		}
	}
	return (dp[a][b][c]);
}

	
int	main(void)
{
	int	a, b, c;
	
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
	
		if (a == -1 && b == -1 && c == -1)
			return (0);
		else if (a <= 0 || b <= 0 || c <= 0)
			printf("w(%d, %d, %d) = 1\n", a, b, c);
		else
			printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	return (0);
}
