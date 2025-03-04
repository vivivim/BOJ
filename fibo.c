#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	dp[45];
	dp[0] = 0;
	dp[1] = 1;
	
	int	i = 1;
	if (n > 1)
	{
		while (++i <= n)
			dp[i] = dp[i-1] + dp[i-2];
	}
	printf("%d", dp[n]);
	return (0);
}
