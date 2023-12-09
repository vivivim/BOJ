#include <stdio.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return(b);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	wine[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &wine[i]);
	if (n == 1)
		printf("%d", wine[0]);
	else if (n == 2)
		printf("%d", wine[0]+wine[1]);
	else if (n == 3)
	{
		int	dst;
		if (wine[0] > wine[1])
		{
			dst = wine[0];
			if (wine[1] > wine[2])
				dst += wine[1];
			else
				dst += wine[2];
		}
		else
		{
			dst = wine[1];
			if (wine[0] > wine[2])
				dst += wine[0];
			else
				dst += wine[2];
		}
		printf("%d", dst);
	}
	if (n <= 3)
		return (0);

	int	dp[n];

	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	dp[2] = max(dp[1], wine[2]+max(wine[0], wine[1]));
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]);
		dp[i] = max(dp[i-3] + wine[i], dp[i]);
		dp[i] = max(dp[i-1], dp[i]);
	}

	printf("%d", dp[n-1]);
	return (0);
}
