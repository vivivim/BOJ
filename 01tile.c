#include <stdio.h>

int	main(void)
{
	int n;
	scanf("%d", &n);

	long long	dp[n];
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < n; i++)
		dp[i] = (dp[i-1] + dp[i-2]) % 15746;
	printf("%lld", dp[n-1]);
	return (0);
}
