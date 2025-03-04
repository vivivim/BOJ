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

	int	score[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &score[i]);
	
	int	dp[n];

	dp[0] = score[0];
	if (n == 1)
	{
		printf("%d", dp[0]);
		return (0);
	}

	dp[1] = score[1] + dp[0];
	dp[2] = max(score[2]+score[0], score[1]+score[2]);
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
	}
	printf("%d", dp[n-1]);
	return (0);
}
