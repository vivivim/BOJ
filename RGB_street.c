#include <stdio.h>

int	ft_min(int a, int b, int c)
{
	int	min;
	min = a < b ? a : b;
	min = min < c ? min : c;
	return (min);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	gold[n][3], dp[n][3];
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &gold[i][0], &gold[i][1], &gold[i][2]);
	dp[0][0] = gold[0][0];
	dp[0][1] = gold[0][1];
	dp[0][2] = gold[0][2];
	
	int	i = 1;
	while (i < n)
	{
		dp[i][0] = gold[i][0] + (dp[i-1][1] < dp[i-1][2] ? dp[i-1][1] : dp[i-1][2]);
		dp[i][1] = gold[i][1] + (dp[i-1][0] < dp[i-1][2] ? dp[i-1][0] : dp[i-1][2]);
		dp[i][2] = gold[i][2] + (dp[i-1][0] < dp[i-1][1] ? dp[i-1][0] : dp[i-1][1]);
		i++;
	}
	printf("%d", ft_min(dp[n-1][0], dp[n-1][1], dp[n-1][2]));
}
