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

	int	seq[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);

	int	dp[n], dst;
	dp[0] = seq[0];
	dst = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i-1] + seq[i], seq[i]);
		if (dst < dp[i])
			dst = dp[i];
	}
	
	printf("%d", dst);
	return (0);
}
