#include <stdio.h>

int	max(int dp[100])
{
	int	dst = -2147483648;

	for (int i = 0; i < 500; i++)
	{
		if (dp[i] > dst)
			dst = dp[i];
	}
	return (dst);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	a_b[500] = {0,}, a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		scanf("%d", &a_b[a]);
	}

	int dp[500], temp = 0;
	dp[0] = 1;
	for (int i = 1; i < 500; i++)
	{
		dp[i] = 1;
		temp = 0;
		for (int j = i-1; j >= 0; j--)
		{
			if (a_b[i] > 0 && a_b[j] && a_b[j] < a_b[i] && temp < dp[j])
			{
				dp[i] = dp[j] + 1;
				temp = dp[j];
			}
		}
	}
	printf("%d", n - max(dp));
	return (0);
}
