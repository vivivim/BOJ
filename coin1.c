#include <stdio.h>

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);

	int	coin[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	int	dp[k], tmp;
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			tmp = j * coin[0];
			if (tmp == i+1)
				dp[i] = 1;
			else
				dp[i] = 0;
			if (tmp >= i+1)
				break ;
		}
	}

	for (int j = 1; j < n; j++)
	{
		if (coin[j] <= k)
		{
			for (int i = 0; i < coin[j]; i++)
			{
				if (i == coin[j]-1)
					dp[i]++;
			}
			for (int i = coin[j]-1; i < k; i++)
				dp[i] += dp[i-coin[j]];
		}
	}
	printf("%d", dp[k-1]);
	return (0);
}
