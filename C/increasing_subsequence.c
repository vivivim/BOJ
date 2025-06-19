#include <stdio.h>

int	ft_max(int dp[], int n)
{
	int	max = -2147483648;

	while (n--)
	{
		if (max < dp[n])
			max = dp[n];
	}
	return (max);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int	dp[n], temp = 0;

	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		temp = 0;
		for (int j = i-1; j >= 0; j--)
		{
			if (a[j] < a[i] && temp < dp[j])
			{
				dp[i] = dp[j] + 1;
				temp = dp[j];
			}
		}
	}
	printf("%d", ft_max(dp, n));
}
