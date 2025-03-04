#include <stdio.h>

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);

	int	w[n], v[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &w[i], &v[i]);

	int	dp[k+1];
	for (int i = 0; i <= k; i++)
		dp[i] = 0;
	
	for (int j = 0; j < n; j++)
	{
		for (int i = k; i >= 1; i--)
		{
			if (i >= w[j])
				dp[i] = (dp[i] < (dp[i-w[j]] + v[j]) ? (dp[i-w[j]] + v[j]) : dp[i]);
		}
	}
	printf("%d", dp[k]);
	return (0);
}
