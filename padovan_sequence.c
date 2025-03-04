#include <stdio.h>

int	main(void)
{
	int	t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int	n;
		scanf("%d", &n);
		
		long long	dp[n];
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 1;
		for (int j = 3; j < n; j++)
			dp[j] = dp[j-2] + dp[j-3];
		printf("%lld\n", dp[n-1]);
	}
	return (0);
}
